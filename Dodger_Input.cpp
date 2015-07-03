#include "Dodger_Input.h"
#include "Dodger_States.h"
#include "Game_Actor.h"

#include <iostream> //Debugging
using namespace std;

Dodger_Input::Dodger_Input()
{
}


Dodger_Input::~Dodger_Input()
{
}

//Same as attacker input minus the mouse input
void Dodger_Input::Update( Game_Actor& dodger )
{
    //If no movement input, change state to standing
    if( !keys[ left ] && !keys[ right ] && !keys[ up ] && !keys[ down ] &&
        !keys[ a ]    && !keys[ d ]     && !keys[ w ]  && !keys[ s ] )
        dodger.ChangeState( new Hero_Standing() );

    //If any movement input, change state to running
    else if( keys[ left ] || keys[ right ] || keys[ up ] || keys[ down ] ||
             keys[ a ]    || keys[ d ]     || keys[ w ]  || keys[ s ] )
    {
        dodger.ChangeState( new Hero_Running() );

        //Move left
        if( keys[ left ] || keys[ a ] )
        {
            dodger.GetPhysics()->SetXVelocity( NEGATIVE_MOVEMENT );
        }

        //Move up
        if( keys[ up ] || keys[ w ] )
        {
            dodger.GetPhysics()->SetYVelocity( NEGATIVE_MOVEMENT );
        }

        //Move down
        if( keys[ down ] || keys[ s ] )
        {
            dodger.GetPhysics()->SetYVelocity( POSITIVE_MOVEMENT );
        }

        //Move right
        if( keys[ right ] || keys[ d ] )
        {
            dodger.GetPhysics()->SetXVelocity( POSITIVE_MOVEMENT );
        }
    }

    //Clear x or y velocities if directions not pushed
    if( !keys[ left ] && !keys[ right ] && !keys[ a ] && !keys[ d ] )
        dodger.GetPhysics()->ClearXVelocity();
    if( !keys[ up ] && !keys[ down ] && !keys[ w ] && !keys[ s ] )
        dodger.GetPhysics()->ClearYVelocity();
}