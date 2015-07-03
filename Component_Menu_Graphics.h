#pragma once
#include "Sprite.h"

#define DOODAD_MAX 5
#define INDICATOR_START_X      300
#define INDICATOR_START_Y      127
#define INDICATOR_WIDTH        64
#define INDICATOR_HEIGHT       64
#define INDICATOR_SPRITE_PATH  "Doge_Sprites/Doge_Sml.png"
#define CHECK_ON_WIDTH         64
#define CHECK_ON_HEIGHT        56
#define CHECK_ON_SPRITE_PATH   "Menu_Sprites/Checkbox_On.png"
#define CHECK_OFF_WIDTH        51
#define CHECK_OFF_HEIGHT       52
#define CHECK_OFF_SPRITE_PATH  "Menu_Sprites/Checkbox_Off.png"

class Menu;

//Draw the specific menu
class Component_Menu_Graphics
{
public:
    /*=====================================================
    *Constructor: setup pointer to the renderer being used, 
        initialize destination for sprite

    *Parameters:
        gRenderer: renderer from main loop
    =======================================================*/
    Component_Menu_Graphics( Game_Renderer* gRenderer );
    ~Component_Menu_Graphics();

    /*=====================================================
    *DrawBackground: draw the static background for the specific menu

    *Parameters:
    =======================================================*/
    void DrawBackground();

    /*=====================================================
    *DrawIndicator: draw where the indicator is relative to the background

    *Parameters:
    =======================================================*/
    void DrawIndicator();

    //Override
    virtual void DrawDoodads() = 0;

    //override
    virtual void Update( Menu &menu, int& curMenu ) = 0;
    
    //Getters and setters
    void SetIndicatorX( int x ) { indicatorDest.x = x; }
    void SetIndicatorY( int y ) { indicatorDest.y = y; }
    int  GetIndicatorX()        { return indicatorDest.x; }
    int  GetIndicatorY()        { return indicatorDest.y; }

private:
    SDL_Rect       backgroundDest;          //Where the background is by rectangle
    SDL_Rect       indicatorDest;           //Where the selector icon is by rectangle

protected:
    Game_Renderer* renderer;
    Sprite*        background;              //Static elements of the background, basically an image
    Sprite*        indicator;               //Where the selector in the menu is
    Sprite*        checkOn;                 //Check-box with check
    Sprite*        checkOff;                //check-box without check
    Sprite*        doodads[ DOODAD_MAX ];   //Other static-stuff/non-static stuff in menu that may or may not need updating (checkboxes)
};

