#pragma once
#include "Component_Menu_Graphics.h"

#define HOWTOPLAY_BACKGROUND_PATH "Menu_Sprites/Howtoplay_Menu_Background.png"

class How2Play_Graphics : public Component_Menu_Graphics
{
public:
    How2Play_Graphics( Game_Renderer* gRenderer );
    ~How2Play_Graphics();

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
};

