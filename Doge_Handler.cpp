#include "Doge_Handler.h"

#include <iostream>
using namespace std;

Doge_Handler::Doge_Handler( Game_Renderer* gRenderer, Game_Sounds* sounds ) :
    MAX_ONSCREEN( 20 )
{
    renderer = gRenderer;
    barker   = sounds;
}

Doge_Handler::~Doge_Handler()
{ 
    //Free up the list
    dogeList.clear();
}

    /*=====================================================
    *GetDirection: depending on the random number, a direction
        will be assigned to the doge

    *Parameters:
        dir: the random number 0-7
    =======================================================*/
Doge_Fly_Direction GetDirection( int dir )
{
    switch( dir )
    {
    case 0:
        return DOGE_FLY_R;
    case 1:
        return DOGE_FLY_RD;
    case 2:
        return DOGE_FLY_RU;
    case 3:
        return DOGE_FLY_D;
    case 4:
        return DOGE_FLY_LD;
    case 5:
        return DOGE_FLY_L;
    case 6:
        return DOGE_FLY_LU;
    case 7:
        return DOGE_FLY_U;
    }
    return DOGE_FLY_R;
}

//Checks if the doge is still on the screen, if not, delete it from the vector
bool Doge_Handler::IsInBounds( SDL_Rect doge, Doge_Fly_Direction dir )
{
    switch( dir )
    {
    case DOGE_FLY_R:
        if( doge.x > renderer->GetScreenWidth() )
            return false;
        break;
    case DOGE_FLY_RD:
        if( doge.x > renderer->GetScreenWidth() ||
            doge.y > renderer->GetScreenHeight() )
            return false;
        break;
    case DOGE_FLY_RU:
        if( doge.x > renderer->GetScreenWidth() ||
            doge.y < 0 )
            return false;
        break;
    case DOGE_FLY_D:
        if( doge.y > renderer->GetScreenHeight() )
            return false;
        break;
    case DOGE_FLY_LD:
        if( doge.x + doge.w < 0 ||
            doge.y + doge.h > renderer->GetScreenHeight() )
            return false;
        break;
    case DOGE_FLY_L:
        if( doge.x + doge.w < 0 )
            return false;
        break;
    case DOGE_FLY_LU:
        if( doge.x + doge.w < 0 ||
            doge.y + doge.h < 0 )
            return false;
        break;
    case DOGE_FLY_U:
        if( doge.y + doge.h < 0 )
            return false;
        break;
    }

    //test fails return in bounds
    return true;
}

//Update the vector of doges, including if they were killed
void Doge_Handler::Update( float timeStep, SDL_Rect mouse, bool leftClick )
{
    //If max on screen not met try to spawn another
    if( dogeList.size() < MAX_ONSCREEN )
    {
        int size = rand() % MAX_RAND_SIZE; //0 - MAX_RAND, if the size is one of the predefined accepted numbers, it will spawn, if not, no spawn
        int dir  = rand() % MAX_RAND_DIR; //0-7, only 8 ways to move

        switch( size )
        {
        case RAND_SPAWN_BIG:
            dogeList.push_back( new Doge( DOGE_SIZE_BIG, GetDirection( dir ), renderer ) );
            break;
        case RAND_SPAWN_MED:
            dogeList.push_back( new Doge( DOGE_SIZE_MEDIUM, GetDirection( dir ), renderer ) );
            break;
        case RAND_SPAWN_SML:
            dogeList.push_back( new Doge( DOGE_SIZE_SMALL, GetDirection( dir ), renderer ) );
            break;
        case RAND_SPAWN_ARR:
            barker->PlayBark();
            dogeList.push_back( new Doge( DOGE_SIZE_ARROW, GetDirection( dir ), renderer ) );
            break;
        }
    }

    int count = 0;  //Element counter

    //Update all doges
    for( Doge* doge : dogeList )
    {
		//Check if in bounds
        if( IsInBounds( doge->GetGraphics()->GetDestination(), doge->GetDirection() ) )
            doge->GetPhysics()->Update( *doge, timeStep );
		//If out of bounds, delete the doge and skip updating the rest (lose 1 frame)
        else
        {
            delete doge;
            dogeList.erase( dogeList.begin() + count );
            break;
        }
		//Check if the doge has collision with the mouse, and if there is a left click action
        if( SingleCollision( mouse, doge->GetGraphics()->GetDestination() ) && leftClick )
        {
			//smaller doges will be killed in 1 hit
            if( doge->GetSize() != DOGE_SIZE_BIG )
            {
                delete doge;
				//erase the specified doge at the count
                dogeList.erase( dogeList.begin() + count );
                barker->PlayAttack();
                break;
            }
			//big size doges will split into two smaller ones
            else
            {
				//Find the location of the big doge that was killed 
                int x = doge->GetGraphics()->GetDestination().x;
                int y = doge->GetGraphics()->GetDestination().x;
				//Find the direction it was flying
                Doge_Fly_Direction dir = doge->GetDirection();
				//delete it
                delete doge;
				//Erase it from the vector
                dogeList.erase( dogeList.begin() + count );
                barker->PlayAttack();
				//create a small sized doge moving in the same direction
                dogeList.push_back( new Doge( DOGE_SIZE_SMALL, dir, renderer, x, y ) );
                barker->PlayBark(); 
                barker->PlayBark();
				//And create one moving in a random direction
                dogeList.push_back( new Doge( DOGE_SIZE_SMALL, GetDirection( rand() % MAX_RAND_DIR ), renderer, x, y ) );
                break;
            }
        }
        count++;
        if( dogeList.empty() ) //if empty
            break;
    }
}

