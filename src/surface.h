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

#ifndef EVERSION__SURFACE_H
#define EVERSION__SURFACE_H


// INCLUDES ///////////////////////////////////////////////////////////////////

#include <SDL/SDL.h>
#include "types.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {

// CLASSES ////////////////////////////////////////////////////////////////////

class surface
{
protected:
	::SDL_Surface *image;
	::SDL_Rect	rect;

public:
	//ctor
	surface() { init(); }
	surface(char *filename) { init(); load(filename); }
	surface(::SDL_Surface *_image) { init(); image = _image; }
	//cctor
	//surface(surface& src);
	//dtor
	virtual ~surface() { dealloc(); }

protected:
	virtual void init();
	virtual void free();

	void dealloc();

public:
	void draw(s32 x, s32 y,  SDL_Surface *dst=NULL);
	void draw(::SDL_Rect rectDest, SDL_Surface *dst=NULL);

	virtual surface& flipH();
	virtual surface& flipV();
	s32 fillRect(::SDL_Rect *rect, u32 color) { return ::SDL_FillRect(image, rect, color); }
	/*virtual void hLine(s32 x1, s32 y, s32 x2, u32 color);
	virtual void vLine(s32 x, s32 y1, s32 y2, u32 color);
	virtual void line(s32 x1, s32 y1, s32 x2, s32 y2);*/

	bool alloc(s32 w, s32 h, u16 depth=0);

	virtual bool load(char *filename);

	//set/getMember
	virtual s32 getWidth() { return image->w; }
	virtual s32 getHeight() { return image->h; }
	//virtual u32 getFlags() { return image->flags; }
	//virtual ::SDL_Surface* getSurface() { return image; }	//unsafe
	virtual ::SDL_Rect getRect() { return rect; }

	void setClipRect(SDL_Rect *rc) { ::SDL_SetClipRect(image,rc); }

	void setAlpha(u8 alpha) { ::SDL_SetAlpha(image, SDL_SRCALPHA|SDL_RLEACCEL, alpha); }
	u8 getAlpha() { return image->format->alpha; }

	void setColorKey(u32 key) { ::SDL_SetColorKey(image, SDL_SRCCOLORKEY|SDL_RLEACCEL, key); }
	u32 getColorKey() { return image->format->colorkey; }

	virtual bool hasImage() { return image!=NULL; }
};

///////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__SURFACE_H
