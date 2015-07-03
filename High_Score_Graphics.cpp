#include "High_Score_Graphics.h"
#include "Menu.h"

High_Score_Graphics::High_Score_Graphics( Game_Renderer* gRenderer, Game_Text* gameText ) :
    Component_Menu_Graphics( gRenderer )
{
    background       = new Sprite( gRenderer->LoadTexture( HIGHSCORES_BACKGROUND_PATH ), gRenderer->GetScreenWidth(), gRenderer->GetScreenHeight() );
    text             = gameText;

    for( int i = 0; i < TEXT_SLOTS; i++ )
    {
        scoreDest[ i ].h = SCORE_HEIGHT;
        scoreDest[ i ].w = SCORE_WIDTH;
        scoreDest[ i ].x = HIGH_SCORE_X;
    }
    scoreDest[ 0 ].y = HIGH_SCORE_1;
    scoreDest[ 1 ].y = HIGH_SCORE_2;
    scoreDest[ 2 ].y = HIGH_SCORE_3;
    scoreDest[ 3 ].y = HIGH_SCORE_4;
    scoreDest[ 4 ].y = HIGH_SCORE_5;

    SDL_Color textColor = { 255, 255, 255 };
    scores = text->GetScores();
    scoreTextures[ 0 ] = renderer->LoadTTFTexture( to_string( scores[ 0 ] ), textColor, text->GetFont() );
    scoreTextures[ 1 ] = renderer->LoadTTFTexture( to_string( scores[ 1 ] ), textColor, text->GetFont() );
    scoreTextures[ 2 ] = renderer->LoadTTFTexture( to_string( scores[ 2 ] ), textColor, text->GetFont() );
    scoreTextures[ 3 ] = renderer->LoadTTFTexture( to_string( scores[ 3 ] ), textColor, text->GetFont() );
    scoreTextures[ 4 ] = renderer->LoadTTFTexture( to_string( scores[ 4 ] ), textColor, text->GetFont() );
}


High_Score_Graphics::~High_Score_Graphics()
{
}

void High_Score_Graphics::Update( Menu& menu, int& curMenu )
{   
    menu.GetGraphics()->SetIndicatorY( 650 );
    switch( menu.GetInputDir() )
    {
    case KEY_BACK:
        curMenu = MENU_ID_MAIN;
        break;
    case KEY_ENTER:
        curMenu = MENU_ID_MAIN;
        break;
    }
    
    for( int i = 0; i < TEXT_SLOTS; i++ ) {
        SDL_DestroyTexture( scoreTextures[ i ] );
        scoreTextures[ i ] = NULL;
    }
    SDL_Color textColor = { 255, 255, 255 };
    scores = text->GetScores();
	for( int i = 0; i < TEXT_SLOTS; i++ ) {
		scoreTextures[ i ] = renderer->LoadTTFTexture( to_string( scores[ i ] ), textColor, text->GetFont() );
	}
}

void High_Score_Graphics::DrawDoodads()
{
    for( int i = 0; i < TEXT_SLOTS; i++ )
    {
        renderer->DrawScreen( scoreTextures[ i ], &scoreDest[ i ], NULL );
    }
}