#pragma once
#include "Component_Character_Graphics.h"
#include "Doge.h"

#define DOGE_BIG_WIDTH        128
#define DOGE_BIG_HEIGHT       128
#define DOGE_BIG_SPRITE_PATH  "Doge_Sprites/Doge_Big.png"
#define DOGE_MED_WIDTH        96
#define DOGE_MED_HEIGHT       96
#define DOGE_MED_SPRITE_PATH  "Doge_Sprites/Doge_Med.png"
#define DOGE_SML_WIDTH        64
#define DOGE_SML_HEIGHT       64
#define DOGE_SML_SPRITE_PATH  "Doge_Sprites/Doge_Sml.png"
#define DOGE_ARR_WIDTH        160
#define DOGE_ARR_HEIGHT       128
#define DOGE_ARR_SPRITE_PATH  "Doge_Sprites/Doge_Arrow_R.png"       

class Doge_Graphics : public Component_Character_Graphics
{
public:
    /*=====================================================
    *Constructor: setup pointer to the renderer being used, 
        initialize destination for sprite

    *Parameters:
        gRenderer: renderer from main loop
    =======================================================*/
    Doge_Graphics( Game_Renderer* gRenderer, Doge_Size dogSize );
    ~Doge_Graphics();

    /*=====================================================
    *Update: update new position of sprite

    *Parameters:
        doge: the doge being referred to
    =======================================================*/
    virtual void Update( Doge& doge );

private:
    Sprite      bigSprite;
    Sprite      medSprite;
    Sprite      smlSprite;
    Sprite      arrSprite;
};

