#pragma once
#include "Component_Character_Graphics.h"

#define DODGER_SPRITE_WIDTH     53
#define DODGER_SPRITE_HEIGHT    64
#define DODGER_SPRITE_PATH      "Dodger_Sprites/Dodger_Standing.png"

//Dodger character's graphics component
class Dodger_Graphics : public Component_Character_Graphics
{
public:
    /*=====================================================
    *Constructor: setup pointer to the renderer being used, 
        initialize destination for sprite

    *Parameters:
        gRenderer: renderer from main loop
    =======================================================*/
    Dodger_Graphics( Game_Renderer* gRenderer );
    ~Dodger_Graphics();

    /*=====================================================
    *Constructor: setup pointer to the renderer being used, 
        initialize destination for sprite

    *Parameters:
        dodger: the character
        timeStep: how much time elapsed for time-based animation
    =======================================================*/
    virtual void Update( Game_Actor& dodger, const float timeStep, bool collision );

private:
    Sprite dodgerSprite;   //Sprite that is shown
};

