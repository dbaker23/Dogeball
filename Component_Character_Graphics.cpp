#include "Component_Character_Graphics.h"

//Set pointers to the only rendering object used throughout the whole project
Component_Character_Graphics::Component_Character_Graphics( Game_Renderer* gRenderer )
{
    renderer = gRenderer;
}

Component_Character_Graphics::~Component_Character_Graphics()
{
}

void Component_Character_Graphics::Draw()
{
	//Draw the character from get texture at &destination with the dimensions of getclip()
    renderer->DrawScreen( displaySprite->GetTexture(), &destination, &displaySprite->GetClip() );
}