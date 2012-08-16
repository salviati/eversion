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

//#ifndef EVERSION__USE_ASM

#include "gfxutil.h"

extern "C" {

void flipImageV(u8 *buffer, u32 width, u32 height, u8 bpp)
{
	u8* _buffer = buffer;
	u8 *_bufferTop = buffer + width*(height-1)*bpp;
	u32 pitch = width*bpp*2;
	u32 height_half = height/2;
	u32 line_len = width*bpp;
	u8 c;

	for(u32 h = 0; h < height_half; h++)
	{
		for(u32 w = 0; w < line_len; w++)
		{
			c = *_buffer;
			*_buffer = *_bufferTop;
			*_bufferTop = c;

			_buffer++;
			_bufferTop++;
		}

		_bufferTop -= pitch;
	}
}


void flipImageH(u8 *buffer, u32 width, u32 height, u8 bpp)
{
	u32 pitch1 = width*bpp/2;
	u32 pitch2 = pitch1*3;
	u8 *_buffer = buffer;
	u8 *_buffer2 = buffer+(width-1)*bpp;
	u32 half_width = width/2;
	u32 bpp_m2 = bpp*2;
	u8 c;

	for(u32 h=0; h<height; h++)
	{
		for(u32 w=0; w<half_width; w++)
		{
			for(u32 pix = 0; pix<bpp; pix++)
			{
				c = *_buffer;
				*_buffer = *_buffer2;
				*_buffer2 = c;

				_buffer++;
				_buffer2++;
			}

			_buffer2 -= bpp_m2;
		}
		_buffer += pitch1;
		_buffer2 += pitch2;
	}
}


void swapAC(u8 *buffer, u32 width, u32 height, u8 bpp)
{
	u32 imageSize = width*height*bpp;

	for(u32 cswap = 0; cswap < imageSize; cswap += bpp)
	{
		buffer[cswap] ^= buffer[cswap+2] ^= buffer[cswap] ^= buffer[cswap+2];
	}
}

}

//#endif 
