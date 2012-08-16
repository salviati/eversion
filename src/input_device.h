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

#ifndef EVERSION__INPUT_DEVICE_H
 #define EVERSION__INPUT_DEVICE_H

////////////////////////////////////////////////////////////////////////////////


// INCLUDES ////////////////////////////////////////////////////////////////////

# include <SDL/SDL.h>

////////////////////////////////////////////////////////////////////////////////

namespace eversion {
	namespace io_device {

// CLASSES /////////////////////////////////////////////////////////////////////

class input_device
{
public:
	input_device();
	virtual ~input_device();
	virtual void update() = 0;
};

////////////////////////////////////////////////////////////////////////////////

	}
}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__INPUT_DEVICE_H
