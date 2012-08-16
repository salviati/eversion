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

// INCLUDES ///////////////////////////////////////////////////////////////////

#include <cstdlib>

#include "font.h"
#include "macros.h"
#include "config.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {

// FUNCTIONS //////////////////////////////////////////////////////////////////

bool font::load(char *graphicFile, s32 width, s32 height, u8 _first, u8 _last)
{
	if( graphic.load(graphicFile, width, height, _last ? (_last-_first) : 0) == true )
	{
		first = _first;
		last = _last ? _last : (graphic.getCount() + first);
	}
	else
	{
		fprintf(stderr,"font::load failure");
		return false;
	}

	return true;
}

void font::write(char chr, SDL_Surface *dst)
{
	// unsigned required for interval check

	if(static_cast<u8>(chr)>=first && static_cast<u8>(chr)<=last)
		graphic.draw((u32)(static_cast<u8>(chr)-first),getX(),getY(),dst);
#ifndef EVERSION__DEBUG
	else
		fprintf(stderr,"font::write - chr out of bounds (\'%c\' - %d",chr,chr);
#endif
}

void font::write(char *str, SDL_Surface *dst)
{
	char *ptr = str;

	s32 x = getX();
	s32 y = getY();


	while(*ptr)
	{
		//graphic.draw(x,y,(GLuint)(*ptr));
		if(*ptr == (char)'\n')	//1 line down; x=beginX
		{
			setX(x);
			setY(getY() + (s32)graphic.tileset::getHeight()*2);
		}
		else
		{
			write(*ptr,dst);
			setX(getX() + (s32)graphic.tileset::getWidth());	//advance 1 char wide
		}

		ptr++;
	}


	if(keepCursor)
	{
		setX(x);
		setY(y);
	}
}

void font::write(s32 value, radix r, SDL_Surface *dst)
{
	if (r != radix_10) {
		fprintf(stderr, "only base10 is supported");
	}
	
	char buffer[1+sizeof(s32)+1]; // 1 for minus sugn.
    snprintf(buffer, 1+sizeof(s32)+1, "%d", value);
	write(buffer,dst);
}

///////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////
