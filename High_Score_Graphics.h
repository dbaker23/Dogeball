#pragma once
#include "component_menu_graphics.h"
#include "Game_Text.h"

#define HIGHSCORES_BACKGROUND_PATH "Menu_Sprites/High_Scores_Menu_Background.png"
#define HIGH_SCORE_1               60	//y positions of the scores
#define HIGH_SCORE_2               150
#define HIGH_SCORE_3               240
#define HIGH_SCORE_4               330
#define HIGH_SCORE_5               420
#define HIGH_SCORE_X               110	//The only x position of all the scores
#define SCORE_HEIGHT               50	//dimensions of the rendered scores
#define SCORE_WIDTH                40

class High_Score_Graphics : public Component_Menu_Graphics
{
public:
    High_Score_Graphics( Game_Renderer* gRenderer, Game_Text* gameText );
    ~High_Score_Graphics();

    /*=====================================================
    *Update: change destination, alter sprites shown, etc

    *Parameters:
        menu: the menu being updated
    =======================================================*/
    virtual void Update( Menu& menu, int& curMenu );

    /*=====================================================
    *DrawDoodads: Draw all the static non-background sprites

    *Parameters:
    =======================================================*/
    virtual void DrawDoodads();

private:
    Game_Text*     text;                //reading in the high scores
    int*           scores;              //For displaying the high scores
    SDL_Texture*   scoreTextures[ 5 ];  //Drawing to the screen
    SDL_Rect       scoreDest[ 5 ];      //Destintations for drawing
};

