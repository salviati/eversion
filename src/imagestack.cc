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

#include <cstdio>

#include "imagestack.h"
#include <SDL/SDL_image.h>
#include "globals.h"
#include "config.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {

// GLOBALS ////////////////////////////////////////////////////////////////////

image_stack* image_stack::pimage_stack	= NULL;


// FUNCTIONS //////////////////////////////////////////////////////////////////

void image_info::load(char *_filename)
{
	free();

	filename=new char[strlen(_filename)+strlen(dataDir)+1];
	strcpy(filename,eversion::dataDir);	strcat(filename,_filename);
	surface=IMG_Load(filename);

	if(surface==NULL)
	{
		fprintf(stderr,"image_info::load: failed to load %s\n", filename);
		return;
	}
}

void image_info::setFileName(char* _filename)
{
#ifdef EVERSION__DEBUG
	if(filename)
	{
		fprintf(stderr, "image_info::setFilename: filename exists");
	}
#endif
	filename=new char[strlen(_filename)+1];	strcpy(filename,_filename);
}


image_info* image_stack::find(char *filename)
{
	//image already loaded?
	for(size_t i=0; i < images.size(); i++)
	{
		if(!strcmp(images[i]->getFileName(),filename))
		{
			return images[i];
		}
	}

	return NULL;
}

SDL_Surface* image_stack::load(char *filename)
{

	//image already loaded?
	image_info* imginf = find(filename);

	if(imginf)
	{
 #ifdef EVERSION__DEBUG
		fprintf(stderr,"image_stack::load: \"%s\" already loaded, returning existing pointer...\n",filename);
 #endif
		return imginf->getSurface();
	}
	else
	{
		image_info* img = new image_info;
		images.push_back(img);
		img->load(filename);

		return img->getSurface();
	}
}

image_stack* image_stack::instance()
{
	if(pimage_stack == NULL)
		pimage_stack = new image_stack;

	return pimage_stack;
}

image_stack::~image_stack()
{
	for(size_t i=0; i<images.size(); i++)
	{
		if(images[i])
		{
			delete images[i];
		}
	}
	images.clear();
}

///////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////
