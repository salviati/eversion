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

#ifndef EVERSION__GAME_H
#define EVERSION__GAME_H


// INCLUDES ///////////////////////////////////////////////////////////////////

#include <vector>

#include "entity.h"
#include "globals.h"
#include "map.h"
#include "font.h"
#include "window.h"
#include "textbox.h"

////////////////////////////////////////////////////////////////////////////////

namespace eversion {

// CLASSES ////////////////////////////////////////////////////////////////////

// game Singleton:
class game
{
private:
	static game *lpGame;
	bool alive;

	//view-port related variables
	map  themap;
	::SDL_Rect scene;
	point2D<s32> cam;
	std::vector<entity*> entities;
	font thefont;
	textbox textWin;

	//entity related vairables
	size_t focus;		//index of the entity followed by cam

	game() : alive(true) { }

public:
	~game();
	static game *instance();

	// Functions related to initializations

	// Main initialization function of the game
	void init();

private:
	void initScene(s32 w, s32 h);

	//  Game-Logic functions
	void updateControls();

	void updateKeyb();
	void updateMouse();

public:
	// GameOver flag controls
	bool isAlive() { return alive; }
	//void isOver(bool _endGame) { endGame = _endGame; } // change the flag
	void endGame() { alive = false; }

	// Graphics Drawing functions
	void drawScene();
	void drawEntities();
	::SDL_Rect getSceneRect() { return scene; }
	font& getFont() { return thefont; }

	void moveCam(s32 x, s32 y) { cam.x+=x; cam.y+=y; normalizeCam(); }
	void moveCam(const point2D<s32> &p) { moveCam(p.x,p.y); }
	void normalizeCam();

	point2D<s32> getCam() { return cam; }

	// Game-Logic functions
	void update();
	char checkObstruction(entity* ent, entity::direction_t d);//-3=map_bounds,-2=map_obs, -1=entity, 0=no-obst
	bool thereEntity(s32 x, s32 y);
	void spawnEntity(char *img, s32 tx, s32 ty, s32 w=32, s32 h=32, s32 s=4, entity::direction_t d=entity::down);

};

///////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////

#endif //EVERSION__GAME_H
