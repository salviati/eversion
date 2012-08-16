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

#ifndef EVERSION__FONT_H
#define EVERSION__FONT_H


// INCLUDES ///////////////////////////////////////////////////////////////////

#include "tileset.h"
#include "types.h"


////////////////////////////////////////////////////////////////////////////////

namespace eversion {

// CLASSES ////////////////////////////////////////////////////////////////////

// note: unicode font support?

class font
{
	enum radix { radix_default=10, radix_2=2, radix_8=8, radix_10=10, radix_16=16 };

private:
	tileset graphic;

	u8 first,last;	// the 1st and last char of the charset
	s32 x,y;		// position of text cursor (not in pixels, instead char_size)

	bool keepCursor;
	radix defaultRadix;

public:
	font() { first=last=0; keepCursor = true; defaultRadix = radix_10; }
	// if first omitted, starts at space, if last omitted, loads all charset
	bool load(char *graphicFile, s32 width, s32 height, u8 _first='\x20', u8 _last='\x7F'); // default interval: [32-127]

	void write(char chr, SDL_Surface *dst=NULL);
	//void write(u8 chr) { write((char)chr); }
	void write(char *str, SDL_Surface *dst=NULL);
	//void write(u8 *str) { write((char*)str); }
	void write(s32 value, radix _radix = radix_default, SDL_Surface *dst=NULL);
	//void write(float value);

	template<typename X>
	font& operator<<(X param)
	{ bool _keepCursor = keepCursor; keepCursor = false; write(param); keepCursor = _keepCursor; return *this; }

	// member access
	void gotoXY(s32 _x, s32 _y) { x=_x; y=_y; }
	void setX(s32 _x) { x=_x; }
	void setY(s32 _y) { y=_y; }
	s32  getX() { return x; }
	s32  getY() { return y; }
	u32 getWidth() { return graphic.getWidth(); }
	u32 getHeight() { return graphic.getHeight(); }

	void setRadix(radix r) { defaultRadix = r; }
	radix getRadix() { return defaultRadix; }
};


///////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__FONT_H
