#pragma once
#include "Component_Physics.h"

//Abstraction for physics interface
class Component_Actor_Physics : public Component_Physics
{
public:
    Component_Actor_Physics();
    ~Component_Actor_Physics();

    //Override
    virtual void Update( Game_Actor& hero, float timeStep, int windowHeight, int windowWidth ) = 0;

    //unused
    virtual void Update( Doge& doge, float timeStep ) {}

    //Override
    virtual void    SetXVelocity( bool xVel ) = 0;
    virtual void    SetYVelocity( bool yVel ) = 0;
    
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

