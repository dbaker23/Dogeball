#pragma once
#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_mouse.h>
#include <map>

class Game_Actor;      //Forward declaration to prevent looping dependencies

//class Component_Input: base interface for player input 
class Component_Input
{
public:
    virtual ~Component_Input() {}
    virtual void HandleInput( const SDL_Event& e ) = 0;		//Find out if the key is up or down
    virtual void HandleMouse( const SDL_Event& e ) = 0;		//Find out where the mouse is by x and y, find out if the mouse has been clicked
    virtual void Update( Game_Actor& object ) = 0;			//Depending on keys pressed, change the character's state to correspond and update movement if any
    virtual int GetMouseX() = 0;							//Returns the x coord of the mouse
    virtual int GetMouseY() = 0;							//Returns the y coord of the mouse
    virtual bool GetLeftClick() = 0;						//Returns if the mouse's left click is down
};