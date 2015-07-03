#pragma once
#include "Sprite.h"

class Game_Actor;      //Forward declaration to prevent looping dependencies
class Doge;

//Base interface for every graphics component
class Component_Graphics
{
public:
    virtual ~Component_Graphics() {}
    virtual void Update( Game_Actor& hero, const float timeStep, bool collision ) = 0;	//Update the current hero's sprite position, dodger or attacker, only really used during animations 
    virtual void Update( Game_Actor& hero, const float timeStep ) = 0;					//I actually don't know why this is here, it's never used
    virtual void Update( Doge& doge ) = 0;												//Update doges
    virtual void Draw() = 0;															//Draw to the screen the updated sprite
    virtual void DrawMouse() = 0;														//Draw to the screen the update mouse
    virtual void SetDestinationX( int x ) = 0;											//Set x position of the sprite
    virtual void SetDestinationY( int y ) = 0;											//set y position of the sprite
    virtual SDL_Rect GetDestination() = 0;												//Get the rectangle where the sprite is located
    virtual SDL_Rect GetMouseDest() = 0;												//Get the rectangle where the mouse is located
};

