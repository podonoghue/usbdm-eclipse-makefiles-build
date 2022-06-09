/*! @file HexToC.c
 *
 *  A program to patch multiple XML files.  A backup is made of original file.
 *
 *  Usage: mergeFiles directoryPathMask filenameMask [mergeFile]
 *    @param directoryPathMask : path to directory, may include wild-cards in last element
 *    @param filenameMask      : name of file(s), may include wild-cards
 *    @param mergeFile         : file containing XML to merge
 *                       If no mergeFile is specified then a restoration is attempted
 *
 *  Created on: 27/07/2008
 *      Author: PODonoghue
 */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/dir.h>
#include <wx/ffile.h>
#include <wx/textfile.h>
#include <wx/app.h>
#include <wx/cmdline.h>
#include <wx/filefn.h>
#include <iostream>
using namespace std;

#include "xmlParser.h"

class MyTraverser : public wxDirTraverser {
public:
   MyTraverser() : rc(0) {
   }
   virtual wxDirTraverseResult OnDir(const wxString& ) = 0;
   virtual wxDirTraverseResult OnFile(const wxString& originalFilepath) = 0;
   int getRc() const { return rc; }

protected:
   int rc;
};

class ConvertTraverser : public MyTraverser {
private:
    const wxString mergePath;

public:
    /**
     * @param mergePath  Path to file containing info on how to modify XML files
     */
   ConvertTraverser(const char *mergePath) : mergePath(strdup(mergePath), wxConvUTF8) {
   }

   virtual ~ConvertTraverser() {
   }

   virtual wxDirTraverseResult OnFile(const wxString& originalFilepath) {
      if(!wxFileExists(mergePath)) {
         cerr << "Error: Merge file '" << mergePath << "' doesn't exist\n";
         rc = -1;
         return wxDIR_STOP;
      }
      if(!wxFileExists(originalFilepath)) {
         cerr << "Error: Original file '" << originalFilepath << "' doesn't exist\n";
         rc = -1;
         return wxDIR_STOP;
      }
      rc = XmlParser::addUsbdmWizard(originalFilepath, mergePath);
      if(rc != 0) {
         cerr << "Error: Failed to do conversion '" << originalFilepath << "' unchanged\n";
         return wxDIR_STOP;
      }
      return wxDIR_CONTINUE;
   }

    virtual wxDirTraverseResult OnDir(const wxString& )
    {
        return wxDIR_CONTINUE;
    }
};

class RestoreTraverser : public MyTraverser
{
public:
   RestoreTraverser() {
   }

   //! @param filepath - path to file, either original or backup
   //!
   virtual wxDirTraverseResult OnFile(const wxString& filepath) {
      wxString destinationFilepath;
      wxString sourceFilepath;

      // Check if the filename finishes with ".original"
      // If so it's the backup else the original to restore
      if (filepath.EndsWith(_(".original"), &destinationFilepath)) {
         sourceFilepath = filepath;
      }
      else {
         destinationFilepath = filepath;
         sourceFilepath      = filepath+_(".original");
      }
      cerr << "Info: Restoring \n"
           << " => " << destinationFilepath.ToAscii() <<"\n"
           << " <= " << sourceFilepath.ToAscii() << "\n";

      if (!wxFileExists(sourceFilepath)) {
         cerr << "Warning: No backup exists - skipping restoration\n";
         return wxDIR_CONTINUE;
      }
      if (!wxRenameFile(sourceFilepath, destinationFilepath, true)) {
         cerr << "Error: Failed to restore" << destinationFilepath.ToAscii() << "\n";
         return wxDIR_STOP;
      }
      cerr << "Done\n";
      return wxDIR_CONTINUE;
   }
   virtual wxDirTraverseResult OnDir(const wxString& WXUNUSED(dirname)) {
      return wxDIR_CONTINUE;
   }
};

/*!   Converts multiple files
 *
 *    @param dirPath    - path to directory
 *
 *    @param filename   - name of file, may include wild-cards
 */
int convertDirectory(const wxString &dirPath, const wxString &filename, MyTraverser &converter ) {
   wxDir directory(dirPath);

   fprintf(stdout, "------------------------------------------------------------------\n");
   fprintf(stdout, "   convertDirectory(): \n"
                   "      dirPath = \'%s\'\n"
                   "      filename = \'%s\'\n",
                   (const char *)dirPath.ToAscii(),
                   (const char *)filename.ToAscii() );
//   printf("Processing Pattern %s\n", (const char *)dirPath.ToAscii());
   directory.Traverse(converter, filename, wxDIR_FILES);
   fprintf(stdout, "------------------------------------------------------------------\n");
   return converter.getRc();
}

/*!   Converts multiple directories/files matching given patterns
 *
 *    @param directoryPath - path to directory, may include wild-cards in last element
 *
 *    @param filename      - names of files separated by '|', may include wild-cards
 */
