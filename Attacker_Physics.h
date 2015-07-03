#pragma once
#include "Component_Actor_Physics.h"

#define ATTACKER_MAX_VELOCITY     350.0f	//Attacker's fastest movement speed
#define ATTACKER_ACCEL_RATE       75.0f		//attacker's acceleration rate

class Attacker_Physics : public Component_Actor_Physics
{
public:
    /*=====================================================
    *Constructor: Initialize all data members

    *Parameters:
    =======================================================*/
    Attacker_Physics(void);
    ~Attacker_Physics(void);

    /*=====================================================
    *Update: Change hero's position in direction or button pressed
            
    *Parameters:
        hero: player
        timeStep: time-based movement
        windowHeight: game's y resolution
        windowWidth: game's x resolution
    =======================================================*/
    virtual void Update( Game_Actor& attacker, float timeStep, int windowHeight, int windowWidth );

    //Setters
    virtual void    SetXVelocity( bool xVel );
    virtual void    SetYVelocity( bool yVel );
};

