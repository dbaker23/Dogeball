#pragma once

class Game_Actor;

class Component_Actor_State
{
public:
    virtual ~Component_Actor_State() {}
    virtual void EnterState( Game_Actor& hero ) = 0;
};

