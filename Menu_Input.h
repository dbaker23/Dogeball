#pragma once
#include <SDL_events.h>
#include <map>

class Menu;

class Menu_Input
{
public:
    typedef unsigned int SDLK_t;    //Give proper representation of the keys

    Menu_Input();
    ~Menu_Input();

    /*=====================================================
    *HandleInput: update which keys were pressed.

    *Parameters: 
            e: event logger for telling which keys are pressed
    =======================================================*/
    void HandleInput( const SDL_Event& e );

    /*=====================================================
    *Update: Depending on input, the state and/or graphics will change

    *Parameters: 
            object: Pass in the hero to change state and graphics
    =======================================================*/
    void Update( Menu& menu );

	/*=====================================================
    *HandleMouse: update the mouse on the screen

    *Parameters: 
        e = events of the mouse
    =======================================================*/
    virtual void HandleMouse( const SDL_Event& e );

	void HandleMouse( const SDL_Event& e ) {};
    int GetMouseX() { return 0; }
    int GetMouseY() { return 0; }
    bool GetLeftClick() { return false; }

private:
    std::map<int, bool>    keys;    //Handle multiple keypresses

	//Mouse
	int     xMouse;             //x and y positions of the mouse
    int     yMouse;     
    bool    leftClick;          //Find if left click happened

    //user-defined inputs
    //Keyboard
    SDLK_t spaceBar;    //Point to what spacebar does
    SDLK_t enter;       
    SDLK_t backSpace;
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

