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

#ifndef EVERSION__MACROS_H
#define EVERSION__MACROS_H

#define RELEASE_ARRAY( x ) if(x) { delete [] x; x = NULL; }
#define RELEASE_OBJ( x ) if(x) { delete x; x = NULL; }
#define RELEASE( x ) if(x) delete (x);

#ifdef MIN
#undef MIN
#endif //MIN
template<typename T> inline T MIN(T x, T y) { return x>y ? y : x; }

#ifdef MAX
#undef MAX
#endif //MAX
template<typename T> inline T MAX(T x, T y) { return x>y ? x : y; }

template<typename T> inline T UNSIGN(T x) { return x>=0?x:0; }

#endif //EVERSION__MACROS_H
