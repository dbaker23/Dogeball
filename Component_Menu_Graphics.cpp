#include "Component_Menu_Graphics.h"

//constructor
Component_Menu_Graphics::Component_Menu_Graphics( Game_Renderer* gRenderer )
{
    renderer            = gRenderer;
    backgroundDest.x    = 0;							//Set the containing rectangle for the background ie: entire screen
    backgroundDest.y    = 0;
    backgroundDest.h    = gRenderer->GetScreenHeight();
    backgroundDest.w    = gRenderer->GetScreenWidth();
    indicatorDest.x     = INDICATOR_START_X;			//Set containing rectangle for the indicator in the menus
    indicatorDest.y     = INDICATOR_START_Y;
    indicatorDest.h     = INDICATOR_HEIGHT;
    indicatorDest.w     = INDICATOR_WIDTH;

	//Setup sprites with the image from file and preprocessor values
    indicator           = new Sprite( gRenderer->LoadTexture( INDICATOR_SPRITE_PATH ), INDICATOR_WIDTH, INDICATOR_HEIGHT );
    checkOn             = new Sprite( gRenderer->LoadTexture( CHECK_ON_SPRITE_PATH ),  CHECK_ON_WIDTH,  CHECK_ON_HEIGHT );
    checkOff            = new Sprite( gRenderer->LoadTexture( CHECK_OFF_SPRITE_PATH ), CHECK_OFF_WIDTH, CHECK_OFF_HEIGHT );
}

Component_Menu_Graphics::~Component_Menu_Graphics()
{
}

void Component_Menu_Graphics::DrawBackground()
{
	//Same as all the other draws
    renderer->DrawScreen( background->GetTexture(), &backgroundDest, &background->GetClip() );
}

void Component_Menu_Graphics::DrawIndicator()
{
    renderer->DrawScreen( indicator->GetTexture(), &indicatorDest, &indicator->GetClip() );
}
