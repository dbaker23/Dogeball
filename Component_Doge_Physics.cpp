#include "Component_Doge_Physics.h"
#include "Doge.h"

Component_Doge_Physics::Component_Doge_Physics( Doge& doge, float speed )
{
    xVelocity = speed;
    yVelocity = speed;
    tempX     = 0;
    tempY     = 0;
    xPos      = doge.GetGraphics()->GetDestination().x; //Initial x and y for the doges will be handled by the spawner
    yPos      = doge.GetGraphics()->GetDestination().y;
    xTile     = 0;        
    yTile     = 0;
}


Component_Doge_Physics::~Component_Doge_Physics()
{
}

void Component_Doge_Physics::Update( Doge& doge, float timeStep )
{
    //branch depending on direction flying
    //x and y velocity differences don't matter
    switch( doge.GetDirection() )
    {
    case DOGE_FLY_R:
        xPos += xVelocity * timeStep;
        doge.GetGraphics()->SetDestinationX( xPos );
        break;
    
    case DOGE_FLY_RD:
        xPos += xVelocity * timeStep;				//First update the velocities of the doges
        yPos += xVelocity * timeStep;
        doge.GetGraphics()->SetDestinationX( xPos ); //then update where they will be drawn
        doge.GetGraphics()->SetDestinationY( yPos );
        break;
    
    case DOGE_FLY_RU:
        xPos += xVelocity * timeStep;
        yPos -= xVelocity * timeStep;
        doge.GetGraphics()->SetDestinationX( xPos );
        doge.GetGraphics()->SetDestinationY( yPos );
        break;
    
    case DOGE_FLY_D:
        yPos += xVelocity * timeStep;
        doge.GetGraphics()->SetDestinationY( yPos );
        break;
    
    case DOGE_FLY_U:
        yPos -= xVelocity * timeStep;
        doge.GetGraphics()->SetDestinationY( yPos );
        break;
    
    case DOGE_FLY_L:
        xPos -= xVelocity * timeStep;
        doge.GetGraphics()->SetDestinationX( xPos );
        break;
    
    case DOGE_FLY_LD:
        xPos -= xVelocity * timeStep;
        yPos += xVelocity * timeStep;
        doge.GetGraphics()->SetDestinationX( xPos );
        doge.GetGraphics()->SetDestinationY( yPos );
        break;
    
    case DOGE_FLY_LU:
        xPos -= xVelocity * timeStep;
        yPos -= xVelocity * timeStep;
        doge.GetGraphics()->SetDestinationX( xPos );
        doge.GetGraphics()->SetDestinationY( yPos );
        break;
    
    default:
        doge.GetGraphics()->SetDestinationX( 0 );	//If for some reason there's no movement, default to the top left corner
        doge.GetGraphics()->SetDestinationY( 0 );
        break;
    }
}