#include <windows.h>
#ifndef __reserved // Used in msi.h
#define __reserved
#endif
#include <msi.h>
#include <msiquery.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdarg.h>

static MSIHANDLE hInstall = 0;

static void printLog(const char *format, ...) {
   UINT er;
   char buff[1000];
   va_list list;

   if (hInstall == 0)
      return;
   va_start(list, format);
   vsprintf(buff, format, list);
   va_end(list);

   PMSIHANDLE hRecord = ::MsiCreateRecord(1);
   if (hRecord) {
       er = ::MsiRecordSetString(hRecord, 0, TEXT(buff));
       if (er == ERROR_SUCCESS) {
           er = ::MsiProcessMessage(hInstall, INSTALLMESSAGE_INFO, hRecord);
       }
   }
}

#if 0
static bool fileExists(const char *path) {
   struct stat stFileInfo;
   int intStat;
   bool found;

   intStat = stat(path, &stFileInfo);
   found = ((intStat == 0) && S_ISREG(stFileInfo.st_mode));

   printLog("fileExists(%s) => %s\n", path, found?"Found":"Not Found");
   return found;
}
#endif

static bool directoryExists(char *path) {
   struct stat stFileInfo;
   int intStat;
   bool found;

   intStat = stat(path, &stFileInfo);
   found = ((intStat == 0) && S_ISDIR(stFileInfo.st_mode));

   printLog("dirExists(%s) => %s\n", path, found?"Found":"Not Found");
   return found;
}

typedef struct  {
   const char *directory;    // Property containing the Feature install path
   const char *feature;      // Feature
   const char *subdir;       // Sub-directory to probe for
   const char *description;  // Description of feature to set for error message
} DirectoryQuad;

