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

#ifndef EVERSION__CONTROL_DEVICE_H
 #define EVERSION__CONTROL_DEVICE_H

////////////////////////////////////////////////////////////////////////////////


// INCLUDES ////////////////////////////////////////////////////////////////////

# include <SDL/SDL.h>
# include "input_device.h"
# include "types.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {
	namespace io_device {

// CLASSES /////////////////////////////////////////////////////////////////////

class control_device : public input_device
{
public:
	enum button_t { a, b, select, start, up, down, left, right};

	control_device();
	virtual ~control_device();
	virtual void update() = 0;

	//virtual bool key_pressed(button_t button) = 0;
	//virtual void unpress_key(button_t button) = 0;

protected:
	SDLKey buttons[8];
};

////////////////////////////////////////////////////////////////////////////////

	}
}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__CONTROL_DEVICE_H
