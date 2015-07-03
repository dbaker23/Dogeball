#include "Dodger_States.h"
#include "Game_Actor.h"


void Hero_Standing::EnterState( Game_Actor& hero )
{
    hero.SetEState( ACTOR_STATE_STANDING );
}

void Hero_Running::EnterState( Game_Actor& hero )
{
    hero.SetEState( ACTOR_STATE_RUNNING );
}