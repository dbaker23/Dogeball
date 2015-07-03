#pragma once
#include "Component_Graphics.h"

class Component_Character_Graphics : public Component_Graphics
{
public:
    
    /*=====================================================
    *Constructor: setup pointer to the renderer being used, 
        initialize destination for sprite

    *Parameters:
        gRenderer: renderer from main loop
    =======================================================*/
    Component_Character_Graphics( Game_Renderer* gRenderer );
    ~Component_Character_Graphics();

    //Overridden in children
    virtual void Update( Game_Actor& hero, const float timeStep, bool collision ) {};
    virtual void Update( Game_Actor& hero, const float timeStep ) {};
    virtual void Update( Doge& doge ) {};
    virtual void DrawMouse() {};
    virtual SDL_Rect GetMouseDest() { return destination; }

    /*=====================================================
    *Draw: Show each frame of animation

    *Parameters:
    =======================================================*/
    virtual void Draw();

    virtual void        SetDestinationX( int x ) { destination.x = x; }
    virtual void        SetDestinationY( int y ) { destination.y = y; }
    virtual SDL_Rect    GetDestination()         { return destination; }
   
protected:
    Game_Renderer* renderer;        //For drawing the sprite
    Sprite*        displaySprite;   //which sprite will be shown.
    Sprite*        mouseDisplay;    //Which mouse sprite will be shown
    SDL_Rect       destination;     //Where the sprite will be shown
};

