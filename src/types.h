/*
    Eversion, a CRPG engine.
    Copyright (c) 2002-2012 Utkan Güngördü (utkan@freeconsole.org)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef EVERSION__TYPES_H
 #define EVERSION__TYPES_H

typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned long		u32;

typedef signed char			s8;
typedef signed short		s16;
typedef signed long			s32;

 #ifndef NULL
 # ifdef __cplusplus
 #  define NULL 0	// __cplusplus-only definition
 # else
 #  define NULL ((void*)0)
 # endif
 #endif


#endif //EVERSION__TYPES_H
