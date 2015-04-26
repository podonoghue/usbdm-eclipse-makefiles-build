/*
 * Application.h
 *
 *  Created on: 15/11/2009
 *      Author: Peter
 */

#ifndef _APPLICATIONFILES_H_
#define _APPLICATIONFILES_H_

#include <string>
#include <stdio.h>

extern FILE *openApplicationFile(const std::string &filename, const std::string &attributes);
extern int checkExistsApplicationFile(const std::string &filename, const std::string &attributes=std::string("r"));
extern std::string getApplicationFilePath(const std::string &filename, const std::string &attributes=std::string("r"));
#ifdef useWxWidgets
extern char getPathSeparator(void);
#endif
#endif /* _APPLICATIONFILES_H_ */