int modifyFiles(const char *directoryPath, const char *filename, MyTraverser &converter) {

   char buff[100];
   strncpy(buff, filename, sizeof(buff)-1);
   char *filePattern = strtok(buff, "|\n");
   if (filePattern == nullptr){
      fprintf(stderr, "Missing pattern\n");
      exit(-1);
   }
   fprintf(stdout, "modifyFiles(): \n"
                   "   inputFilenameMask = \'%s\'\n"
                   "   filename= \'%s\'\n",
         directoryPath,
         filename);
   do {
      wxString f = wxFindFirstFile(wxString(directoryPath, wxConvUTF8), wxDIR);
      while (!f.empty()) {
         int rc = convertDirectory(f, wxString(filePattern, wxConvUTF8), converter);
         if (rc != 0)
            return rc;
         f = wxFindNextFile();
      }
      filePattern = strtok(0, "|\n");
   } while (filePattern != 0);
   return 0;
}

bool doPause = false;

static void waitForKeypress(void) {
   if (doPause) {
      fprintf(stdout, "=========================\n"
                      "Press Enter to close...\n"
                      "=========================\n");
      getchar();
   }
}

void usage(void) {
   fprintf(stderr,
         "Usage: mergeFiles [options] directoryPathMask filenameMask [mergeFile]\n"
         "If no mergeFile is specified then a restoration is attempted\n"
         "options = -p - pause before exit\n\n");
}

/**
 *  Strips trailing \ (unless root e.g. "c:\")
 *
 * @param filePath Path to process
 */
void fixPath(char *filePath) {
   int length = strlen(filePath);
   if ((length > 2) && (filePath[length-1] == '\\') && (filePath[length-2] != ':')) {
      filePath[length-1] = '\0';
   }
}

//void doCommandFile(const char *scriptFile) {
//   cerr << "Reading from script file '" << scriptFile << "\n";
//   FILE *fp = fopen(scriptFile, "rt");
//   if (fp == 0) {
//      fprintf(stderr, "Failed to open %s\n", scriptFile);
//      exit(-1);
//   }
//   char buff[100];
//   while (fgets(buff, sizeof(buff), fp) != 0) {
//      const char *f1 = strtok(buff, ", \t\n");
//      const char *f2 = strtok(0, ", \t\n");
//      const char *f3 = strtok(0, ", \t\n");
//      if ((f1 == 0) && (f2 == 0) && (f3 == 0)) {
//         continue;
//      }
//      if ((f1 == 0) || (f2 == 0) || (f3 == 0)) {
//         fprintf(stderr, "Illegal/missing args f1=%s, f2=%s, f3=%s\n", f1, f2, f3);
//         exit(-1);
//      }
//      fprintf(stderr, "Processing args f1=%s, f2=%s, f3=%s\n", f1, f2, f3);
//   }
//   waitForKeypress();
//}

int main(int  argc, char *argv[]){
   int fileArg = 1;
   if ((argc >= 2) && (strcasecmp(argv[1], "-p")==0)) {
      fileArg++;
      doPause = true;
   }
//   if ((strcasecmp(argv[fileArg], "-f")==0)) {
//      doCommandFile(argv[fileArg+1]);
//      return 0;
//   }
   if (argc < fileArg+2) {
      fprintf(stderr, "Arguments(s) missing\n");
      usage();
      return 1;
   }
   // Strip trailing \ (unless root e.g. "c:\")
   fixPath(argv[fileArg]);
   if (argc == (fileArg+3)) {
      string mergeFile = argv[fileArg+2];
      if(!wxFileExists(mergeFile.c_str())) {
         // Prepend default directory
         mergeFile = "CW_Patches\\Data\\" + mergeFile;
      }
      wxGetCwd();
      fprintf(stdout, "==================================================================\n");
      fprintf(stdout, "directoryPathMask = \'%s\'\n", argv[fileArg]);
      fprintf(stdout, "filenameMask      = \'%s\'\n", argv[fileArg+1]);
      fprintf(stdout, "mergeFile         = \'%s\'\n", mergeFile.c_str());
      fprintf(stdout, "cwd               = \'%s\'\n", (const char*)(wxGetCwd().ToAscii()));
      fprintf(stdout, "==================================================================\n");
      ConvertTraverser traverser(mergeFile.c_str());
      int rc = modifyFiles(argv[fileArg], argv[fileArg+1], traverser);
      waitForKeypress();
      return rc;
   }
   else {
      fprintf(stdout, "==================================================================\n");
      fprintf(stdout, "directoryPathMask = \'%s\'\n", argv[fileArg]);
      fprintf(stdout, "filenameMask      = \'%s\'\n", argv[fileArg+1]);
      fprintf(stdout, "cwd               = \'%s\'\n", (const char*)(wxGetCwd().ToAscii()));
      fprintf(stdout, "==================================================================\n");
      RestoreTraverser traverser;
      int rc = modifyFiles(argv[fileArg], argv[fileArg+1], traverser);
      waitForKeypress();
      return rc;
   }
   return 0;
}


