#pragma once
#include <SDL_mixer.h>

#define SURFACE_PATH    "Sounds_Music/Dimrain_Surface.wav"	//Music path
#define BARK_AMOUNT     6
#define BARK_PATH_0     "Sounds_Music/Doge_Bark_0.wav"		//the different doge barks
#define BARK_PATH_1     "Sounds_Music/Doge_Bark_1.wav"
#define BARK_PATH_2     "Sounds_Music/Doge_Bark_2.wav"
#define BARK_PATH_3     "Sounds_Music/Doge_Bark_3.wav"
#define BARK_PATH_4     "Sounds_Music/Doge_Bark_4.wav"
#define BARK_PATH_5     "Sounds_Music/Doge_Bark_5.wav"
#define DEATH_PATH      "Sounds_Music/Character_Death.wav"	//Character death
#define MENU_SEL_PATH   "Sounds_Music/Menu_Select.wav"		//Selection sound in menu
#define BODY_HIT_PATH   "Sounds_Music/Body_Hit.wav"			//Hit detection sound
#define SWORDSWING_PATH "Sounds_Music/Sword_Swing.wav"		//Sword swing sound for attacker, when clicking on doges

#define ENABLED         true	//supposed to be true and false for readability, but never used, faster to set on or off to passed in value
#define DISABLED        true

//class for playing music and sounds
class Game_Sounds
{
public:
    /*=====================================================
    *Constructor: Load all audio paths

    *Parameters:
    =======================================================*/
    Game_Sounds();
    ~Game_Sounds();

    //Simple sounds
    void PlayDeath()    { if( soundEnabled ) Mix_PlayChannel( -1, death, 0 ); }
    //Randomize what bark will play
    void PlayBark();
    //Play menu sounds.
    void PlayMenuSel()  { if( soundEnabled ) Mix_PlayChannel( -1, menuSelect, 0 ); }
    //Play music
    void PlayMusic()    { if( musicEnabled ) Mix_PlayMusic( surface, -1 ); }
    //Stop music
    void StopMusic();
    //Pause Music
    void PauseMusic();
    //play attack
    void PlayAttack();

    void SetMusic( bool onOff ) { musicEnabled = onOff; }	//enable or disable sounds and music
    void SetSound( bool onOff ) { soundEnabled = onOff; }

private:
    bool soundEnabled;
    bool musicEnabled;
    //Moosic
    Mix_Music* surface;             //Surface by Dimrain47
    //Soonds
    Mix_Chunk* bark[ BARK_AMOUNT ]; //When the arrow spawns
    Mix_Chunk* death;               //When the player loses
    Mix_Chunk* menuSelect;          //selecting a menu option
    Mix_Chunk* bodyHit;             //Played after sword swing
    Mix_Chunk* swordSwing;          //Played when attacker attacks
};

