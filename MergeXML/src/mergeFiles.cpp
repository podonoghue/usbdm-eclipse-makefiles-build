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
 *    @param inputFilenameMask - path to directory, may include wild-cards in last element
 *
 *    @param filename          - name of file, may include wild-cards
 */
int convertPattern(const char *inputFilenameMask, const char *filename, MyTraverser &converter) {

   fprintf(stdout, "convertPattern(): \n"
                   "   inputFilenameMask = \'%s\'\n"
                   "   filename= \'%s\'\n",
         inputFilenameMask,
         filename);
   wxString f = wxFindFirstFile(wxString(inputFilenameMask, wxConvUTF8), wxDIR);
   while (!f.empty()) {
      int rc = convertDirectory(f, wxString(filename, wxConvUTF8), converter);
      if (rc != 0)
         return rc;
      f = wxFindNextFile();
   }
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

int main(int  argc, char *argv[]){
   int fileArg = 1;
   if ((argc >= 2) && (strcasecmp(argv[1], "-p")==0)) {
      fileArg++;
      doPause = true;
   }
   if (argc < fileArg+2) {
      fprintf(stderr, "Arguments(s) missing\n");
      usage();
      return 1;
   }
   // Strip trailing \ (unless root e.g. "c:\")
   int length = strlen(argv[fileArg]);
   if ((length > 2) && (argv[fileArg][length-1] == '\\') && (argv[fileArg][length-2] != ':')) {
      argv[fileArg][length-1] = '\0';
   }
   if (argc == (fileArg+3)) {
      fprintf(stdout, "==================================================================\n");
      fprintf(stdout, "directoryPathMask = \'%s\'\n", argv[fileArg]);
      fprintf(stdout, "filenameMask = \'%s\'\n",      argv[fileArg+1]);
      fprintf(stdout, "mergeFile = \'%s\'\n",         argv[fileArg+2]);
      fprintf(stdout, "==================================================================\n");
      ConvertTraverser traverser(argv[fileArg+2]);
      int rc = convertPattern(argv[fileArg], argv[fileArg+1], traverser);
      waitForKeypress();
      return rc;
   }
   else {
      fprintf(stdout, "==================================================================\n");
      fprintf(stdout, "directoryPathMask = \'%s\'\n", argv[fileArg]);
      fprintf(stdout, "filenameMask = \'%s\'\n",      argv[fileArg+1]);
      fprintf(stdout, "==================================================================\n");
      RestoreTraverser traverser;
      int rc = convertPattern(argv[fileArg], argv[fileArg+1], traverser);
      waitForKeypress();
      return rc;
   }
   return 0;
}


