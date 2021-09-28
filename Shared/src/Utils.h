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

/** Convert a single HEX character ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param[in/out] ptr Ptr to the character to convert. ptr is advanced
 *
 * @return - a value in the range 0 to 15
 */
uint8_t hex1ToDecimal(char *&ptr);

/** Convert two HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param[in/out] ptr  -  Ptr to the 1st character to convert. ptr is advanced
 *
 * @return - a value in the range 0 to 255
 */
uint8_t hex2ToDecimal( char *&ptr);

/** Convert four HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param[in/out] ptr  -  Ptr to the 1st character to convert. ptr is advanced
 *
 * @return - a value in the range 0 to 65535
 */
uint16_t hex4ToDecimal( char *&ptr);

/** Convert six HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param[in/out] ptr  -  Ptr to the 1st character to convert. ptr is advanced
 *
 * @return - a value in the range 0 to 0xFFFFFFU
 */
uint32_t hex6ToDecimal( char *&ptr);

/** Convert six HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param[in/out] ptr  -  Ptr to the 1st character to convert. ptr is advanced
 *
 * @return - a value in the range 0 to 0xFFFFFFU
 */
uint32_t hex8ToDecimal( char *&ptr);

/**
 * Filters a string to only contain a set of permitted values
 *
 * @param data    string to filter
 * @param pattern string containing permitted chars
 *
 * @return filtered string
 */
std::string filter(const std::string &data, const std::string &pattern);

/**
 * Check if a string starts with a stem string <b>literal</b>
 *
 * @param stem  Stem string to compare.  The length of stem determines the number of characters compared.
 * @param str   String to compare
 *
 * @return    true  => str start with stem
 * @return    false => str does not start with stem
 */
template<std::size_t N>
static inline bool strStartsWith(const char (&stem)[N], const char *str) {
   return strncmp(str, stem, N-1) == 0;
}

#endif

#endif /* UTILS_H_ */
