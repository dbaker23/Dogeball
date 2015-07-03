#include "Game_Actor.h"


Game_Actor::Game_Actor()
{
}


Game_Actor::~Game_Actor()
{
    delete state;
    delete input;
    delete physics;
    delete graphics;

    state = NULL;
    input = NULL;
    physics = NULL;
    graphics = NULL;
}

void Game_Actor::ChangeState( Component_Actor_State* newState )
{
    state = newState;
}

void Game_Actor::SpawnDodger( Game_Renderer* gRenderer )
{
    this->graphics = new Dodger_Graphics( gRenderer );
    this->input    = new Dodger_Input();
    this->physics  = new Dodger_Physics();
    this->state    = new Hero_Standing();
}

void Game_Actor::SpawnAttacker(  Game_Renderer* gRenderer )
{
    this->graphics = new Attacker_Graphics( gRenderer );
    this->input    = new Attacker_Input();
    this->physics  = new Attacker_Physics();
    this->state    = new Hero_Standing();
}