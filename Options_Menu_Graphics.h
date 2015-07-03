#pragma once
#include "component_menu_graphics.h"

//Vertical positioning of elements
#define OPTIONS_MENU_BACKGROUND_PATH "Menu_Sprites/Options_Menu_Background.png"
#define OPTIONS_YPOSITIONS           3
#define OPTIONS_TOP_Y                50
#define OPTIONS_MUSIC_Y              200
#define OPTIONS_BOT_Y                400

//Doodads
#define OPTIONS_DD_AMOUNT            2
#define CHECK_BOX_XPOS               300
#define DD_MUSIC                     0
#define DD_SOUNDS                    1
#define CHECK_ON                     true;
#define CHECK_OFF                    false

class Options_Menu_Graphics : public Component_Menu_Graphics
{
public:
    Options_Menu_Graphics( Game_Renderer* gRenderer );
    ~Options_Menu_Graphics();

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
    int      yPosition[ OPTIONS_YPOSITIONS ]; //Where the indicator is on-screen
    SDL_Rect ddPosition[ OPTIONS_DD_AMOUNT ]; //Where the check boxes and shit will be   
    int      y;                               //The y position
    bool     music;                         //Music on/off
    bool     sounds;                        //sounds on/off
};

