/*
	BmUtil.cpp
		$Id$
*/

#include <stdio.h>

#include <Alert.h>
#include <Autolock.h>

#include "BmApp.h"
#include "BmPrefs.h"
#include "BmUtil.h"

/*------------------------------------------------------------------------------*\
	FindMsgString( archive, name)
		-	extracts the msg-field with the specified name from the given archive and
			returns it.
		-	throws BM_invalid_argument if field is not contained withing archive
\*------------------------------------------------------------------------------*/
const char* FindMsgString( BMessage* archive, const char* name) {
	const char* str;
	BM_assert(archive && name);
	if (archive->FindString( name, &str) == B_OK) {
		return str;
	} else {
		throw BM_invalid_argument( BString( "unknown message-field: ") << name);
	}
}

/*------------------------------------------------------------------------------*\
	FindMsgBool( archive, name)
		-	extracts the msg-field with the specified name from the given archive and
			returns it.
		-	throws BM_invalid_argument if field is not contained withing archive
\*------------------------------------------------------------------------------*/
bool FindMsgBool( BMessage* archive, const char* name) {
	bool b;
	BM_assert(archive && name);
	if (archive->FindBool( name, &b) == B_OK) {
		return b;
	} else {
		throw BM_invalid_argument( BString( "unknown message-field: ") << name);
	}
}

/*------------------------------------------------------------------------------*\
	FindMsgInt64( archive, name)
		-	extracts the msg-field with the specified name from the given archive and
			returns it.
		-	throws BM_invalid_argument if field is not contained withing archive
\*------------------------------------------------------------------------------*/
int64 FindMsgInt64( BMessage* archive, const char* name) {
	int64 i;
	BM_assert(archive && name);
	if (archive->FindInt64( name, &i) == B_OK) {
		return i;
	} else {
		throw BM_invalid_argument( BString( "unknown message-field: ") << name);
	}
}

/*------------------------------------------------------------------------------*\
	FindMsgInt32( archive, name)
		-	extracts the msg-field with the specified name from the given archive and
			returns it.
		-	throws BM_invalid_argument if field is not contained withing archive
\*------------------------------------------------------------------------------*/
int32 FindMsgInt32( BMessage* archive, const char* name) {
	int32 i;
	BM_assert(archive && name);
	if (archive->FindInt32( name, &i) == B_OK) {
		return i;
	} else {
		throw BM_invalid_argument( BString( "unknown message-field: ") << name);
	}
}

/*------------------------------------------------------------------------------*\
	FindMsgInt16( archive, name)
		-	extracts the msg-field with the specified name from the given archive and
			returns it.
		-	throws BM_invalid_argument if field is not contained withing archive
\*------------------------------------------------------------------------------*/
int16 FindMsgInt16( BMessage* archive, const char* name) {
	int16 i;
	BM_assert(archive && name);
	if (archive->FindInt16( name, &i) == B_OK) {
		return i;
	} else {
		throw BM_invalid_argument( BString( "unknown message-field: ") << name);
	}
}

/*------------------------------------------------------------------------------*\
	FindMsgMsg( archive, name)
		-	extracts the msg-field with the specified name from the given archive and
			returns it.
		-	throws BM_invalid_argument if field is not contained withing archive
\*------------------------------------------------------------------------------*/
BMessage* FindMsgMsg( BMessage* archive, const char* name, BMessage* msg) {
	BM_assert(archive && name);
	if (archive->FindMessage( name, msg) == B_OK) {
		return msg;
	} else {
		throw BM_invalid_argument( BString( "unknown message-field: ") << name);
	}
}

/*------------------------------------------------------------------------------*\
	FindMsgFloat( archive, name)
		-	extracts the msg-field with the specified name from the given archive and
			returns it.
		-	throws BM_invalid_argument if field is not contained withing archive
\*------------------------------------------------------------------------------*/
float FindMsgFloat( BMessage* archive, const char* name) {
	float f;
	BM_assert(archive && name);
	if (archive->FindFloat( name, &f) == B_OK) {
		return f;
	} else {
		BString s( "unknown message-field: ");
		s += name;
		throw BM_invalid_argument( s.String());
	}
}

/*------------------------------------------------------------------------------*\
	BytesToString( bytes)
		-	returns the given number of bytes as a short, descriptive string:
			* bytes < 1024 				-> "X bytes"
			* 1024 < bytes < 1024000	-> "X.xx KB"
			* 1024000 < bytes 			-> "X.xx MB"
\*------------------------------------------------------------------------------*/
BString BytesToString( int32 bytes) {
	char buf[100];
	if (bytes >= 1024000) {
		sprintf( buf, "%6.2f MB", bytes/1024000.0);
	} else if (bytes >= 1024) {
		sprintf( buf, "%6.2f KB", bytes/1024.0);
	} else {
		sprintf( buf, "%ld bytes", bytes);
	}
	return BString(buf);
}

/*------------------------------------------------------------------------------*\*\
	ShowAlert( text)
		-	pops up an Alert showing the passed (error-)text
\*------------------------------------------------------------------------------*/
void ShowAlert( const BString &text) {
	BAlert* alert = new BAlert( NULL, text.String(), "OK", NULL, NULL, 
										 B_WIDTH_AS_USUAL, B_STOP_ALERT);
	alert->Go();
}
