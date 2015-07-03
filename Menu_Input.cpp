#include "Menu_Input.h"
#include "Menu.h"

Menu_Input::Menu_Input()
{
    spaceBar    = SDLK_SPACE;
    enter       = SDLK_RETURN;
    backSpace   = SDLK_BACKSPACE;
    tilde       = SDLK_BACKQUOTE;
    left        = SDLK_LEFT;
    right       = SDLK_RIGHT;
    up          = SDLK_UP;
    down        = SDLK_DOWN;
    w           = SDLK_w;
    a           = SDLK_a;
    s           = SDLK_s;
    d           = SDLK_d;
}


Menu_Input::~Menu_Input()
{
}

void Menu_Input::HandleInput( const SDL_Event& e )
{
    if( e.type == SDL_KEYDOWN ) 
        keys[ e.key.keysym.sym ] = true;
    else if( e.type == SDL_KEYUP )
        keys[ e.key.keysym.sym ] = false;
}

void Menu_Input::Update( Menu& menu )
{
    if( keys[ right ] || keys[ d ] )
        menu.SetInputDir( KEY_RIGHT );
    else if( keys[ down ] || keys[ s ] )
        menu.SetInputDir( KEY_DOWN );
    else if( keys[ left ] || keys[ a ] )
        menu.SetInputDir( KEY_LEFT );
    else if( keys[ up ] || keys[ w ] )
        menu.SetInputDir( KEY_UP );
    else if( keys[ spaceBar ] || keys[ enter ] )
        menu.SetInputDir( KEY_ENTER );
    else if( keys[ backSpace ] )
        menu.SetInputDir( KEY_BACK );
    else
        menu.SetInputDir( KEY_NULL );
    keys.clear();
}