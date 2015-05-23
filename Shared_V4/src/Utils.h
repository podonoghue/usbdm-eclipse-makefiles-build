/*
 * Utils.h
 *
 *  Created on: 12/01/2011
 *      Author: pgo
 */

#ifndef UTILS_H_
#define UTILS_H_
#include <stdint.h>
#if defined(__cplusplus)
#include <string>
#endif

/*! Convert a single HEX character ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 15
 */
uint8_t hex1ToDecimal(char **ptr);

/*! Convert two HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 255
 */
uint8_t hex2ToDecimal( char **ptr);

/*! Convert four HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 65535
 */
uint16_t hex4ToDecimal( char **ptr);

/*! Convert six HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 0xFFFFFFU
 */
uint32_t hex6ToDecimal( char **ptr);

/*! Convert six HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 0xFFFFFFU
 */
uint32_t hex8ToDecimal( char **ptr);

#if defined(__cplusplus)
//! Filters a string to only contain a set of permitted values
//!
//! @param data    string to filter
//! @param pattern string containing permitted chars
//!
//! @return filtered string
//!
std::string filter(const std::string &data, const std::string &pattern);
#endif

#endif /* UTILS_H_ */
