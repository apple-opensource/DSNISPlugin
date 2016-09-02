/*
 * Copyright (c) 2002 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
 
#ifndef __DSUTIL_H__
#define __DSUTIL_H__

#include <stdarg.h>

#ifndef streq
#define streq(A, B) (strcmp(A, B) == 0)
#endif

#ifndef IndexNull
#define IndexNull (unsigned int)-1
#endif

/*
 * Characters in names to be escaped before mapping to X.500
 */
#define NeedEscapeRDN(c) \
	 (((c) == '+') || \
	 ((c) == ',') || \
	 ((c) == ';') || \
	 ((c) == '\"') || \
	 ((c) == '\\') || \
	 ((c) == '<') || \
	 ((c) == '>'))

#define NeedEscapeAVA(c) (NeedEscapeRDN(c) || ((c) == '='))

char *copyString(char *);
char *concatString(char *, char *);
char **insertString(char *, char **, unsigned int);
char **appendString(char *, char **);
void freeList(char **);
void freeString(char *);
unsigned int listLength(char **);
unsigned int listIndex(char *,char **);
char *prefix(char *, char);
char *postfix(char *, char);
char *presuffix(char *, char);
char *suffix(char *, char);
char *lowerCase(char *);
char **explode(char *, char *);
char *itoa(int);

#endif __DSUTIL_H__
