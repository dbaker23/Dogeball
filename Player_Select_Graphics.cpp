#include "Player_Select_Graphics.h"
#include "Menu.h"

Player_Select_Graphics::Player_Select_Graphics( Game_Renderer* gRenderer ) :
    Component_Menu_Graphics( gRenderer )
{
    background = new Sprite( gRenderer->LoadTexture( CHARACTER_SELECT_BACKGROUND_PATH ), gRenderer->GetScreenWidth(), gRenderer->GetScreenHeight() );
}


Player_Select_Graphics::~Player_Select_Graphics()
{
}

void Player_Select_Graphics::Update( Menu& menu, int& curMenu )
{
    if( menu.GetGraphics()->GetIndicatorX() != CHARSEL_X_LEFT && menu.GetGraphics()->GetIndicatorX() != CHARSEL_X_RIGHT )
        menu.GetGraphics()->SetIndicatorX( CHARSEL_X_LEFT );
    if( menu.GetGraphics()->GetIndicatorY() != CHARSEL_Y )
        menu.GetGraphics()->SetIndicatorY( CHARSEL_Y );

    switch( menu.GetInputDir() )
    {
    case KEY_LEFT:
        if( menu.GetGraphics()->GetIndicatorX() != CHARSEL_X_LEFT )
        {
            menu.GetGraphics()->SetIndicatorX( CHARSEL_X_LEFT );
            menu.GetSounds()->PlayMenuSel();
        }
        break;
    
    case KEY_RIGHT:
        if( menu.GetGraphics()->GetIndicatorX() != CHARSEL_X_RIGHT )
        {
            menu.GetGraphics()->SetIndicatorX( CHARSEL_X_RIGHT );
            menu.GetSounds()->PlayMenuSel();
        }
        break;

    case KEY_BACK:
        curMenu = MENU_ID_MAIN;
        break;

    case KEY_ENTER:
        if( menu.GetGraphics()->GetIndicatorX() == CHARSEL_X_RIGHT )
        {
            curMenu = MENU_ID_PLAY_ATTACK;
        }
        else
        {
            curMenu = MENU_ID_PLAY_DODGE;
        }
        break;
    }
}

void Player_Select_Graphics::DrawDoodads()
{
}