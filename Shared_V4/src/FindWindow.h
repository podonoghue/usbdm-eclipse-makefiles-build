/*
 * FindWindow.h
 *
 *  Created on: 10/12/2012
 *      Author: PODonoghue
 */

#ifndef FINDWINDOW_H_
#define FINDWINDOW_H_

#ifdef _WIN32
#include <windows.h>

HWND GetConsoleHwnd(void);
HWND FindEclipseWindowHwnd(void);
#endif

#endif /* FINDWINDOW_H_ */
