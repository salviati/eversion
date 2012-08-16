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

#ifndef EVERSION__TIMER_H
 #define EVERSION__TIMER_H

////////////////////////////////////////////////////////////////////////////////


// INCLUDES ///////////////////////////////////////////////////////////////////

 #include <SDL/SDL.h>

 #include "types.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {

// CLASSES ////////////////////////////////////////////////////////////////////

class timer
{
protected:
	u32 target;	//times in miliseconds

public:
	timer() { reset(); }
	timer(u32 time) { set(time); }

	inline u32 get();
	void set(u32 time) { target = ::SDL_GetTicks() + time; }
	void reset() { target=0; }
};


inline u32 timer::get()
{
	u32 now=::SDL_GetTicks();

	if(now >= target)
	{
		reset();
		return 0;
	}
	else
	{
		return target-now;
	}
}

////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__TIMER_H
