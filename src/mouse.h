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

#ifndef EVERSION__MOUSE_H
# define EVERSION__MOUSE_H

////////////////////////////////////////////////////////////////////////////////


// INCLUDES ////////////////////////////////////////////////////////////////////

# include <SDL/SDL.h>
# include "input_device.h"
# include "types.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {
	namespace io_device {

// CLASSES /////////////////////////////////////////////////////////////////////

class mouse : public input_device
{
public:
	mouse();
	~mouse();

	void update();

	bool button_pressed(u8 button) { return (mouseState&SDL_BUTTON(button)) != 0; }
	void get_pos(int& x, int &y) { x=pos_x; y=pos_y; }
	void get_mov(int& x, int &y) { x=mov_x; y=mov_y; }
	void warp(int x, int y) { ::SDL_WarpMouse((u16)x, (u16)y); pos_x=x; pos_y=y; }

private:
	u8 mouseState;
	//bool update_rel;

	int pos_x, pos_y;
	int mov_x, mov_y;
};

////////////////////////////////////////////////////////////////////////////////

	}
}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__MOUSE_H