//! Check if feature paths are valid
//!
extern "C" UINT __stdcall CheckInstallPaths(MSIHANDLE hInstall) {
   bool found = true;
   char path[MAX_PATH];
   DWORD filePathLength;
   DirectoryQuad pathsToCheck[] = {
         // directory                         feature                            subdir               description
         {"D.CW_FOR_MCU_V10_7",              "F.CW_FOR_MCU_V10_7",              "MCU",               "Codewarrior Interfaces\n     - MCU V10.7"},
         {"D.CW_FOR_MCU_V10_6",              "F.CW_FOR_MCU_V10_6",              "MCU",               "Codewarrior Interfaces\n     - MCU V10.6"},
         {"D.CW_FOR_MCU_V10_5",              "F.CW_FOR_MCU_V10_5",              "MCU",               "Codewarrior Interfaces\n     - MCU V10.5"},
         {"D.CW_FOR_MCU_V10_4",              "F.CW_FOR_MCU_V10_4",              "MCU",               "Codewarrior Interfaces\n     - MCU V10.4"},
         {"D.CW_FOR_MCU_V10_3",              "F.CW_FOR_MCU_V10_3",              "MCU",               "Codewarrior Interfaces\n     - MCU V10.3"},
         {"D.CW_FOR_MCU_V10_2",              "F.CW_FOR_MCU_V10_2",              "MCU",               "Codewarrior Interfaces\n     - MCU V10.2"},
         {"D.CW_FOR_MCU_V10_1",              "F.CW_FOR_MCU_V10_1",              "MCU",               "Codewarrior Interfaces\n     - MCU V10.1"},
         {"D.CODEWARRIOR_COLDFIRE_V7_2",     "F.CODEWARRIOR_COLDFIRE_V7_2",     "bin",               "Codewarrior Interfaces\n     - Coldfire V7.2"},
         {"D.CODEWARRIOR_COLDFIRE_V7_1",     "F.CODEWARRIOR_COLDFIRE_V7_1",     "bin",               "Codewarrior Interfaces\n     - Coldfire V7.1"},
         {"D.CODEWARRIOR_COLDFIRE_V7",       "F.CODEWARRIOR_COLDFIRE_V7",       "bin",               "Codewarrior Interfaces\n     - Coldfire V7.x"},
         {"D.CODEWARRIOR_DSC_V8_3",          "F.CODEWARRIOR_DSC_V8_3",          "bin",               "Codewarrior Interfaces\n     - DSC56800E B8,3"},
         {"D.CW_FOR_MICROCONTROLLERS_V6_3",  "F.CW_FOR_MICROCONTROLLERS_V6_3",  "bin",               "Codewarrior Interfaces\n     - Microcontrollers V6.3"},
         {"D.CW_FOR_MICROCONTROLLERS_V6_2",  "F.CW_FOR_MICROCONTROLLERS_V6_2",  "bin",               "Codewarrior Interfaces\n     - Microcontrollers V6.2"},
         {"D.CW_FOR_MICROCONTROLLERS_V6",    "F.CW_FOR_MICROCONTROLLERS_V6",    "bin",               "Codewarrior Interfaces\n     - Microcontrollers V6.x"},
         {"D.CWS12_X_V5_1",                  "F.CWS12_X_V5_1",                  "bin",               "Codewarrior Interfaces\n     - S12(X) V5.1"},
         {"D.FREEMASTER_V1_3",               "F.FREEMASTER_V1_3",               "plugins",           "FreeMASTER V1.3"},
         {"D.CFFLASHER_V3_1",                "F.CFFLASHER_V3_1",                "BDM Protocol",      "CF Flasher V3.1"},
         {"D.CODESOURCERY_CF",               "F.CODESOURCERY_CF",               "bin",               "Sourcery Interfaces\n        - Codebench Lite for Coldfire ELF"},
         {"D.CODESOURCERY_KINETIS",          "F.CODESOURCERY_KINETIS",          "bin",               "Sourcery Interfaces\n        - Codebench Lite for Kinetis EABI"},
         {"D.CODESOURCERY_ARM",              "F.CODESOURCERY_ARM",              "bin",               "Sourcery Interfaces\n        - Codebench Lite for ARM EABI"},
         {"D.ECLIPSE_CDT",                   "F.ECLIPSE_CDT",                   "dropins",           "Eclipse CDT Interfaces\n     - Eclipse Plugin"},
         {"D.ECLIPSE_JUNO_CDT",              "F.ECLIPSE_JUNO_CDT",              "dropins",           "Eclipse JUNO Interfaces\n    - Eclipse Plugin"},
         {"D.ECLIPSE_KEPLER_CDT",            "F.ECLIPSE_KEPLER_CDT",            "dropins",           "Eclipse KEPLER Interfaces\n  - Eclipse Plugin"},
         {"D.ECLIPSE_LUNA_CDT",              "F.ECLIPSE_LUNA_CDT",              "dropins",           "Eclipse LUNA Interfaces\n    - Eclipse Plugin"},
         {"D.KINETIS_DESIGN_STUDIO",         "F.KINETIS_DESIGN_STUDIO",         "eclipse/dropins",   "Freescale Design Studio"},
         {NULL,                              NULL,                              NULL,                NULL}
   };
   ::hInstall = hInstall;
   printLog("CheckInstallPaths()\n");

   int pathNum;
   for (pathNum=0; pathsToCheck[pathNum].directory != NULL; pathNum++) {
      UINT rc;
      filePathLength = MAX_PATH;
      INSTALLSTATE installedState;
      INSTALLSTATE actionState;

      // Check if feature is being installed - otherwise no path check needed
      rc = MsiGetFeatureState(hInstall,pathsToCheck[pathNum].feature, &installedState, &actionState);
      if (actionState != INSTALLSTATE_LOCAL) {
         printLog("CheckInstallPaths() Feature = \'%s\' not being installed - no action\n", pathsToCheck[pathNum].feature);
         continue;
      }
      // Check if path exists
      found = false;
      // Get path & validate
      rc = MsiGetTargetPath(hInstall, pathsToCheck[pathNum].directory, path, &filePathLength);
      if (rc == ERROR_SUCCESS) {
         strcat(path, pathsToCheck[pathNum].subdir);
         found = directoryExists(path);
      }
      printLog("CheckInstallPaths(%s) => %s\n", path, found?"Found":"Not Found");
      if (!found) {
         MsiSetProperty (hInstall, "CODEWARRIOR_MISSING_PATH", path);
         MsiSetProperty (hInstall, "CODEWARRIOR_MISSING_APP",  pathsToCheck[pathNum].description);
         break;
      }
   }
   UINT rc = MsiSetProperty(hInstall, "CODEWARRIOR_PATHS_EXIST", found?"1":"0");
   return rc;
}

