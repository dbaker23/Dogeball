#pragma once
#include "Component_Actor_Input.h"

//Input handler for the attacker
class Attacker_Input : public Component_Actor_Input
{
public:
    Attacker_Input();
    ~Attacker_Input();

    /*=====================================================
    *Execute: Depending on input, the state and/or graphics will change

    *Parameters: 
            object: Pass in the hero to change state and graphics
    =======================================================*/
    virtual void Update( Game_Actor& attacker );

    /*=====================================================
    *HandleMouse: update the mouse on the screen

    *Parameters: 
        e = events of the mouse
    =======================================================*/
    virtual void HandleMouse( const SDL_Event& e );

    virtual int GetMouseX()     { return xMouse; }
    virtual int GetMouseY()     { return yMouse; }
    virtual bool GetLeftClick() { return leftClick; }

private:
    int     xMouse;             //x and y positions of the mouse
    int     yMouse;     
    bool    leftClick;          //Find if left click happened
};

