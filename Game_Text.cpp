#include "Game_Text.h"
#include <stdio.h>
#include <stdlib.h>

//qsort
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

Game_Text::Game_Text( Game_Renderer* gRenderer )
{
	//Set up text destinations 
    renderer        = gRenderer;
    destination.h   = TEXT_HEIGHT;
    destination.w   = TEXT_WIDTH;
    
	//Start positioning at the farthest to the left number
    destination.x   = ( gRenderer->GetScreenWidth() / 2 ) - ( TEXT_WIDTH / 2 );
    destination.y   = 0;
    font			= TTF_OpenFont( TEXT_PATH, 30 );

	//init
	for( int i = 0; i < SORT_SLOTS; i++ )
		scores[ i ] = 0;

	//Read in and save the scores
	string line;
    ifstream savedTimes( SAVE_PATH );
    if( savedTimes.is_open() ) {
		int i = 0;
        while( getline( savedTimes, line ) ) {
			//Save scores as ints in scores
			scores[ i ] = atoi( line.c_str() );
			if( scores[ i ] < 0 )
				scores[ i ] = 0;
            i++;
        }
    } else
        cout << "Unable to open saved times" << endl;
	savedTimes.close();
	
	//sort
	int time = scoreTimer.GetTicks() / 1000;
	int temp[ TEXT_SLOTS ];
	int count = SORT_SLOTS - 1;
	scores[ 5 ] = time;
	qsort( scores, SORT_SLOTS, sizeof(int), compare ); 
	//rewrite scores in inverse
	for( int i = 0; i < TEXT_SLOTS; i++ ) {
		temp[ i ] = scores[ count ];
		count--;
	}
	for( int i = 0; i < TEXT_SLOTS; i++ )
		scores[ i ] = temp[ i ];
}

Game_Text::~Game_Text()
{
    SDL_DestroyTexture( fontTexture );
    fontTexture = NULL;
	
	//Write scores to file
	ofstream outStream( SAVE_PATH );
	if( outStream.is_open() ) {
		for( int i = 0; i < TEXT_SLOTS; i++ )
			outStream << to_string( scores[ i ] ) << "\n";
	}
}

void Game_Text::UpdateScore()
{
    std::string time = std::to_string( scoreTimer.GetTicks() / 1000 );
    SDL_Color textColor = { 255, 0, 0 };
    
    SDL_DestroyTexture( fontTexture );
    fontTexture = NULL;

    fontTexture = renderer->LoadTTFTexture( time, textColor, font );
}

void Game_Text::DisplayScore()
{
    renderer->DrawScreen( fontTexture, &destination, NULL );
}

void Game_Text::SaveScore()
{
    int time = scoreTimer.GetTicks() / 1000;
	int temp[ TEXT_SLOTS ];
	int count = SORT_SLOTS - 1;
	scores[ 5 ] = time;
	qsort( scores, SORT_SLOTS, sizeof(int), compare ); 
	//rewrite scores in inverse
	for( int i = 0; i < TEXT_SLOTS; i++ ) {
		temp[ i ] = scores[ count ];
		count--;
	}
	for( int i = 0; i < TEXT_SLOTS; i++ )
		scores[ i ] = temp[ i ];
	scores[ SORT_SLOTS - 1 ] = 0;
}


void Game_Text::PingScore()
{
    string time =  to_string( scoreTimer.GetTicks() / 1000 );
    char const *pchar = time.c_str();
    SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_INFORMATION, "Your Score!", pchar, NULL ); 
}