#if 0
extern "C" UINT __stdcall FileExists(MSIHANDLE hInstall) {
   bool found;
   char path[MAX_PATH];
   DWORD filePathLength = MAX_PATH;

   ::hInstall = hInstall;

   MsiGetProperty (hInstall, "MYCA_PATH", path, &filePathLength);

   found = fileExists(path);
   MsiSetProperty (hInstall, "MYCA_EXISTS", found?"1":"0");

   printLog("FileExists(%s) => %s\n", path, found?"Found":"Not Found");
   return ERROR_SUCCESS;
}

extern "C" UINT __stdcall  DirectoryExists(MSIHANDLE hInstall) {
   bool found;

   ::hInstall = hInstall;

   char path[MAX_PATH];
   DWORD filePathLength = MAX_PATH;

   MsiGetProperty (hInstall, "MYCA_PATH", path, &filePathLength);

   // Attempt to get the subdir attributes
   found = directoryExists(path);
   MsiSetProperty (hInstall, "MYCA_EXISTS", found?"1":"0");

   printLog("DirectoryExists(%s) => %s\n", path, found?"Found":"Not Found");
   return ERROR_SUCCESS;
}
#endif

#if 0
static void tests(void) {
   const char *ids[] = {
      "D.EclipsePlugins",
      "F.ECLIPSE_JUNO_CDT",
      "F.ECLIPSE_KEPLER_CDT",
      "F.ECLIPSE_LUNA_CDT",
      "D.Eclipse_JUNO_Dropins",
      "D.Eclipse_KEPLER_Dropins",
      "D.Eclipse_LUNA_Dropins",
   };
   unsigned rc;

   unsigned long pathLength;
   for(unsigned sub=0; sub<(sizeof(ids)/sizeof(ids[0])); sub++) {
      // Get Eclipse install plugin path
      char path[MAX_PATH];
      pathLength = MAX_PATH;
      rc = MsiGetProperty(hInstall, ids[sub], path, &pathLength);
      if (rc != ERROR_SUCCESS) {
         printLog("WriteLinkFile() MsiGetProperty(%s) => FAILED", ids[sub]);
      }
      else {
         printLog("WriteLinkFile() MsiGetProperty(%s) => \'%s\'", ids[sub], path);
      }
      pathLength = MAX_PATH;
      rc = MsiGetTargetPath(hInstall, ids[sub], path, &pathLength);
      if (rc != ERROR_SUCCESS) {
         printLog("WriteLinkFile() MsiGetTargetPath(%s) => FAILED", ids[sub]);
      }
      else {
         printLog("WriteLinkFile() MsiGetTargetPath(%s) => \'%s\'", ids[sub], path);
      }
   }
}
#endif

struct PluginInformation {
   const char *feature;
   const char *dropinPath;
};

static const PluginInformation pluginInformation[] = {
   {"F.ECLIPSE_JUNO_CDT",        "D.Eclipse_JUNO_Dropins"},
   {"F.ECLIPSE_KEPLER_CDT",      "D.Eclipse_KEPLER_Dropins"},
   {"F.ECLIPSE_LUNA_CDT",        "D.Eclipse_LUNA_Dropins"},
   {"F.ECLIPSE_MARS_CDT",        "D.Eclipse_MARS_Dropins"},
   {"F.KINETIS_DESIGN_STUDIO",   "D.KDSDropins"},
};

