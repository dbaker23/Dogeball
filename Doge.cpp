#include "Doge.h"
#include "Doge_Graphics.h"
#include "Doge_Physics_Big.h"
#include "Doge_Physics_Med.h"
#include "Doge_Physics_Sml.h"
#include "Doge_Physics_Arr.h"

//Constructor, build the doges
Doge::Doge( Doge_Size size, Doge_Fly_Direction dir, Game_Renderer* renderer ) : 
    dogeSize( size ),		//Constant for the doge's size defined by doge handler
    flyDirection( dir )		//Constant for doge's flying direction defined by handler
{
	//Setup graphics objects according to the sizes
    switch( dogeSize )
    {
    case DOGE_SIZE_BIG:
        this->graphics = new Doge_Graphics( renderer, DOGE_SIZE_BIG );
        break;

    case DOGE_SIZE_MEDIUM:
        this->graphics = new Doge_Graphics( renderer, DOGE_SIZE_MEDIUM );
        break;

    case DOGE_SIZE_SMALL:
        this->graphics = new Doge_Graphics( renderer, DOGE_SIZE_SMALL );
        break;

    case DOGE_SIZE_ARROW:
        this->graphics = new Doge_Graphics( renderer, DOGE_SIZE_ARROW );
        break;
    }

    //Set starting positions
    switch( dir )
    {

	//Depnding on the direction flown, either the X or Y can be randomized, make sure they start off screen though
    case DOGE_FLY_R:
        this->graphics->SetDestinationX( 0 );
        this->graphics->SetDestinationY( rand() % renderer->GetScreenHeight() - DOGE_BIG_HEIGHT );
        break;
    case DOGE_FLY_RD:
        this->graphics->SetDestinationX( 0 );
        this->graphics->SetDestinationY( 0 );
        break;
    case DOGE_FLY_RU:
        this->graphics->SetDestinationX( 0 );
        this->graphics->SetDestinationY( rand() % renderer->GetScreenHeight() - 1 );
        break;
    case DOGE_FLY_D:
        this->graphics->SetDestinationX( rand() % renderer->GetScreenWidth() );
        this->graphics->SetDestinationY( 0 );
        break;
    case DOGE_FLY_LD:
        this->graphics->SetDestinationX( renderer->GetScreenWidth() - 1 );
        this->graphics->SetDestinationY( 0 );
        break;
    case DOGE_FLY_L:
        this->graphics->SetDestinationX( renderer->GetScreenWidth() - 1 );
        this->graphics->SetDestinationY( rand() % renderer->GetScreenHeight() - DOGE_BIG_HEIGHT );
        break;
    case DOGE_FLY_LU:
        this->graphics->SetDestinationX( renderer->GetScreenWidth() - 1 );
        this->graphics->SetDestinationY( rand() % renderer->GetScreenHeight() );
        break;
    case DOGE_FLY_U:
        this->graphics->SetDestinationX( rand() % renderer->GetScreenWidth() - DOGE_SML_WIDTH );
        this->graphics->SetDestinationY( renderer->GetScreenHeight() );
        break;
    }

	//Finally, setup physics objects for each doge will move at a different speed
    switch( dogeSize )
    {
    case DOGE_SIZE_BIG:
        this->physics  = new Doge_Physics_Big( *this );
        break;

    case DOGE_SIZE_MEDIUM:
        this->physics  = new Doge_Physics_Med( *this );
        break;

    case DOGE_SIZE_SMALL:
        this->physics  = new Doge_Physics_Sml( *this );
        break;

    case DOGE_SIZE_ARROW:
        this->physics  = new Doge_Physics_Arr( *this );
        break;
    }
}

//Overloaded constructor, where starting x and y are predefined
Doge::Doge( Doge_Size size, Doge_Fly_Direction dir, Game_Renderer* renderer, int startx, int starty ) : 
    dogeSize( size ),
    flyDirection( dir )
{
    switch( dogeSize )
    {
    case DOGE_SIZE_BIG:
        this->graphics = new Doge_Graphics( renderer, DOGE_SIZE_BIG );
        break;

    case DOGE_SIZE_MEDIUM:
        this->graphics = new Doge_Graphics( renderer, DOGE_SIZE_MEDIUM );
        break;

    case DOGE_SIZE_SMALL:
        this->graphics = new Doge_Graphics( renderer, DOGE_SIZE_SMALL );
        break;

    case DOGE_SIZE_ARROW:
        this->graphics = new Doge_Graphics( renderer, DOGE_SIZE_ARROW );
        break;
    }

    this->graphics->SetDestinationX( startx );
    this->graphics->SetDestinationY( starty );
    
    switch( dogeSize )
    {
    case DOGE_SIZE_BIG:
        this->physics  = new Doge_Physics_Big( *this );
        break;

    case DOGE_SIZE_MEDIUM:
        this->physics  = new Doge_Physics_Med( *this );
        break;

    case DOGE_SIZE_SMALL:
        this->physics  = new Doge_Physics_Sml( *this );
        break;

    case DOGE_SIZE_ARROW:
        this->physics  = new Doge_Physics_Arr( *this );
        break;
    }
}


Doge::~Doge()
{
	//Cleanup
    delete graphics;
    delete physics;

    graphics = NULL;
    physics = NULL;
}
