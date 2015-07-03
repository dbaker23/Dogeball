#include "Sprite.h"

Sprite::Sprite() : 
    spriteHeight( DEFAULT_NUM ),
    spriteWidth( DEFAULT_NUM ),
    sprite()
{
}

Sprite::Sprite( SDL_Texture* spriteSheet, const int spriteWidth, const int spriteHeight ) :
    spriteHeight( spriteHeight ),
    spriteWidth( spriteWidth ),
    sprite( spriteSheet )
{
    clip    = SDL_Rect();
    clip.h  = spriteHeight;
    clip.w  = spriteWidth;
    clip.x  = 0;
    clip.y  = 0;
}

Sprite::~Sprite()
{
}