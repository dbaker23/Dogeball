#include "How2Play_Graphics.h"
#include "Menu.h"

How2Play_Graphics::How2Play_Graphics( Game_Renderer* gRenderer) :
    Component_Menu_Graphics( gRenderer )
{
    background = new Sprite( gRenderer->LoadTexture( HOWTOPLAY_BACKGROUND_PATH ), gRenderer->GetScreenWidth(), gRenderer->GetScreenHeight() );
}


How2Play_Graphics::~How2Play_Graphics()
{
}

void How2Play_Graphics::Update( Menu& menu, int& curMenu )
{
    menu.GetGraphics()->SetIndicatorX( 15 );
    menu.GetGraphics()->SetIndicatorY( 70 );
    switch( menu.GetInputDir() )
    {
    case KEY_BACK:
        curMenu = MENU_ID_MAIN;
        break;
    case KEY_ENTER:
        curMenu = MENU_ID_MAIN;
        break;
    }
}

void How2Play_Graphics::DrawDoodads()
{
    //Unused
}