#include "Main_Menu_Graphics.h"
#include "Menu.h"

Main_Menu_Graphics::Main_Menu_Graphics( Game_Renderer* gRenderer ) :
    Component_Menu_Graphics( gRenderer )
{
    background     = new Sprite( gRenderer->LoadTexture( MAIN_MENU_BACKGROUND_PATH ), gRenderer->GetScreenWidth(), gRenderer->GetScreenHeight() );
    yPosition[ 0 ] = MAIN_MENU_TOP_Y;
    yPosition[ 1 ] = MAIN_MENU_OPTIONS_Y;
    yPosition[ 2 ] = MAIN_MENU_H2P_Y;
    yPosition[ 3 ] = MAIN_MENU_BOT_Y;
    y              = 0;
}

Main_Menu_Graphics::~Main_Menu_Graphics()
{
}

void Main_Menu_Graphics::Update( Menu& menu, int& curMenu )
{
    switch( menu.GetInputDir() )
    {
    case KEY_DOWN:
        if( menu.GetGraphics()->GetIndicatorY() != MAIN_MENU_BOT_Y )
        {
            y++;
            menu.GetGraphics()->SetIndicatorY( yPosition[ y ] );
            menu.GetSounds()->PlayMenuSel();
        }
        break;
    
    case KEY_UP:
        if( menu.GetGraphics()->GetIndicatorY() != MAIN_MENU_TOP_Y )
        {
            y--;
            menu.GetGraphics()->SetIndicatorY( yPosition[ y ] );
            menu.GetSounds()->PlayMenuSel();
        }
        break;

    case KEY_ENTER:
        switch( yPosition[ y ] )
        {
        case MAIN_MENU_TOP_Y:
            curMenu = MENU_ID_PLAYER_SELECT;
            menu.GetSounds()->PlayMenuSel();
            break;
        case MAIN_MENU_OPTIONS_Y:
            curMenu = MENU_ID_OPTIONS;
            menu.GetSounds()->PlayMenuSel();
            break;
        case MAIN_MENU_H2P_Y:
            curMenu = MENU_ID_H2P;
            menu.GetSounds()->PlayMenuSel();
            break;
        case MAIN_MENU_BOT_Y:
            curMenu = MENU_ID_VIEW_HIGH_SCORE;
            menu.GetSounds()->PlayMenuSel();
            break;
        }
        break;
    }
}

void Main_Menu_Graphics::DrawDoodads()
{
    //No doodads
}
