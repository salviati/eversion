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

#include "keyboard.h"
#include "config.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {
	namespace io_device {

// FUNCTIONS //////////////////////////////////////////////////////////////////

keyboard::keyboard()
{
	keyBuffer=NULL;

#ifdef EVERSION__UNICODE
	::SDL_EnableUNICODE(1);
#endif

	buttons[a] = SDLK_z;
	buttons[b] = SDLK_x;
	buttons[start] = SDLK_RETURN;
	buttons[select] = SDLK_SPACE;

	buttons[up] = SDLK_UP;
	buttons[down] = SDLK_DOWN;
	buttons[left] = SDLK_LEFT;
	buttons[right] = SDLK_RIGHT;

	update();
}

keyboard::~keyboard()
{
}

////////////////////////////////////////////////////////////////////////////////

	}
}

////////////////////////////////////////////////////////////////////////////////
