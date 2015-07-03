#pragma once
#include "Doge.h"
#include "Game_Timer.h"
#include "Game_Sounds.h"
#include <vector>

#define MAX_RAND_SIZE      100	//Maximum random number that can be returned from rand(), for spawning the doggies
#define MAX_RAND_DIR         7	//Number of directions doggies can fly 0-7
#define RAND_SPAWN_BIG      80	//Some arbitrary numbers that will spawn corresponding doges if returned by rand() in cpp file
#define RAND_SPAWN_MED      40
#define RAND_SPAWN_SML      20
#define RAND_SPAWN_ARR       0
#define DOGE_BIG_HIT_OFFSET 32	//the + or - amount of deadzone for the hit detection, since I used rectangles and they are circular
#define DOGE_MED_HIT_OFFSET 29
#define DOGE_SML_HIT_OFFSET 11
#define DOGE_ARR_HIT_OFFSET 64

//Spawns, updates, and moves the doges on screen
class Doge_Handler
{
public:
    /*=====================================================
    *Constructor: Initialize the list and renderer

    *Parameters:
        gRenderer: the renderer being used everywhere
        sounds: for making the bark sound
    =======================================================*/
    Doge_Handler( Game_Renderer* gRenderer, Game_Sounds* sounds );
    ~Doge_Handler();

    /*=====================================================
    *Update: go through the vector and update all the doges

    *Parameters:
        timeStep: the amount of time between frames
        mouse: the rectangle for testing the mouse
        leftClick: tells if the mouse was clicked or not
    =======================================================*/
    void Update( float timeStep, SDL_Rect mouse, bool leftClick );

    /*=====================================================
    *Draw: draw all doggies to screen.

    *Parameters:
    =======================================================*/
    void Draw();

    /*=====================================================
    *IsCollision: check sprite boxes then check pixel level
        if the character is in one of the doge's sprite boxes

    *Parameters:
        a: the character's sprite box
    =======================================================*/
    bool IsCollision( const SDL_Rect a );

    bool SingleCollision( const SDL_Rect a, const SDL_Rect b );

    /*=====================================================
    *ClearDoges: clear the list and start from scratch

    *Parameters:
    =======================================================*/
    void ClearDoges() { dogeList.clear(); }

private:
    /*=====================================================
    *CheckBounds: check if the doge is outside of the window

    *Parameters:
        doge: the rectangle where the dog is
    =======================================================*/
    bool IsInBounds( SDL_Rect doge, Doge_Fly_Direction dir );

    const unsigned int MAX_ONSCREEN;
    Game_Renderer*     renderer;
    Game_Sounds*       barker;       //For making the bark sounds
    std::vector<Doge*> dogeList;     //empty list of Doges
};

