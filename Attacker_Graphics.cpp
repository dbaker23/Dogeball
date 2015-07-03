#include "Attacker_Graphics.h"
#include "Game_Actor.h"

//Constructor, load up textures, set texture dimensions for the sprite and its containing rectangle, and setup the mouse textures
Attacker_Graphics::Attacker_Graphics( Game_Renderer* gRenderer ) :
    Component_Character_Graphics( gRenderer ),
    attackerSprite( gRenderer->LoadTexture( ATTACKER_SPRITE_PATH ),     ATTACKER_SPRITE_WIDTH, ATTACKER_SPRITE_HEIGHT ),
    mouseFloat(     gRenderer->LoadTexture( CURSOR_FLOAT_SPRITE_PATH),  CURSOR_WIDTH,          CURSOR_HEIGHT ),
    mouseHover(     gRenderer->LoadTexture( CURSOR_HOVER_SPRITE_PATH ), CURSOR_WIDTH,          CURSOR_HEIGHT )
{
	//Set the attacker's sprite to the initial one
    displaySprite = &attackerSprite;
	//Set the attacker's containing rectangle up
    destination.h = ATTACKER_SPRITE_HEIGHT;
    destination.w = ATTACKER_SPRITE_WIDTH;
    destination.x = (int)HERO_START_X;
    destination.y = (int)HERO_START_Y;

	//Set the mouse's containing rectangle
    mouseDest.h   = CURSOR_HEIGHT;
    mouseDest.w   = CURSOR_WIDTH;
    mouseDest.x   = 0;
    mouseDest.y   = 0;
}


Attacker_Graphics::~Attacker_Graphics(void)
{
}

void Attacker_Graphics::Update( Game_Actor& attacker, const float timeStep, bool collision )
{
	//Collect the mouse's x and y locations
    mouseDest.x = attacker.GetInputObject()->GetMouseX();
    mouseDest.y = attacker.GetInputObject()->GetMouseY();

	//If the mouse is colliding with a doge, set it to the hover sprite
    if( collision )
        mouseDisplay = &mouseHover;
	//otherwise, leave it as the normal pointer
    else
        mouseDisplay = &mouseFloat;
}

void Attacker_Graphics::DrawMouse()
{
	//Send to draw the mouse at &mouseDest with the dimensions of the &mouseFloat.getclip, same dimensions for hover and float
    renderer->DrawScreen( mouseDisplay->GetTexture(), &mouseDest, &mouseFloat.GetClip() );
}