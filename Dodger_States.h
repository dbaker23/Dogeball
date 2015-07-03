#pragma once
#include "Component_Actor_State.h"

//not moving
class Hero_Standing : public Component_Actor_State
{
public:
    virtual void EnterState( Game_Actor& hero );
};

//Moving
class Hero_Running : public Component_Actor_State
{
public:
    virtual void EnterState( Game_Actor& hero );
};
