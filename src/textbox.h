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

#ifndef EVERSION__TEXTBOX_H
 #define EVERSION__TEXTBOX_H


// INCLUDES ///////////////////////////////////////////////////////////////////

#include "window.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {

// CLASSES ////////////////////////////////////////////////////////////////////

//Draws a styled textbox
class textbox : private window
{
public:
	typedef enum { dead, write, hold, rise, fall } textboxState_t;

protected:
	static u8 advTimeVal;
	static const u32 defWinW, defWinH;
	static const u8 boxMovSpd,arrowAvdVal;

	static surface imgArrow;

	char *strPos;
	char **lines;
	u16 maxStrLen, maxLines, currentLine;
	textboxState_t state;
	bool showArrow;

	virtual void reset();
	virtual void draw();

public:


	textbox() { init(); if(!imgArrow.hasImage()) imgArrow.load("arrow.png"); }
	~textbox() { free(); }

	virtual void init();
	virtual void free();

	u8 getTextRate() { return advTimeVal; }
	void setTextRate(u8 rate) { advTimeVal = rate; }

	void update();	//process text&draw
	void kill();

	bool moreText() { return *strPos != 0; }

	textboxState_t getState() { return state; }

	virtual void setCaption(char *str);
};


////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__TEXTBOX_H
