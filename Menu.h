#pragma once
#include "Main_Menu_Graphics.h"
#include "Player_Select_Graphics.h"
#include "Options_Menu_Graphics.h"
#include "How2Play_Graphics.h"
#include "High_Score_Graphics.h"
#include "Menu_Input.h"
#include "Game_Sounds.h"

enum Menu_ID
{
    MENU_ID_MAIN            = 0, //Arbitrary values for the menus
    MENU_ID_PLAYER_SELECT   = 1,
    MENU_ID_OPTIONS         = 2,
    MENU_ID_H2P             = 3,
    MENU_ID_VIEW_HIGH_SCORE = 4,
    MENU_ID_PLAY_DODGE      = 5,
    MENU_ID_PLAY_ATTACK     = 6
};

enum Input_Direction
{
    KEY_LEFT,	//key inputs and directions within the menus
    KEY_RIGHT,
    KEY_UP,
    KEY_DOWN,
    KEY_ENTER,
    KEY_BACK,
    KEY_EXIT,
    KEY_NULL
};

//One of three menus
class Menu
{
public:
	//Setup each menu with its own set of objects and specific ID
    Menu( Menu_ID ID, Game_Renderer* gRenderer, Game_Sounds* sounds, Game_Text* gameText );
    ~Menu();

    Component_Menu_Graphics* GetGraphics()      { return graphics; }
    Menu_Input*              GetInputObject()   { return input; }
    Input_Direction          GetInputDir()      { return inputDir; }
    Game_Sounds*             GetSounds()        { return gameSounds; }
    void SetInputDir( Input_Direction newDir )  { inputDir = newDir; }

private:
    Component_Menu_Graphics* graphics;    //Draw menu
    Menu_Input*              input;       //User input
    Input_Direction          inputDir;    //Which way the user is trying to go
    Game_Sounds*             gameSounds;
};

