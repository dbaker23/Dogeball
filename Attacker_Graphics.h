#pragma once
#include "Component_Character_Graphics.h"

//Attacker
#define ATTACKER_SPRITE_WIDTH     55	//Attacker character's sprite width
#define ATTACKER_SPRITE_HEIGHT    64	// "		"			"	  height
#define ATTACKER_SPRITE_PATH      "Attacker_Sprites/Attacker_Standing.png"	//Place in files where the attacker character's sprite is located

//Mouse
#define CURSOR_FLOAT_SPRITE_PATH "Attacker_Sprites/Cursor.png"
#define CURSOR_HOVER_SPRITE_PATH "Attacker_Sprites/Cursor_Hover.png"
#define CURSOR_WIDTH             14
#define CURSOR_HEIGHT            25

class Attacker_Graphics : public Component_Character_Graphics
{
public:
    /*=====================================================
    *Constructor: setup pointer to the renderer being used, 
        initialize destination for sprite

    *Parameters:
        gRenderer: renderer from main loop
    =======================================================*/
    Attacker_Graphics( Game_Renderer* gRenderer );
    ~Attacker_Graphics();

    /*=====================================================
    *Update: update the sprite's position

    *Parameters:
        dodger: the character
        timeStep: how much time elapsed for time-based animation
    =======================================================*/
    virtual void Update( Game_Actor& attacker, const float timeStep, bool collision );

    /*=====================================================
    *DrawMouse: draw the mouse based on where it is

    *Parameters:
    =======================================================*/
    virtual void DrawMouse();

    virtual SDL_Rect GetMouseDest() { return mouseDest; }


private:
    SDL_Rect mouseDest;        //Where the mouse is drawn to
    Sprite   attackerSprite;   //Sprite that is shown
    Sprite   mouseFloat;       //float = floating around, regular mouse pointer
    Sprite   mouseHover;       //hover = over a clickable object
};

