#pragma once
#include "Component_Character_Graphics.h"
#include "Component_Doge_Physics.h"
#include <vector>
using namespace std;

class Doge_Graphics;

enum Doge_Size
{
    DOGE_SIZE_BIG,		//Big round
    DOGE_SIZE_MEDIUM,	//middle size
    DOGE_SIZE_SMALL,	//smallest, fastest
    DOGE_SIZE_ARROW		//crazy arrow
};

//Direction which the doge is flying
enum Doge_Fly_Direction
{
    DOGE_FLY_R  = 0,	//right
    DOGE_FLY_RD = 1,	//right down
    DOGE_FLY_RU = 2,	//right up
    DOGE_FLY_D  = 3,	//down
    DOGE_FLY_LD = 4,	//left down
    DOGE_FLY_L  = 5,	//left
    DOGE_FLY_LU = 6,	//left up
    DOGE_FLY_U  = 7		//up
};

class Doge
{
public:
    /*=====================================================
    *Constructor: default randomizer constructor

    *Parameters:
        size: size sml, med, lrg, or arr
        dir: which way it's flying
        renderer: drawing
    =======================================================*/
    Doge( Doge_Size size, Doge_Fly_Direction dir, Game_Renderer* renderer );

    /*=====================================================
    *Overloaded Constructor: specify where the Doge will spawn

    *Parameters:
        size: size sml, med, lrg, or arr
        dir: which way it's flying
        renderer: drawing
        start x/y: coordinates of where it's spawning
    =======================================================*/
    Doge( Doge_Size size, Doge_Fly_Direction dir, Game_Renderer* renderer, int startx, int starty );
    ~Doge();

    Doge_Fly_Direction  GetDirection()  { return flyDirection; }	//Return which way the doge is flying
    Component_Graphics* GetGraphics()   { return graphics; }		//Returns the graphics object being used
    Component_Physics*  GetPhysics()    { return physics; }			//returns the physics object being used
    const Doge_Size     GetSize()       { return dogeSize; }		//returns the size of the doge (big, med, smal, arrow)

private:
    const Doge_Size           dogeSize;      //Tells what size sprite the object contains
    const Doge_Fly_Direction  flyDirection;  //Which way the doge is flying
    Component_Graphics*       graphics;      //Drawing the sprites to the screen
    Component_Physics*        physics;       //Moving across the screen
};

