#pragma once
#include "component_menu_graphics.h"

#define CHARACTER_SELECT_BACKGROUND_PATH "Menu_Sprites/Character_Select_Menu_Background.png"

#define CHARSEL_Y           380
#define CHARSEL_X_RIGHT     600
#define CHARSEL_X_LEFT      150

class Player_Select_Graphics : public Component_Menu_Graphics
{
public:
    Player_Select_Graphics( Game_Renderer* gRenderer );
    ~Player_Select_Graphics();

    /*=====================================================
    *Update: change destination, alter sprites shown, etc

    *Parameters:
        menu: the menu being updated
    =======================================================*/
    virtual void Update( Menu& menu, int& curMenu );

    /*=====================================================
    *DrawDoodads: Draw all the static non-background sprites

    *Parameters:
    =======================================================*/
    virtual void DrawDoodads();

private:

};

