#pragma once
#include "Component_Actor_Physics.h"

#define DODGER_MAX_VELOCITY     800.0f
#define DODGER_ACCEL_RATE       100.0f

//Where velocity, acceleration, and anything involving movement and the player are handled
class Dodger_Physics : public Component_Actor_Physics
{
public:
    /*=====================================================
    *Constructor: Initialize all data members

    *Parameters:
    =======================================================*/
    Dodger_Physics();
    ~Dodger_Physics();

    /*=====================================================
    *Update: Change hero's position in direction or button pressed
            
    *Parameters:
        hero: player
        timeStep: time-based movement
        windowHeight: game's y resolution
        windowWidth: game's x resolution
    =======================================================*/
    virtual void Update( Game_Actor& dodger, float timeStep, int windowHeight, int windowWidth );

    //Setters
    virtual void    SetXVelocity( bool xVel );
    virtual void    SetYVelocity( bool yVel );

private:
};

