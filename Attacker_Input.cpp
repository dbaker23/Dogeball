#include "Attacker_Input.h"
#include "Game_Actor.h"

Attacker_Input::Attacker_Input()
{
    SDL_SetRelativeMouseMode( SDL_TRUE );
    xMouse = 0;
    yMouse = 0;
}


Attacker_Input::~Attacker_Input()
{
}

void Attacker_Input::HandleMouse( const SDL_Event& e )
{
	//Check if the mouse has a button down
    if( e.type == SDL_MOUSEBUTTONDOWN )
		//If it's the left click, set left click to true, if anything else, fuck it
        if( e.button.button == SDL_BUTTON_LEFT )
            leftClick = true;
	//Check if the mouse has a released button
    if( e.type == SDL_MOUSEBUTTONUP )
		//If it's the left click, release it
        if( e.button.button == SDL_BUTTON_LEFT )
            leftClick = false;
	//Retrieve the x and y position of the mouse from the system
    SDL_GetMouseState( &xMouse, &yMouse );
}

void Attacker_Input::Update( Game_Actor& attacker )
{
    //If no movement input, change state to standing
    if( !keys[ left ] && !keys[ right ] && !keys[ up ] && !keys[ down ] &&
        !keys[ a ]    && !keys[ d ]     && !keys[ w ]  && !keys[ s ] )
        attacker.ChangeState( new Hero_Standing() );

    //If any movement input, change state to running
    else if( keys[ left ] || keys[ right ] || keys[ up ] || keys[ down ] ||
             keys[ a ]    || keys[ d ]     || keys[ w ]  || keys[ s ] )
    {
        attacker.ChangeState( new Hero_Running() );

        //Move left
        if( keys[ left ] || keys[ a ] )
        {
            attacker.GetPhysics()->SetXVelocity( NEGATIVE_MOVEMENT );
        }

        //Move up
        if( keys[ up ] || keys[ w ] )
        {
            attacker.GetPhysics()->SetYVelocity( NEGATIVE_MOVEMENT );
        }

        //Move down
        if( keys[ down ] || keys[ s ] )
        {
            attacker.GetPhysics()->SetYVelocity( POSITIVE_MOVEMENT );
        }

        //Move right
        if( keys[ right ] || keys[ d ] )
        {
            attacker.GetPhysics()->SetXVelocity( POSITIVE_MOVEMENT );
        }
    }

    //Clear x or y velocities if directions not pushed
    if( !keys[ left ] && !keys[ right ] && !keys[ a ] && !keys[ d ] )
        attacker.GetPhysics()->ClearXVelocity();
    if( !keys[ up ] && !keys[ down ] && !keys[ w ] && !keys[ s ] )
        attacker.GetPhysics()->ClearYVelocity();
}
