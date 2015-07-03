#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Game_Renderer.h"
#include "Game_Timer.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#define TEXT_HEIGHT 50	//In pixels
#define TEXT_WIDTH  40
#define TEXT_PATH   "Game_Font/Chiaro.ttf"
#define TEXT_SLOTS  5	//how many actual scores are displayed
#define SORT_SLOTS  6	//add in a new score and sort it
#define SAVE_PATH   "Saved_Scores/scores.txt"

//Where the outputting of text will happen
class Game_Text
{
public:
    /*=====================================================
    *Constructor: Initialize the font

    *Parameters:
    =======================================================*/
    Game_Text( Game_Renderer* gRenderer );
    ~Game_Text();

    /*=====================================================
    *UpdateScore: update logic behind showing the score.

    *Parameters:
    =======================================================*/
    void UpdateScore();

    /*=====================================================
    *DisplayScore: show the score (time alive)

    *Parameters:
    =======================================================*/
    void DisplayScore();

    /*=====================================================
    *SaveScore: check score against top 5 on a text file, and
        write it to the score array if it betters one of them

    *Parameters:
    =======================================================*/
    void SaveScore();

    /*=====================================================
    *PingScore: show dialogue box for player's score after game

    *Parameters:
    =======================================================*/
    void PingScore();

    TTF_Font* GetFont()		{ return font; }
	int*	  GetScores()	{ return scores; }

    void StartTimer() { scoreTimer.Start(); }
    void StopTimer()  { scoreTimer.Stop(); }
    void PauseTimer() { scoreTimer.Pause(); }

private:
    SDL_Rect       destination;					//Where the numbers are drawn to
    Game_Renderer* renderer;					//For rendering the font
    SDL_Texture*   fontTexture;					//For displaying
    Game_Timer     scoreTimer;					//Counting the seconds the player survives.
    TTF_Font*      font;
	int			   scores[ SORT_SLOTS ];		//reading in and saving top 5 scores
};

