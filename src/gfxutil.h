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

#ifndef __GFXUTIL_H
#define __GFXUTIL_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* parameters: func(imagebuffer,width,height,bytesperpixel) */

void flipImageV(u8*, u32, u32, u8);
void flipImageH(u8*, u32, u32, u8);
void swapAC(u8*, u32, u32, u8);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __GFXUTIL_H */
