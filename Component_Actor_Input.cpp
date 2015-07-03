#include "Component_Actor_Input.h"


Component_Actor_Input::Component_Actor_Input()
{
    spaceBar    = SDLK_SPACE;
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


Component_Actor_Input::~Component_Actor_Input()
{
}

void Component_Actor_Input::HandleInput( const SDL_Event& e )
{
	//Keys are held in a boolean map, where pressed is true and not pressed is false

	//Check which keys are down
    if( e.type == SDL_KEYDOWN )
		//SDL will return the keys pressed
        keys[ e.key.keysym.sym ] = true;

	//If keys are up, set them to false
    else if( e.type == SDL_KEYUP )
        keys[ e.key.keysym.sym ] = false;
}