//! Write Eclipse plugin paths to files
//!
static UINT WriteEclipseLinkFiles(MSIHANDLE hInstall) {
   ::hInstall = hInstall;
   printLog("WriteLinkFile()");

//   tests();

   unsigned rc;

   static const char *PLUGIN_ID = "D.EclipsePlugins";

   // Get path to shared USBDM Eclipse plugins
   unsigned long pathLength = MAX_PATH;
   char usbdmPluginsPath[MAX_PATH];
   rc = MsiGetTargetPath(hInstall, PLUGIN_ID, usbdmPluginsPath, &pathLength);
   if (rc != ERROR_SUCCESS) {
      printLog("WriteLinkFile() MsiGetTargetPath(%s) => FAILED", PLUGIN_ID);
      return rc;
   }
   printLog("WriteLinkFile() MsiGetTargetPath(%s) => \'%s\'", PLUGIN_ID, usbdmPluginsPath);
   // Create entry for link file
   char linkFileContents[MAX_PATH+20];
   sprintf(linkFileContents, "path=%susbdm", usbdmPluginsPath);
   for( char *s=linkFileContents; *s!= '\0'; s++) {
      if (*s == '\\') {
         *s = '/';
      }
   }
   for (unsigned sub=0; sub<(sizeof(pluginInformation)/sizeof(pluginInformation[0])); sub++) {
      // Check if feature is being installed - otherwise no action needed
      INSTALLSTATE installedState;
      INSTALLSTATE actionState;
      rc = MsiGetFeatureState(hInstall, pluginInformation[sub].feature, &installedState, &actionState);
      if (actionState != INSTALLSTATE_LOCAL) {
         printLog("WriteLinkFile() Feature = \'%s\' not being installed - no action", pluginInformation[sub].feature);
         continue;
      }
      // Get Eclipse install plugin path
      unsigned long pathLength = MAX_PATH;
      char path[MAX_PATH];
      rc = MsiGetTargetPath(hInstall, pluginInformation[sub].dropinPath, path, &pathLength);
      if (rc != ERROR_SUCCESS) {
         printLog("WriteLinkFile() MsiGetProperty(%s) => FAILED", pluginInformation[sub].dropinPath);
         return rc;
      }
      printLog("WriteLinkFile() MsiGetProperty(%s) => \'%s\'", pluginInformation[sub].dropinPath, path);
      strcat(path, "/usbdm.link");
      FILE *fp = fopen(path, "w");
      fputs(linkFileContents, fp);
      fclose(fp);
   }
   return 0;
}

//! Write Eclipse plugin paths to files
//!
static UINT RemoveEclipseLinkFiles(MSIHANDLE hInstall) {
   ::hInstall = hInstall;
   printLog("RemoveEclipseLinkFiles()");

   unsigned rc;

   for (unsigned sub=0; sub<(sizeof(pluginInformation)/sizeof(pluginInformation[0])); sub++) {
      // Check if feature is being uninstalled - otherwise no action needed
      INSTALLSTATE installedState;
      INSTALLSTATE actionState;
      rc = MsiGetFeatureState(hInstall, pluginInformation[sub].feature, &installedState, &actionState);
      printLog("RemoveEclipseLinkFiles() Feature = \'%s\' actionState = %d", pluginInformation[sub].feature, actionState);
      if (actionState != INSTALLSTATE_ABSENT) {
         printLog("RemoveEclipseLinkFiles() Feature = \'%s\' not being removed - no action", pluginInformation[sub].feature);
         continue;
      }
      // Get Eclipse install plugin path
      unsigned long pathLength = MAX_PATH;
      char path[MAX_PATH];
      rc = MsiGetTargetPath(hInstall, pluginInformation[sub].dropinPath, path, &pathLength);
      if (rc != ERROR_SUCCESS) {
         printLog("RemoveEclipseLinkFiles() MsiGetProperty(%s) => FAILED", pluginInformation[sub].dropinPath);
         return rc;
      }
      printLog("RemoveEclipseLinkFiles() MsiGetProperty(%s) => \'%s\'", pluginInformation[sub].dropinPath, path);
      strcat(path, "/usbdm.link");
      remove(path);
   }
   return 0;
}

static const PluginInformation cwPluginInformation[] = {
   {"F.CW_FOR_MCU_V10.3",   "D.CW_V10.3_EclipseDropins"},
   {"F.CW_FOR_MCU_V10.4",   "D.CW_V10.4_EclipseDropins"},
   {"F.CW_FOR_MCU_V10.5",   "D.CW_V10.5_EclipseDropins"},
   {"F.CW_FOR_MCU_V10.6",   "D.CW_V10.6_EclipseDropins"},
   {"F.CW_FOR_MCU_V10.7",   "D.CW_V10.7_EclipseDropins"},
   {"F.CW_FOR_MCU_V10.8",   "D.CW_V10.8_EclipseDropins"},
};

