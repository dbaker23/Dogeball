#pragma once
#include "Attacker_Graphics.h"
#include "Attacker_Input.h"
#include "Attacker_Physics.h"
#include "Dodger_Graphics.h"
#include "Dodger_Input.h"
#include "Dodger_Physics.h"
#include "Dodger_States.h"

#define DODGER_STARTING_HEALTH  10		//Initially wanted a health system, never used it.
#define HERO_START_X            100.0f	//Starting x and y positions of the sprite
#define HERO_START_Y            150.0f

enum Actor_Type
{
    ACTOR_TYPE_DODGER,	//Types of characters the player can choose from
    ACTOR_TYPE_ATTACKER
};

enum Current_State
{
    ACTOR_STATE_STANDING,	//Types of states the characters can take on
    ACTOR_STATE_RUNNING,
    ACTOR_STATE_ATTACKING
};

//Any game actor 
class Game_Actor
{
public:
    Game_Actor();
    ~Game_Actor();

    /*=====================================================
    *ChangeState: depending on input, change character to new state

    *Parameters: 
        newState: what state will be set to
    =======================================================*/
    void ChangeState( Component_Actor_State* newState );

    /*=====================================================
    *SpawnDodger/SpawnAttacker: hookup respective components
        to Game_Actor class 

    *Parameters: 
        gRenderer: hooks up with pointers in graphics components for rendering
    =======================================================*/
    void SpawnDodger( Game_Renderer* gRenderer );
    void SpawnAttacker( Game_Renderer* gRenderer );

    Actor_Type             GetActorType()   { return actorType; }	//Returns which character the player chose
    Component_Actor_State* GetStateObject() { return state; }		//Returns the state machine object
    Component_Graphics*    GetGraphics()    { return graphics; }	//returns the graphics object
    Component_Input*       GetInputObject() { return input; }		//returns the input object
    Component_Physics*     GetPhysics()     { return physics; }		//returns the physics object
    int                    GetHealth()      { return health; }		//returns the health if i ever used it

    void SetEState( Current_State newEState ) {  eState = newEState; }	//Changes the state of the character to the passed-in state using "new RunningState()" or whatever desired

private:
    int                     health;     //Amount of hits left
    Actor_Type              actorType;  //Dodger or attacker
    Current_State           eState;     //Enum type to easily identify what the actor is doing
    Component_Actor_State*  state;      //Character's statemachine
    Component_Graphics*     graphics;   //Character's on-screen rendition
    Component_Input*        input;      //Keyboard input
    Component_Physics*      physics;    //Movement and acceleration
};

