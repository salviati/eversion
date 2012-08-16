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

#include "sdl.h"
#include "globals.h"
#include "surface.h"
#include "gfxutil.h"
#include "imagestack.h"
#include <string.h>

////////////////////////////////////////////////////////////////////////////////

namespace eversion {


// FUNCTIONS //////////////////////////////////////////////////////////////////

void surface::init()
{
	image = NULL;
	rect.x = rect.y = 0;  rect.w = rect.h = 0;
}


void surface::free()
{
/*
	if(image != NULL)
	{
		SDL_FreeSurface(image);
	}
*/
	init();
}

void surface::dealloc()
{
	if(image)
	{
		SDL_FreeSurface(image);
	}

	init();
}


void surface::draw(s32 x, s32 y, SDL_Surface *dst)
{
	::SDL_Rect rectDest;

	rectDest.x = x;  rectDest.y = y;
	rectDest.w = image->w;  rectDest.h = image->h;

	eversion::SDL_BlitSurface(image, &rect, dst, &rectDest);
}


void surface::draw(::SDL_Rect rectDest, SDL_Surface *dst)
{
	eversion::SDL_BlitSurface(image, &rect, dst, &rectDest);
}


surface& surface::flipH()
{
	::flipImageH(
		(u8*)image->pixels,
		(u32)image->w, (u32)image->h,
		image->format->BitsPerPixel/8
		);

	return *this;
}


surface& surface::flipV()
{
	::flipImageV(
		(u8*)image->pixels,
		(u32)image->w, (u32)image->h,
		image->format->BitsPerPixel/8
		);

	return *this;
}


bool surface::load(char *filename)
{
	//free();

	image = image_stack::instance()->load(filename);

	if(image==NULL)
		return false;

	rect.w = image->w; rect.h = image->h;

	setColorKey(0);
	return true;
}

bool surface::alloc(s32 w, s32 h, u16 depth)
{
	dealloc();
	s32 bpp=depth?depth:eversion::screenBitsPerPixel;
	image = SDL_CreateRGBSurface(SDL_SRCCOLORKEY,w,h,bpp,0,0,0,0);

	if(image==NULL)
	{
		fprintf(stderr, "surface::alloc: SDL_CreateRGBSurface returned NULL\n");
		return false;
	}

	if ( SDL_MUSTLOCK(image) )
	{
		if ( SDL_LockSurface(image) < 0 )
		{
			fprintf(stderr, "surface::alloc: couldn't lock the surface\n");
		}
	}

	::memset((u8*)(image->pixels),0,image->w*image->h*image->format->BytesPerPixel);

	if ( SDL_MUSTLOCK(image) )
		SDL_UnlockSurface(image);



	rect.x=0; rect.y=0; rect.w=w; rect.h=h;
	setColorKey(0);
	return true;
}

////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////
