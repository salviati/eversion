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

#include "window.h"
#include <cstring>
#include "game.h"
#include "macros.h"


////////////////////////////////////////////////////////////////////////////////

namespace eversion {

const u32 window::FC_WinColors[2][5] =
{ 0x00000001,0x0000FECE,0x0000FFFF,0x0000FECE,0x00000016, 0x00000001,0x00F8BF24,0x00FFFFFF,0x00FFD86F,0x000000B0,};

// FUNCTIONS //////////////////////////////////////////////////////////////////

void window::makeWin()
{
	image.alloc(size.x, size.y);

	point2D<u32> pt(size);
	size_t clr_index = (eversion::screenBitsPerPixel>>3)-2;

	if(clr_index<0)
		clr_index=0;
	if(clr_index>1)
		clr_index=1;

	::SDL_Rect rc;
	for(size_t i=0; i<5; i++)
	{
		rc.x=2+i*2; rc.w=pt.x-4;
		rc.y=i*2; rc.h=2;
		image.fillRect(&rc,FC_WinColors[clr_index][i]);
		rc.y=pt.y-2+i*2;
		image.fillRect(&rc,FC_WinColors[clr_index][i]);
		rc.x=+i*2; rc.w=pt.x;
		rc.y=2+i*2; rc.h=pt.y-4;
		image.fillRect(&rc,FC_WinColors[clr_index][i]);

		pt.x-=4; pt.y-=4;
	}
/*
	font& font = game::instance()->getFont();
	rc.x=font.getWidth(); rc.y=font.getHeight();
	rc.w=size.x-font.getWidth()*2; rc.h=size.y-font.getHeight()*2;
	image.setClipRect(&rc);*/

	//image.setAlpha(100);
}

void window::draw()
{
	if(isVisible)
	{
		image.draw(pos.x,pos.y);

		if(showCaption && caption)
		{
			font& font = game::instance()->getFont();
			font.gotoXY(pos.x+font.getWidth(),pos.y+font.getHeight());
			font.write(caption/*,image.getSurface()*/);
		}
	}
}

void window::setCaption(char *str, u16 lineLen)
{
	if(caption)
	{
		delete [] caption;
		caption=NULL;
	}

	if(str)
	{
		caption = new char[strlen(str)+1];
		strcpy(caption,str);
	}

	if(lineLen)
	{
		char *p = caption;
		u16 len=1;

		do
		{
			while(*p != ' ' && *p)
			{
				len++;
				p++;
			}

			if(len>lineLen)
			{
				p-=UNSIGN(len-lineLen);
				while(*p != (char)' ')
					p--;
				*p = (char)'\n';
				len=1;
			}
			else
				len++;

		} while(*p++);


	}
}


////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////