void Doge_Handler::Draw()
{
	//foreach doge, draw it to the screen
    for( Doge* doge : dogeList )
    {
        doge->GetGraphics()->Draw();
    }
}

bool Doge_Handler::SingleCollision( const SDL_Rect a, const SDL_Rect b )
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int botA, botB;

    //Sides of rect A       sides of rect B
    leftA  = a.x;           leftB  = b.x;
    rightA = a.x + a.w;     rightB = b.x + b.w;
    topA   = a.y;           topB   = b.y;
    botA   = a.y + a.h;     botB   = b.y + b.h;

    //If any of the sides of A are outside of B
    if( botA <= topB )
        return false;
    if( topA >= botB )
        return false;
    if( rightA <= leftB )
        return false;
    if( leftA >= rightB )
        return false;

    return true;
}

bool Doge_Handler::IsCollision( const SDL_Rect a )
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int botA, botB;

    //Sides of rect A       
    leftA  = a.x;           
    rightA = a.x + a.w;     
    topA   = a.y;           
    botA   = a.y + a.h; 

    //iterate through the vector
    for( Doge* doge : dogeList )
    {
        SDL_Rect b = doge->GetGraphics()->GetDestination();
        
        //sides of rect B
        switch( doge->GetSize() )
        {
        case DOGE_SIZE_BIG:
            leftB  = b.x + DOGE_BIG_HIT_OFFSET;
            rightB = b.x + b.w - DOGE_BIG_HIT_OFFSET;
            topB   = b.y + DOGE_BIG_HIT_OFFSET;
            botB   = b.y + b.h - DOGE_BIG_HIT_OFFSET;
            break;
        case DOGE_SIZE_MEDIUM:
            leftB  = b.x + DOGE_MED_HIT_OFFSET;
            rightB = b.x + b.w - DOGE_MED_HIT_OFFSET;
            topB   = b.y + DOGE_MED_HIT_OFFSET;
            botB   = b.y + b.h - DOGE_MED_HIT_OFFSET;
            break;
        case DOGE_SIZE_SMALL:
            leftB  = b.x + DOGE_SML_HIT_OFFSET;
            rightB = b.x + b.w - DOGE_SML_HIT_OFFSET;
            topB   = b.y + DOGE_SML_HIT_OFFSET;
            botB   = b.y + b.h - DOGE_SML_HIT_OFFSET;
            break;
        case DOGE_SIZE_ARROW:
            leftB  = b.x;
            rightB = b.x + b.w;
            topB   = b.y + DOGE_ARR_HIT_OFFSET;
            botB   = b.y + b.h - DOGE_ARR_HIT_OFFSET;
            break;
        }       

        //If any of the sides of A are outside of B
        if( botA <= topB ) {
            continue;
        } if( topA >= botB ) {
            continue;
        } if( rightA <= leftB ) {
            continue;
        } if( leftA >= rightB ) {
            continue;
        }
        return true;
    }
    return false;
}