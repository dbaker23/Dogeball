#include "Dodger_Physics.h"
#include "Game_Actor.h"

Dodger_Physics::Dodger_Physics()
{
    xVelocity = 0;
    yVelocity = 0;
    tempX     = HERO_START_X;
    tempY     = HERO_START_Y;
    xPos      = HERO_START_X;
    yPos      = HERO_START_Y;
    xTile     = (int)HERO_START_X / TILE_SIZE;
    yTile     = (int)HERO_START_Y / TILE_SIZE;
}

Dodger_Physics::~Dodger_Physics()
{
}

//Same as attacker physics
void Dodger_Physics::Update( Game_Actor& dodger, float timeStep, int windowHeight, int windowWidth )
{
    tempX += xVelocity * timeStep;
    tempY += yVelocity * timeStep;

    //Check if in bounds
    if( xVelocity > 0 )
    {
        if( tempX + DODGER_SPRITE_WIDTH > windowWidth )
        {
            //No bounce
            dodger.GetGraphics()->SetDestinationX( windowWidth - DODGER_SPRITE_WIDTH );
            tempX = windowWidth - DODGER_SPRITE_WIDTH;
        }
        else
        {
            dodger.GetGraphics()->SetDestinationX( (int)tempX );
            xPos = tempX;
        }
    }

    else if( xVelocity < 0 ) 
    {
        if( tempX < 0 )
        {
            dodger.GetGraphics()->SetDestinationX( 0 );
            tempX = 0;
        }
        else
        {
            dodger.GetGraphics()->SetDestinationX( (int)tempX );
            xPos = tempX;
        }
    }

    else
        dodger.GetGraphics()->SetDestinationX( tempX );

    if( yVelocity > 0 )
    {
        if( tempY + DODGER_SPRITE_WIDTH > windowHeight )
        {
            //No bounce
            dodger.GetGraphics()->SetDestinationY( windowHeight - DODGER_SPRITE_HEIGHT );
            tempY = windowHeight - DODGER_SPRITE_HEIGHT;
        }
        else
        {
            dodger.GetGraphics()->SetDestinationY( (int)tempY );
            yPos = tempY;
        }
    }

    else if( yVelocity < 0 ) 
    {
        if( tempY < 0 )
        {
            dodger.GetGraphics()->SetDestinationY( 0 );
            tempY = 0;
        }
        else
        {
            dodger.GetGraphics()->SetDestinationY( (int)tempY );
            yPos = tempY;
        }
    }

    else
        dodger.GetGraphics()->SetDestinationY( tempY );

    dodger.GetGraphics()->SetDestinationY( yPos );
}

void Dodger_Physics::SetXVelocity( bool xVel )
{
    if( xVel == POSITIVE_MOVEMENT )
    {
        if( xVelocity < DODGER_MAX_VELOCITY )
            xVelocity += DODGER_ACCEL_RATE;
        else
            xVelocity = DODGER_MAX_VELOCITY;
    }
    else
    {
        if( xVelocity > -DODGER_MAX_VELOCITY )
            xVelocity -= DODGER_ACCEL_RATE;
        else
            xVelocity = -DODGER_MAX_VELOCITY;
    }
}

void Dodger_Physics::SetYVelocity( bool yVel )
{
    if( yVel == POSITIVE_MOVEMENT )
    {
        if( yVelocity < DODGER_MAX_VELOCITY )
            yVelocity += DODGER_ACCEL_RATE;
    }
    else
    {
        if( yVelocity > -DODGER_MAX_VELOCITY )
            yVelocity -= DODGER_ACCEL_RATE;
    }
}