#pragma once
#include "Component_Actor_Input.h"
#include "Dodger_Physics.h"

//class Player_Input_Handler: Take in player input and do stuff with it
class Dodger_Input : public Component_Actor_Input
{
public:
    Dodger_Input();
    ~Dodger_Input();

    /*=====================================================
    *Execute: Depending on input, the state and/or graphics will change

    *Parameters: 
            object: Pass in the hero to change state and graphics
    =======================================================*/
    virtual void Update( Game_Actor& dodger );

    //unused, dodger has no attack
    virtual int GetMouseX(){ return 0; }
    virtual int GetMouseY(){ return 0; }
private:

};