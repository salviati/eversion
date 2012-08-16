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

#ifndef EVERSION__LAYER_H
#define EVERSION__LAYER_H


// INCLUDES ///////////////////////////////////////////////////////////////////

#include <string.h>

#include "types.h"
#include "math.h"


////////////////////////////////////////////////////////////////////////////////

namespace eversion {

// CLASSES ////////////////////////////////////////////////////////////////////


template<class T>
class layer
{
protected:
	T *data;
	u32 width, height;
public:
	layer() { init(); }
	layer(u32 _width, u32 _height) { init(); create(_width,_height); }
	~layer() { free(); }

	void create(u32 _width, u32 _height)
	{ free(); width = _width; height = _height; data = new T[width*height]; clear(); }

	void init() { data = NULL; }
	void free() {  if(data) { delete [] data; data = NULL; } init(); }

	void clear(int c=0) { memset(data,c,sizeof(T)*width*height); }

	T get(u32 x, u32 y) { return data[ x+width*y ]; }
	void set(u32 x, u32 y, T value) { data[ x+width*y ] = value; }

	u32 getWidth() const { return width; }
	u32 getHeight() const { return height; }
};

///////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__LAYER_H
