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

#ifndef EVERSION__TILESET_H
#define EVERSION__TILESET_H


// INCLUDES ///////////////////////////////////////////////////////////////////

#include "surface.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {

// CLASSES ////////////////////////////////////////////////////////////////////

class tileset : public surface
{
protected:
	s32 count;			//count of tiles
	s32 width,height;	//dimensions of a tile

	virtual void init();
	virtual void free();

public:
	//ctor
	tileset() { init(); }
	tileset(char *filename, u32 width, u32 height, u32 count=0)	{ init(); load(filename,width,height,count); }
	//tileset(SDL_Surface *_image) { init(); image = _image; }
	//cctor
	//tileset(tileset& src) { src = *this; }
	//dtor
	virtual ~tileset() { free(); }

	void draw(s32 index, s32 x, s32 y, SDL_Surface *dst=NULL);
	void draw(s32 index, SDL_Rect rectDest, SDL_Surface *dst=NULL);

	virtual bool load(char *filename, s32 _width, s32 _height, s32 _count = 0);

	//get/setMember
	s32 getCount() { return count; }
	virtual s32 getWidth() { return width; }
	virtual s32 getHeight() { return height; }

};

///////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__TILESET_H
