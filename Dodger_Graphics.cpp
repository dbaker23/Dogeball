#include "Dodger_Graphics.h"
#include "Game_Actor.h"

Dodger_Graphics::Dodger_Graphics( Game_Renderer* gRenderer ) :
    Component_Character_Graphics( gRenderer ),
    dodgerSprite(  gRenderer->LoadTexture( DODGER_SPRITE_PATH ), DODGER_SPRITE_WIDTH, DODGER_SPRITE_HEIGHT )
{
    displaySprite = &dodgerSprite;
    destination.h = DODGER_SPRITE_HEIGHT;
    destination.w = DODGER_SPRITE_WIDTH;
    destination.x = (int)HERO_START_X;
    destination.y = (int)HERO_START_Y;
}


Dodger_Graphics::~Dodger_Graphics()
{
}

void Dodger_Graphics::Update( Game_Actor& hero, const float timeStep, bool collision )
{
    ////
    //Add animation here later
    //
}