//! Write Eclipse plugin paths to files
//!
static UINT WriteCodewarriorLinkFiles(MSIHANDLE hInstall) {
   ::hInstall = hInstall;
   printLog("WriteCodewarriorLinkFiles()");

//   tests();

   unsigned rc;

   static const char *PLUGIN_ID = "D.CWEclipsePlugins";

   // Get path to shared USBDM Eclipse plugins
   unsigned long pathLength = MAX_PATH;
   char usbdmPluginsPath[MAX_PATH];
   rc = MsiGetTargetPath(hInstall, PLUGIN_ID, usbdmPluginsPath, &pathLength);
   if (rc != ERROR_SUCCESS) {
      printLog("WriteCodewarriorLinkFiles() MsiGetTargetPath(%s) => FAILED", PLUGIN_ID);
      return rc;
   }
   printLog("WriteCodewarriorLinkFiles() MsiGetTargetPath(%s) => \'%s\'", PLUGIN_ID, usbdmPluginsPath);
   // Create entry for link file
   char linkFileContents[MAX_PATH+20];
   sprintf(linkFileContents, "path=%susbdm", usbdmPluginsPath);
   for( char *s=linkFileContents; *s!= '\0'; s++) {
      if (*s == '\\') {
         *s = '/';
      }
   }
   for (unsigned sub=0; sub<(sizeof(cwPluginInformation)/sizeof(cwPluginInformation[0])); sub++) {
      // Check if feature is being installed - otherwise no action needed
      INSTALLSTATE installedState;
      INSTALLSTATE actionState;
      rc = MsiGetFeatureState(hInstall, cwPluginInformation[sub].feature, &installedState, &actionState);
      if (actionState != INSTALLSTATE_LOCAL) {
         printLog("WriteCodewarriorLinkFiles() Feature = \'%s\' not being installed - no action", cwPluginInformation[sub].feature);
         continue;
      }
      // Get Eclipse install plugin path
      unsigned long pathLength = MAX_PATH;
      char path[MAX_PATH];
      rc = MsiGetTargetPath(hInstall, cwPluginInformation[sub].dropinPath, path, &pathLength);
      if (rc != ERROR_SUCCESS) {
         printLog("WriteCodewarriorLinkFiles() MsiGetProperty(%s) => FAILED", cwPluginInformation[sub].dropinPath);
         return rc;
      }
      printLog("WriteCodewarriorLinkFiles() MsiGetProperty(%s) => \'%s\'", cwPluginInformation[sub].dropinPath, path);
      strcat(path, "/usbdm.link");
      FILE *fp = fopen(path, "w");
      fputs(linkFileContents, fp);
      fclose(fp);
   }
   return 0;
}

//! Write Eclipse plugin paths to files
//!
static UINT RemoveCodewarriorLinkFiles(MSIHANDLE hInstall) {
   ::hInstall = hInstall;
   printLog("RemoveCodewarriorLinkFiles()");

   unsigned rc;

   for (unsigned sub=0; sub<(sizeof(cwPluginInformation)/sizeof(cwPluginInformation[0])); sub++) {
      // Check if feature is being installed - otherwise no action needed
      INSTALLSTATE installedState;
      INSTALLSTATE actionState;
      rc = MsiGetFeatureState(hInstall, cwPluginInformation[sub].feature, &installedState, &actionState);
      printLog("RemoveCodewarriorLinkFiles() Feature = \'%s\' actionState = %d", cwPluginInformation[sub].feature, actionState);
      if (actionState != INSTALLSTATE_ABSENT) {
         printLog("RemoveCodewarriorLinkFiles() Feature = \'%s\' not being removed - no action", cwPluginInformation[sub].feature);
         continue;
      }
      // Get Eclipse install plugin path
      unsigned long pathLength = MAX_PATH;
      char path[MAX_PATH];
      rc = MsiGetTargetPath(hInstall, cwPluginInformation[sub].dropinPath, path, &pathLength);
      if (rc != ERROR_SUCCESS) {
         printLog("RemoveCodewarriorLinkFiles() MsiGetProperty(%s) => FAILED", cwPluginInformation[sub].dropinPath);
         return rc;
      }
      printLog("RemoveCodewarriorLinkFiles() MsiGetProperty(%s) => \'%s\'", cwPluginInformation[sub].dropinPath, path);
      strcat(path, "/usbdm.link");
      remove(path);
   }
   return 0;
}

extern "C" UINT __stdcall WriteLinkFiles(MSIHANDLE hInstall) {
   unsigned rc;
   rc = WriteEclipseLinkFiles(hInstall);
   if (rc != ERROR_SUCCESS) {
      return rc;
   }
   rc = WriteCodewarriorLinkFiles(hInstall);
   return rc;
}

extern "C" UINT __stdcall RemoveLinkFiles(MSIHANDLE hInstall) {
   unsigned rc;
   rc = RemoveEclipseLinkFiles(hInstall);
   if (rc != ERROR_SUCCESS) {
      return rc;
   }
   rc = RemoveCodewarriorLinkFiles(hInstall);
   return rc;
}
