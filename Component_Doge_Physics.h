#pragma once
#include "Component_Physics.h"

#define DOGE_SPEED_BIG    45.0f
#define DOGE_SPEED_MED    200.0f
#define DOGE_SPEED_SML    375.0f
#define DOGE_SPEED_FAST   460.0f 

class Component_Doge_Physics : public Component_Physics
{
public:
    /*=====================================================
    *constructor: intialize the velocity depending on doge size

    *Parameters:
        doge: for initializing variables
        speed: which speed the object flys at
    =======================================================*/
    Component_Doge_Physics( Doge& doge, float speed );
    ~Component_Doge_Physics();

    //unused
    virtual void Update( Game_Actor& hero, float timeStep, int windowHeight, int windowWidth ) {};

    /*=====================================================
    *Update: Update the doge's position on screen accoording
        to its size and heft and stuff

    *Parameters:
        doge: the flying enemy
        timeStep: movement by time rather than FPS
    =======================================================*/
    virtual void Update( Doge& doge, float timeStep );

    //unused
    virtual void    SetXVelocity( bool xVel ) {}
    virtual void    SetYVelocity( bool yVel ) {}
    
    //Getters and Setters
    virtual void    ClearXVelocity() { xVelocity = 0; }
    virtual void    ClearYVelocity() { yVelocity = 0; }
    virtual float   GetXPos()        { return xPos; }
    virtual float   GetYPos()        { return yPos; }

protected:
    float   xVelocity;      //x and y current velocities
    float   yVelocity;
    float   tempX;          //Temporary holders of movement
    float   tempY;
    float   xPos;           //Decimal point accurate on-screen positions
    float   yPos;
    int     xTile;          //Current 32x32 tile the dodger is on
    int     yTile;
};

