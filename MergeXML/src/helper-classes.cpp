/*

This file is part of the sample code for the article,
"Processing XML with Xerces and the DOM" by Ethan McCallum (2005/09/08)

Published on ONLamp.com (http://www.onlamp.com/)
http://www.onlamp.com/pub/a/onlamp/2005/09/08/xerces_dom.html

*/
#include "helper-classes.h"

#include <list>
#include <iterator>
#include <algorithm>
#include <stdexcept>

#include <xercesc/util/XMLString.hpp>

// = = = = = = = = = = = = = = = = = = = =

/*
	class FreeXercesString is a template and thus
	defined in its entirety in the header
*/

// = = = = = = = = = = = = = = = = = = = =

#include<string>
#include<xercesc/util/XMLString.hpp>

DualString::DualString( const XMLCh* const original )
	:
	cString_( xercesc::XMLString::transcode( original ) ) ,
	xmlString_( xercesc::XMLString::replicate( original ) )
{
	return ;
} // DualString::ctor( const XMLCh* )


DualString::DualString( const char* const original )
	:
	cString_( xercesc::XMLString::replicate( original ) ) ,
	xmlString_( xercesc::XMLString::transcode( original ) )
{
	return ;
} // DualString::ctor( const char* )


DualString::DualString( const std::string& original )
	:
	cString_( xercesc::XMLString::replicate( original.c_str() ) ) ,
	xmlString_( xercesc::XMLString::transcode( original.c_str() ) )
{
	return ;
} // DualString::ctor( const std::string& )


DualString::~DualString() throw() {

	xercesc::XMLString::release( &cString_ ) ;
	xercesc::XMLString::release( &xmlString_ ) ;

	return ;

} // DualString::dtor()


const char* DualString::asCString() const throw() {
	return( cString_ ) ;
} // DualString::asCString()


const XMLCh* DualString::asXMLString() const throw() {
	return( xmlString_ ) ;
} // DualString::asXMLString()


std::ostream& DualString::print( std::ostream& s ) const {
	s << cString_ ;
	return( s ) ;
} // DualString::print()


std::ostream& operator<<( std::ostream& s, const DualString& obj ) {
	return( obj.print( s ) ) ;
} // operator<< for DualString



// = = = = = = = = = = = = = = = = = = = =


StringManager::StringManager()
	:
	xmlStrings_() ,
	cStrings_()
{

	return ;

} // StringManager::ctor


StringManager::~StringManager() throw(){

	drain() ;
	return ;

} // StringManager::dtor


void StringManager::drain() throw() {

	std::for_each(
		xmlStrings_.begin() ,
		xmlStrings_.end() ,
		FreeXercesString::releaseXMLString
	) ;


	std::for_each(
		cStrings_.begin() ,
		cStrings_.end() ,
		FreeXercesString::releaseCString
	) ;

	return ;

} // StringManager::drain()


char* StringManager::disown( char* str ) throw( std::logic_error ){

	CStringList::iterator item = std::find( cStrings_.begin() , cStrings_.end() , str ) ;

	if( cStrings_.end() == item ){
		throw( std::logic_error( "Request to disown a string not owned by this container." ) ) ;
	}

	char* result = *item ;

	// the call to list<>::remove has the added benefit of nailing duplicates
	cStrings_.remove( str ) ;

	return( result ) ;

} // StringManager::disown( char* str )

XMLCh* StringManager::disown( XMLCh* str ) throw( std::logic_error ){

	XMLStringList::iterator item = std::find( xmlStrings_.begin() , xmlStrings_.end() , str ) ;

	if( xmlStrings_.end() == item ){
		throw( std::logic_error( "Request to disown a string not owned by this container." ) ) ;
	}

	XMLCh* result = *item ;

	// the call to list<>::remove has the added benefit of nailing duplicates
	xmlStrings_.remove( str ) ;

	return( result ) ;

} // StringManager::disown( XMLCh* str )



XMLCh* StringManager::convert( const char* str ){

	XMLCh* result = xercesc::XMLString::transcode( str ) ;

	xmlStrings_.push_back( result ) ;

	return( result ) ;

} // StringManager::convert( const char* )

XMLCh* StringManager::convert( const std::string& str ){

	XMLCh* result = xercesc::XMLString::transcode( str.c_str() ) ;

	xmlStrings_.push_back( result ) ;

	return( result ) ;

} // StringManager::convert( const std::string& )

char* StringManager::convert( const XMLCh* str ){

	char* result = xercesc::XMLString::transcode( str ) ;

	cStrings_.push_back( result ) ;

	return( result ) ;

} // StringManager::convert( const XMLCh* )

// = = = = = = = = = = = = = = = = = = = =
