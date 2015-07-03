#include "Attacker_Physics.h"
#include "Game_Actor.h"

Attacker_Physics::Attacker_Physics()
{
    xVelocity = 0;
    yVelocity = 0;
    tempX     = HERO_START_X;
    tempY     = HERO_START_Y;
    xPos      = HERO_START_X;
    yPos      = HERO_START_Y;
    xTile     = (int)HERO_START_X / TILE_SIZE;	//Tiles only for checking valid movement, unused for this game
    yTile     = (int)HERO_START_Y / TILE_SIZE;
}


Attacker_Physics::~Attacker_Physics()
{
}

void Attacker_Physics::Update( Game_Actor& attacker, float timeStep, int windowHeight, int windowWidth )
{
	//Calculate the new x and y positions, but hold them temporarily for testing
    tempX += xVelocity * timeStep;
    tempY += yVelocity * timeStep;

    //Check if moving right (positive)
    if( xVelocity > 0 )
    {
		//If the temporary position + width of the sprite is out of bounds
        if( tempX + ATTACKER_SPRITE_WIDTH > windowWidth )
        {
            //subtract the amount of sprite out of bounds and set it butt-up against the side of the screen
            attacker.GetGraphics()->SetDestinationX( windowWidth - ATTACKER_SPRITE_WIDTH );
			//Remember to set the temporary X position to the new position for when the loop goes through again
            tempX = windowWidth - ATTACKER_SPRITE_WIDTH;
        }
		//If within bounds
        else
        {
			//Set equal to the temporary position
            attacker.GetGraphics()->SetDestinationX( (int)tempX );
            xPos = tempX;
        }
    }
	//Check if moving left (negative)
    else if( xVelocity < 0 ) 
    {
        if( tempX < 0 )
        {
            attacker.GetGraphics()->SetDestinationX( 0 );
            tempX = 0;
        }
        else
        {
            attacker.GetGraphics()->SetDestinationX( (int)tempX );
            xPos = tempX;
        }
    }

	//If no movement, set it to the same position
    else
        attacker.GetGraphics()->SetDestinationX( tempX );

	//Do the same checks and repositioning with the Y values
    if( yVelocity > 0 )
    {
        if( tempY + ATTACKER_SPRITE_WIDTH > windowHeight )
        {
            //No bounce
            attacker.GetGraphics()->SetDestinationY( windowHeight - ATTACKER_SPRITE_HEIGHT );
            tempY = windowHeight - ATTACKER_SPRITE_HEIGHT;
        }
        else
        {
            attacker.GetGraphics()->SetDestinationY( (int)tempY );
            yPos = tempY;
        }
    }

    else if( yVelocity < 0 ) 
    {
        if( tempY < 0 )
        {
            attacker.GetGraphics()->SetDestinationY( 0 );
            tempY = 0;
        }
        else
        {
            attacker.GetGraphics()->SetDestinationY( (int)tempY );
            yPos = tempY;
        }
    }

    else
        attacker.GetGraphics()->SetDestinationY( tempY );

    attacker.GetGraphics()->SetDestinationY( yPos );
}

void Attacker_Physics::SetXVelocity( bool xVel )
{
	//Find out if the player is moving left or right on the screen
	//Positive movement is right
    if( xVel == POSITIVE_MOVEMENT )
    {
		//check if not max velocity, if not, increase by the acceleration rate
        if( xVelocity < ATTACKER_MAX_VELOCITY )
            xVelocity += ATTACKER_ACCEL_RATE;
		//If max V, then set to max V
        else
            xVelocity = ATTACKER_MAX_VELOCITY;
    }
	//Negative movement is left
    else
    {
        if( xVelocity > -ATTACKER_MAX_VELOCITY )
            xVelocity -= ATTACKER_ACCEL_RATE;
        else
            xVelocity = -ATTACKER_MAX_VELOCITY;
    }
}

//Same as X velocity
void Attacker_Physics::SetYVelocity( bool yVel )
{
    if( yVel == POSITIVE_MOVEMENT )
    {
        if( yVelocity < ATTACKER_MAX_VELOCITY )
            yVelocity += ATTACKER_ACCEL_RATE;
    }
    else
    {
        if( yVelocity > -ATTACKER_MAX_VELOCITY )
            yVelocity -= ATTACKER_ACCEL_RATE;
    }
}
