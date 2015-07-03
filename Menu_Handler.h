#pragma once
#include "Menu.h"

#define MENU_AMOUNT 5

//Hold an array of every menu and do menu stuff
class Menu_Handler
{
public:
    /*=====================================================
    *Constructor: initialize all menus in the menu array

    *Parameters:
        gRenderer: renderer from main loop
    =======================================================*/
    Menu_Handler( Game_Renderer* gRenderer, Game_Sounds* sounds, Game_Text* gameText );
    ~Menu_Handler();

    /*=====================================================
    *HandleInput: Using updated keystrokes, move the indicator
        to the appropriate place on the menu

    *Parameters:
        e: the keystrokes being done
    =======================================================*/
    void HandleInput( const SDL_Event& e );

    /*=====================================================
    *UpdateInput: Update keyboard and mouse input for cur menu

    *Parameters:
    =======================================================*/
    void UpdateInput();

    /*=====================================================
    *UpdateGraphics: Update the position of the indicator

    *Parameters:
    =======================================================*/
    void UpdateGraphics();

    /*=====================================================
    *DrawGraphics: where the drawing actually takes place.

    *Parameters:
    =======================================================*/
    void DrawGraphics();

    int GetOpenMenu()            { return openMenu; }
    void SetOpenMenu( int menu ) { openMenu = menu; }

private:
    Menu*        menus[ MENU_AMOUNT ];   //hold all menus
    int          openMenu;               //The menu open at the moment
};

