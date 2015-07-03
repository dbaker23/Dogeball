#include "Game_Sounds.h"

#include <stdio.h>
#include <random>

Game_Sounds::Game_Sounds()
{
    //Init SDL_Mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        printf( "SDL_Mixer not initialized! Error: %s\n", Mix_GetError() );

    surface = Mix_LoadMUS( SURFACE_PATH );
    if( surface == NULL )
        printf( "FAILED to load music. Error: %s\n", Mix_GetError() );

    //Different barks
    bark[ 0 ] = Mix_LoadWAV( BARK_PATH_0 );
    bark[ 1 ] = Mix_LoadWAV( BARK_PATH_1 );
    bark[ 2 ] = Mix_LoadWAV( BARK_PATH_2 );
    bark[ 3 ] = Mix_LoadWAV( BARK_PATH_3 );
    bark[ 4 ] = Mix_LoadWAV( BARK_PATH_4 );
    bark[ 5 ] = Mix_LoadWAV( BARK_PATH_5 );

    //Check em all
    for( int i = 0; i < BARK_AMOUNT; i++ )
    {
        if( bark[ i ] == NULL )
            printf( "FAILED to load bark. Error: %s\n", Mix_GetError() );
    }

    death = Mix_LoadWAV( DEATH_PATH );
    if( death == NULL )
        printf( "FAILED to load death. Error: %s\n", Mix_GetError() );
    menuSelect = Mix_LoadWAV( MENU_SEL_PATH );
    if( menuSelect == NULL )
        printf( "FAILED to load Menu Select. Error: %s\n", Mix_GetError() );
    bodyHit = Mix_LoadWAV( BODY_HIT_PATH );
    if( bodyHit == NULL )
        printf( "FAILED to load body hit. Error: %s\n", Mix_GetError() );
    swordSwing = Mix_LoadWAV( SWORDSWING_PATH );
    if( swordSwing == NULL )
        printf( "FAILED to load sword swing. Error: %s\n", Mix_GetError() );

    musicEnabled = ENABLED;
    soundEnabled = ENABLED;
}

Game_Sounds::~Game_Sounds()
{
    Mix_FreeMusic( surface );
    for( int i = 0; i < BARK_AMOUNT; i++ )
        Mix_FreeChunk( bark[ i ] );
    Mix_FreeChunk( death );
    Mix_FreeChunk( menuSelect );
    Mix_FreeChunk( bodyHit );
    Mix_FreeChunk( swordSwing );

    surface = NULL;
    for( int i = 0; i < BARK_AMOUNT; i++ )
        bark[ i ] = NULL;
    death = NULL;
    menuSelect = NULL;
    bodyHit = NULL;
    swordSwing = NULL;

    Mix_Quit();
}

void Game_Sounds::PlayBark()
{
    if( soundEnabled )
    {
        int select = rand() % BARK_AMOUNT;
        switch( select )
        {
        case 0:
            Mix_PlayChannel( -1, bark[ 0 ], 0 );
            break;
        case 1:
            Mix_PlayChannel( -1, bark[ 1 ], 0 );
            break;
        case 2:
            Mix_PlayChannel( -1, bark[ 2 ], 0 );
            break;
        case 3:
            Mix_PlayChannel( -1, bark[ 3 ], 0 );
            break;
        case 4:
            Mix_PlayChannel( -1, bark[ 4 ], 0 );
            break;
        case 5:
            Mix_PlayChannel( -1, bark[ 5 ], 0 );
            break;
        case 6:
            Mix_PlayChannel( -1, bark[ 6 ], 0 );
            break;
        }
    }
}

void Game_Sounds::PlayAttack()
{
    if( soundEnabled )
    {
        Mix_PlayChannel( -1, swordSwing, 0 );
        Mix_PlayChannel( -1, bodyHit, 0 );
    }
}

void Game_Sounds::StopMusic()
{
    //IF already stopped do nothing.
    if( Mix_PlayingMusic() != 0 )
        Mix_HaltMusic();
}

void Game_Sounds::PauseMusic()
{
    if( Mix_PlayingMusic() != 0 )
        Mix_PauseMusic();
}