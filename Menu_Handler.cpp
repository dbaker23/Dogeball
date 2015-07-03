#include "Menu_Handler.h"


Menu_Handler::Menu_Handler( Game_Renderer* gRenderer, Game_Sounds* sounds, Game_Text* gameText )
{
    menus[ MENU_ID_MAIN ]           = new Menu( MENU_ID_MAIN, gRenderer, sounds, gameText );
    menus[ MENU_ID_OPTIONS ]        = new Menu( MENU_ID_OPTIONS, gRenderer, sounds, gameText );
    menus[ MENU_ID_H2P ]            = new Menu( MENU_ID_H2P, gRenderer, sounds, gameText );
    menus[ MENU_ID_PLAYER_SELECT ]  = new Menu( MENU_ID_PLAYER_SELECT, gRenderer, sounds, gameText );
    menus[ MENU_ID_VIEW_HIGH_SCORE ]= new Menu( MENU_ID_VIEW_HIGH_SCORE, gRenderer, sounds, gameText );

    //Gotta know which menu is open
    openMenu = MENU_ID_MAIN;
}

Menu_Handler::~Menu_Handler()
{
}

//Take Input
void Menu_Handler::UpdateInput()
{
    menus[ openMenu ]->GetInputObject()->Update( *menus[ openMenu ] );
}

//Handle Input
void Menu_Handler::HandleInput( const SDL_Event& e )
{
    menus[ openMenu ]->GetInputObject()->HandleInput( e );
}

//Update Graphics
void Menu_Handler::UpdateGraphics()
{
    menus[ openMenu ]->GetGraphics()->Update( *menus[ openMenu ], openMenu );
}

//Draw
void Menu_Handler::DrawGraphics()
{
    menus[ openMenu ]->GetGraphics()->DrawBackground();
    menus[ openMenu ]->GetGraphics()->DrawDoodads();
    menus[ openMenu ]->GetGraphics()->DrawIndicator();
}
