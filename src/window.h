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

#ifndef EVERSION__WINDOW_H
 #define EVERSION__WINDOW_H


// INCLUDES ///////////////////////////////////////////////////////////////////

#include "surface.h"
#include "math.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {

// CLASSES ////////////////////////////////////////////////////////////////////

//Draws a styled window
class window
{
protected:
	static const u32 FC_WinColors[2][5];

	point2D<s32> pos;
	point2D<u32> size;
	surface image;
	char *caption;
	bool showCaption, isVisible;

	virtual void makeWin();

public:
	window() { init(); }
	window(s32 x, s32 y, u32 w, u32 h) { move(x,y); resize(w,h); }
	window(const point2D<u32> &_pos, const point2D<u32> &_size) { move(_pos); resize(_size); }
	virtual ~window() { free(); }

	virtual void init() { caption=NULL; isVisible=showCaption=true; }
	virtual void free() { setCaption(NULL); }

	virtual void draw();
	virtual void setCaption(char *str, u16 lineLen=0);

	void move(s32 x, s32 y) { pos.x=x; pos.y=y; }
	void move(const point2D<u32> &_pos) { pos=_pos; }

	void resize(u32 w, u32 h) { size.x=w; size.y=h; makeWin(); }
	void resize(const point2D<u32> &_size) { size=_size; makeWin(); }
};


////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__WINDOW_H
