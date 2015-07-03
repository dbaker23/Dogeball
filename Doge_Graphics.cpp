#include "Doge_Graphics.h"
#include "Doge.h"

Doge_Graphics::Doge_Graphics( Game_Renderer* gRenderer, Doge_Size dogSize ) :
    Component_Character_Graphics( gRenderer ),
    bigSprite( gRenderer->LoadTexture( DOGE_BIG_SPRITE_PATH ), DOGE_BIG_WIDTH, DOGE_BIG_HEIGHT ),
    medSprite( gRenderer->LoadTexture( DOGE_MED_SPRITE_PATH ), DOGE_MED_WIDTH, DOGE_MED_HEIGHT ),
    smlSprite( gRenderer->LoadTexture( DOGE_SML_SPRITE_PATH ), DOGE_SML_WIDTH, DOGE_SML_HEIGHT ),
    arrSprite( gRenderer->LoadTexture( DOGE_ARR_SPRITE_PATH ), DOGE_ARR_WIDTH, DOGE_ARR_HEIGHT )
{
    switch ( dogSize )
    {
    case DOGE_SIZE_BIG:
        displaySprite = &bigSprite;
        destination.w = DOGE_BIG_WIDTH;
        destination.h = DOGE_BIG_HEIGHT;
        break;

    case DOGE_SIZE_MEDIUM:
        displaySprite = &medSprite;
        destination.w = DOGE_MED_WIDTH;
        destination.h = DOGE_MED_HEIGHT;
        break;

    case DOGE_SIZE_SMALL:
        displaySprite = &smlSprite;
        destination.w = DOGE_SML_WIDTH;
        destination.h = DOGE_SML_HEIGHT;
        break;

    case DOGE_SIZE_ARROW:
        displaySprite = &arrSprite;
        destination.w = DOGE_ARR_WIDTH;
        destination.h = DOGE_ARR_HEIGHT;
        break;
    }

    destination.x = 0;
    destination.y = 0;
}

Doge_Graphics::~Doge_Graphics()
{
}

void Doge_Graphics::Update( Doge& doge )
{
}