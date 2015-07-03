#include "Menu.h"


Menu::Menu( Menu_ID ID, Game_Renderer* gRenderer, Game_Sounds* sounds, Game_Text* gameText )
{
    switch( ID )
    {
    case MENU_ID_MAIN:
        graphics = new Main_Menu_Graphics( gRenderer );
        break;
    case MENU_ID_OPTIONS:
        graphics = new Options_Menu_Graphics( gRenderer );
        break;
    case MENU_ID_PLAYER_SELECT:
        graphics = new Player_Select_Graphics( gRenderer );
        break;
    case MENU_ID_VIEW_HIGH_SCORE:
        graphics = new High_Score_Graphics( gRenderer, gameText );
        break;
    case MENU_ID_H2P:
        graphics = new How2Play_Graphics( gRenderer );
        break;
    }

    input = new Menu_Input();
    gameSounds = sounds;
}

Menu::~Menu()
{
}