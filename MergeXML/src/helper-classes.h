#ifndef HELPER_CLASSES_H
#define HELPER_CLASSES_H

/*
Misc utility classes and routines for using Xerces-C++


This file is part of the sample code for the article,
"Processing XML with Xerces and the DOM" by Ethan McCallum (2005/09/08)

Published on ONLamp.com (http://www.onlamp.com/)
http://www.onlamp.com/pub/a/onlamp/2005/09/08/xerces_dom.html

*/
// = = = = = = = = = = = = = = = = = = = =

#include <algorithm>
#include <functional>
#include <iterator>

#include <xercesc/util/XMLString.hpp>

/**
\brief static functions to release C-style char* strings and XMLCh* strings
allocated by Xerces routines

Required because XMLString::release() takes pointer-to-pointer, not just
pointer.  THe alternative would be for StringManager and related classes to store
char** or XMLCh**, but that would be an effort of diminishing returns.
*/

struct FreeXercesString {

	static void releaseXMLString( XMLCh* str ) {
		xercesc::XMLString::release( &str ) ;
		return ;
	}

	static void releaseCString( char* str ) {
		xercesc::XMLString::release( &str ) ;
		return ;
	}

} ; // FreeXercesString

// = = = = = = = = = = = = = = = = = = = =

/**
\brief Dual-purpose (and two-faced) string: wraps a string (XMLCh* or char*)
and lets you access it in either form.

This is a value-added version of the "StrX" class from Xerces-C examples.

NOTE: the constructor COPIES the string it's given, so beware of using loose
strings as ctor parameters.  One reason to duplicate it to guarantee the
const char* string is allocated from the Xerces memory pool and therefore may
be freed using Xerces functions.

As a value-add feature, this class could store a std::string instead of a char*
and thus provide accessors to return "const std::string&" as well as "const char*".
Perhaps in a future version.


*/

#include <string>
#include <xercesc/util/XMLString.hpp>

class DualString {

	public :
	DualString( const XMLCh* const original ) ;

	DualString( const char* const original ) ;

	DualString( const std::string& original ) ;

	~DualString() throw() ;


	const char* asCString() const throw() ;

	const XMLCh* asXMLString() const throw() ;

	std::ostream& print( std::ostream& s ) const ;


	protected:
	// empty

	private :
	char*   cString_ ;
	XMLCh*  xmlString_ ;

} ; // class DualString


std::ostream& operator<<( std::ostream& s, const DualString& obj ) ;


// = = = = = = = = = = = = = = = = = = = =

#include<list>
#include<stdexcept>

#include<xercesc/util/XMLString.hpp>

/**
\\brief Converts between XMLCh* and char* strings, and takes ownership of the
newly-created string.

It's a wrapper around and an alternative to direct XMLString::transcode()
calls, which require the calling code to manually/individually free the memory
of the returned strings.

This class releases all of the owned pointers in its destructor.  You can
either pass a StringManager pointer around a set of related classes and perform all
of the memory cleanup at the end (with a single delete() call); or create a
StringManager object and let scoping rules trigger the destructor for you.

Several decisions were made in the design of this class:

- there were originally member functions to take ownership of arbitrary XMLCh*
  and char* strings; but since there's no way to tell from which memory pool
  those came (general heap or private/custom Xerces allocator) this was scrapped.
  As such, this class only manages its own strings, that is, ones initiated by
  internal calls to XMLString::transcode()

- Strings are stored internally as non-const pointers, and convert() returns
  the same.  Client code can still store convert() results as const pointers,
  but calls disown() for those same strings would require a cast.  (disown()
  does an internal lookup of the string and that requires us to search by
  non-const pointer.)

*/

class StringManager {

	private:
	typedef std::list< XMLCh* > XMLStringList ;
	typedef std::list< char* > CStringList ;

	XMLStringList xmlStrings_ ;
	CStringList cStrings_ ;

	protected:
	// empty

	public:
	StringManager() ;

	/// destroys the strings in the various lists
	~StringManager() throw() ;


	/// frees memory of all owned strings
	void drain() throw() ;


	/**
	\brief grant ownership of the string to the calling code

	throw std::logic_error if the specified string isn't found
	*/
	char* disown( char* str ) throw( std::logic_error ) ;


	/**
	\brief grant ownership of the string to the calling code

	throw std::logic_error if the specified string isn't found
	*/
	XMLCh* disown( XMLCh* str ) throw( std::logic_error ) ;


	/**
	\brief transcode the supplied C string to XMLCh* and take ownership of the XMLCh*

	The returned XMLCh* will be added to the const pool; calls to own() must therefore
	pass a const XMLCh* parameter
	*/

	XMLCh* convert( const char* str ) ;


	/**
	\brief transcode the supplied C++ string to XMLCh* and take ownership of the XMLCh*

	The returned XMLCh* will be added to the const pool; calls to own() must therefore
	pass a const XMLCh* parameter
	*/

	XMLCh* convert( const std::string& str ) ;


	/**
	\brief transcode the supplied XMLCh* to a C string and take ownership of the C string

	The returned char* will be added to the const pool; calls to own() must therefore
	pass a const char* parameter
	*/
	char* convert( const XMLCh* str ) ;

} ; // class StringManager 

#endif // #ifndef HELPER_CLASSES_H
