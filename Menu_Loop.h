#pragma once
#include "Game_Renderer.h"
#include "Game_Sounds.h"
#include "Main_Loop.h"


//#define FRAME_RATE      60   //cap framerate for menus
#define TICKS_PER_FRAME 1000/FRAME_RATE

//Loop until out of menus and into the game
class Menu_Loop
{
public:
    /*=====================================================
    *Constructor: Initialize all menus

    *Parameters: 
    =======================================================*/
    Menu_Loop( Game_Renderer* gRenderer, Game_Sounds* sounds );
    ~Menu_Loop();

    /*=====================================================
    *MenuLoop: like mainloop, where menus are updated and drawn

    *Parameters: 
    =======================================================*/
    void MenuLoop();

    Menu_Handler* GetMenuHandler() { return menuHandler; }

private:

    Game_Renderer* renderer;      //Draw the window
    Game_Sounds*   gameSounds;    //Sounds and music
    bool           quit;          //loop until user stops or goes into the game
    SDL_Event      gameEvent;     //Polling input
    Main_Loop*     gameLoop;    
};

