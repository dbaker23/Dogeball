#pragma once
#include <SDL.h>
#include "Doge_Handler.h"
#include "Game_Actor.h"
#include "Game_Renderer.h"
#include "Game_Sounds.h"
#include "Game_Timer.h"
#include "Game_Text.h"
#include "Menu_Handler.h"

//Where the game loop happens: logic, updating, drawing
class Main_Loop
{
public:
    /*=====================================================
    *Constructor: Create objects and allocate pointers before entering the main loop

    *Parameters:
    =======================================================*/
    Main_Loop();
    ~Main_Loop();

    /*=====================================================
    *Game_Loop: logic, updating, and drawing will happen until the user quits

    *Parameters: 
    =======================================================*/
    void GameLoop();

    /*=====================================================
    *MenuLoop: Logic, updating, and drawing for the menus

    *Parameters: 
    =======================================================*/
    void MenuLoop();

    /*=====================================================
    *Run: interaction between both game states will happen

    *Parameters: 
    =======================================================*/
    void Run();

private:
    bool           quit;        //Game runs until quitting
    float          timeStep;    //Frame-independent movement
    int            character;   //which character will spawn

    Doge_Handler*  dogeHandler; //for updating the list of doges
    Game_Actor*    hero;        //Dodger or attacker
    Game_Renderer* renderer;    //Updates the screen
    Game_Sounds*   gameSounds;  //Sounds and music played here.
    Game_Timer     stepTimer;   //used for movement and anything involving time
    Game_Text*     gameText;    //For showing the user's score and other stuff.
    Menu_Handler*  menuHandler;   //Handle each menu individually.
    SDL_Event      gameEvent;	//SDL tracks things happening in the system, and this tracks it
};

