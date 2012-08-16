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

#ifndef EVERSION__KEYBOARD_H
# define EVERSION__KEYBOARD_H

////////////////////////////////////////////////////////////////////////////////


// INCLUDES ////////////////////////////////////////////////////////////////////

# include <SDL/SDL.h>
# include "control_device.h"
# include "types.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {
	namespace io_device {

// CLASSES /////////////////////////////////////////////////////////////////////

class keyboard : public control_device
{
public:
	keyboard();
	~keyboard();

	void update() { keyBuffer = ::SDL_GetKeyState(NULL); }

	bool key_pressed(SDLKey key) { return keyBuffer[key]?true:false; }
	void unpress_key(SDLKey key) { keyBuffer[key]=false; }

	bool key_pressed(control_device::button_t button) { return key_pressed( buttons[button] ); }
	void unpress_key(control_device::button_t button) { unpress_key( buttons[button] ); }

private:
	u8* keyBuffer;
};

////////////////////////////////////////////////////////////////////////////////

	}
}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__KEYBOARD_H
