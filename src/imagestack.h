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

#ifndef EVERSION__IMAGESTACK_H
 #define EVERSION__IMAGESTACK_H


// INCLUDES ///////////////////////////////////////////////////////////////////

#include <cstring>
#include <vector>
#include <SDL/SDL.h>


////////////////////////////////////////////////////////////////////////////////

//these classes will prevent load of the same image more than once.

namespace eversion {

// CLASSES ////////////////////////////////////////////////////////////////////

struct image_info
{
private:
	char *filename;
	SDL_Surface *surface;

	void init() { surface=NULL; filename=NULL; }
	void free() { /*freeSurface();*/ if(filename) delete [] filename; init(); }

	void setFileName(char* _filename);

public:
	image_info() { init(); }
	image_info(char *_filename) { init(); load(_filename); }
	~image_info() { free(); }

	void freeSurface() { if(surface) SDL_FreeSurface(surface); }

	char* getFileName() { return filename; }	//insecure
	SDL_Surface* getSurface() { return surface; }

	void load(char *_filename);
};

///////////////////////////////////////////////////////////////////////////////

class image_stack
{
private:
	static image_stack *pimage_stack;
	std::vector<image_info*> images;

	image_stack() {}

public:
	~image_stack();
	static image_stack* instance();

	SDL_Surface* load(char* filename);
	image_info* find(char *filename);
	SDL_Surface* get(char *filename) { return find(filename)->getSurface(); }
};


////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__IMAGESTACK_H
