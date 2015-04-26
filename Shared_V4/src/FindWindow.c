
#include <stdio.h>
#include "FindWindow.h"

//! A rather crude effort to locate an Eclipse window - Any one!
//!
//! @return HWND of Any Eclipse window located
//!
HWND FindEclipseWindowHwnd(void) {
   return FindWindowExA(NULL,NULL,"SWT_Window0",0);
}

//! Locates the HWND of a Console Application
//!
//! @return HWND of Console Application
//!
HWND GetConsoleHwnd(void) {
const int MaxTitleSize = 1024;           // Size for console window titles.
   char pszNewWindowTitle[MaxTitleSize]; // Fabricated window title.
   char pszOldWindowTitle[MaxTitleSize]; // Original window title.

   // Fetch current window title.
   GetConsoleTitleA(pszOldWindowTitle, MaxTitleSize);

   // Format a "unique" NewWindowTitle.
   wsprintfA(pszNewWindowTitle, "%d/%d", GetTickCount(), GetCurrentProcessId());

   // Change current window title.
   SetConsoleTitleA(pszNewWindowTitle);

   // Ensure window title has been updated.
   Sleep(40);

   // Look for window with NewWindowTitle.
   HWND hwndFound = FindWindowA(NULL, pszNewWindowTitle);

   // Restore original window title.
   SetConsoleTitleA(pszOldWindowTitle);

   return(hwndFound);
}
