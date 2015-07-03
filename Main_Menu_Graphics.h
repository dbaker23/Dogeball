#pragma once
#include "component_menu_graphics.h"

#define MAIN_MENU_TOP_Y     127
#define MAIN_MENU_BOT_Y     335
#define MAIN_MENU_OPTIONS_Y 200
#define MAIN_MENU_H2P_Y     280
#define MAIN_MENU_YPOSITIONS  4
#define MAIN_MENU_BACKGROUND_PATH "Menu_Sprites/Main_Menu_Background.png"

class Main_Menu_Graphics : public Component_Menu_Graphics
{
public:
    Main_Menu_Graphics( Game_Renderer* gRenderer );
    ~Main_Menu_Graphics();

    /*=====================================================
    *Update: change destination, alter sprites shown, etc

    *Parameters:
        menu: the menu being updated
        curMenu: currently open menu to change
    =======================================================*/
    virtual void Update( Menu& menu, int& curMenu );

    /*=====================================================
    *DrawDoodads: Draw all the static non-background sprites

    *Parameters:
    =======================================================*/
    virtual void DrawDoodads();

private:
    int yPosition[ MAIN_MENU_YPOSITIONS ]; //Where the indicator is on-screen
    int y;                                 //The y position
};

