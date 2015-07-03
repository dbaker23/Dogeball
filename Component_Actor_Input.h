#pragma once
#include "Component_Input.h"

class Game_Actor;

//Abstraction of the interface
class Component_Actor_Input : public Component_Input
{
public:
    typedef unsigned int SDLK_t;    //Give proper representation of the keys

    Component_Actor_Input();
    ~Component_Actor_Input();

    /*=====================================================
    *HandleInput: Take in input and designate pressed keys

    *Parameters: 
            e: Player input event
    =======================================================*/
    virtual void HandleInput( const SDL_Event& e );

    //Overridden in child classes.
    virtual void Update( Game_Actor& actor ) = 0;
    virtual void HandleMouse( const SDL_Event& e ) {};
    virtual int GetMouseX() { return 0; }
    virtual int GetMouseY() { return 0; }
    virtual bool GetLeftClick() { return false; }

protected: 
    std::map<int, bool>    keys;    //Handle multiple keypresses

    //user-defined inputs
    //Keyboard
    SDLK_t spaceBar;    //Point to what spacebar does
    SDLK_t tilde;       //Tilde
    SDLK_t left;        //directional keys
    SDLK_t right;
    SDLK_t up;
    SDLK_t down;
    SDLK_t w;           //WASD keys
    SDLK_t a;
    SDLK_t s;
    SDLK_t d;
};

