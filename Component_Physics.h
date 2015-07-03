#pragma once
#include "Game_Renderer.h"

#define TILE_SIZE         32
#define NEGATIVE_MOVEMENT false
#define POSITIVE_MOVEMENT true

class Game_Actor;
class Doge;

class Component_Physics
{
public:
    virtual ~Component_Physics() {}
    virtual void Update( Game_Actor& actor, float timeStep, int windowHeight, int windowWidth ) = 0;	//Update the hero's position through calculations
    virtual void Update( Doge& doge, float timeStep ) = 0;												//Update doges
    virtual void SetXVelocity( bool xVel ) = 0;															//Set the x velocity of the object
    virtual void SetYVelocity( bool yVel ) = 0;
    virtual void ClearXVelocity() = 0;																	//Set the velocity to 0
    virtual void ClearYVelocity() = 0;
    virtual float GetXPos() = 0;																		//Return the x or y position of the object
    virtual float GetYPos() = 0;
};


