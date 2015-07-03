#include "Main_Loop.h"
#include "Menu.h"

Main_Loop::Main_Loop()
{
    quit        = false;
    timeStep    = 0.0f;
    renderer    = new Game_Renderer();
    hero        = new Game_Actor();
    gameSounds  = new Game_Sounds();
    gameText    = new Game_Text( renderer );
    menuHandler = new Menu_Handler( renderer, gameSounds, gameText );
    dogeHandler = new Doge_Handler( renderer, gameSounds );
}


Main_Loop::~Main_Loop()
{
    delete hero;
    delete renderer;
    delete gameSounds;
    delete dogeHandler;
    delete menuHandler;
    delete gameText;

    renderer = NULL;
    hero = NULL;
    gameSounds = NULL;
    dogeHandler = NULL;
    gameText = NULL;
    menuHandler = NULL;

    IMG_Quit();
    SDL_Quit();
}

void Main_Loop::Run()
{
	// the only way out of all the game loops is to quit
    while( !quit )
    {
        //check quit
        if( quit )
            break;
		//If not quit, start the menus
        else
            MenuLoop();
        //check quit
        if( quit )
            break;
		//If not quit, start the game
        else
            GameLoop();
    }
}

void Main_Loop::GameLoop()
{
    //loop until quitting
    bool gameQuit = false;
    bool mouseCollision = false;
    bool leftClick = false;
    stepTimer.Start();
    gameSounds->PlayMusic();
    gameText->StartTimer();
    //Clear the doges for fresh starts
    dogeHandler->ClearDoges();

    //Spawn whichever is chosen
    switch( character )
    {
    case MENU_ID_PLAY_ATTACK:
        hero->SpawnAttacker( renderer );
        break;
    case MENU_ID_PLAY_DODGE:
        hero->SpawnDodger( renderer );
        break;
    }

    while( !gameQuit )
    {
        //Clear the screen first
        renderer->ClearScreen();

        //==============================
        // Taking input for updating 
        //==============================
		//Loop until the pipeline of events is empty
        while( SDL_PollEvent( &gameEvent ) != 0 ) 
        {
            switch( gameEvent.type ) 
            {
            case SDL_QUIT:
                gameQuit = true;
                break;

				//If a key was pressed
            case SDL_KEYDOWN:
                if( gameEvent.key.keysym.sym == SDLK_ESCAPE ) {     //quit game
                    gameQuit = true;
                    break; 
                }
                else                                               //Get input
                    hero->GetInputObject()->HandleInput( gameEvent );

				//If it a key was let go
            case SDL_KEYUP:
                hero->GetInputObject()->HandleInput( gameEvent );
				//if the mouse was moved
            case SDL_MOUSEMOTION:
                hero->GetInputObject()->HandleMouse( gameEvent );
				//if the mouse button was released
            case SDL_MOUSEBUTTONUP:
                hero->GetInputObject()->HandleMouse( gameEvent );
                break;
				//f the mouse button was pressed
            case SDL_MOUSEBUTTONDOWN:
                hero->GetInputObject()->HandleMouse( gameEvent );
                break;
            }
        }

        //==============================
        // Using input to update logic
        //==============================
		//Check collisin between doges and the hero
        if( dogeHandler->IsCollision( hero->GetGraphics()->GetDestination() ) )
        {
            gameSounds->PlayDeath();
            gameQuit = true;
        }

		//check mouse collision between the doges and the mouse
        mouseCollision = dogeHandler->IsCollision( hero->GetGraphics()->GetMouseDest() );
        leftClick = hero->GetInputObject()->GetLeftClick();

		//use time for any animations or movement, so every machine will play the same rather than depnding on Frames per second
        timeStep = stepTimer.GetTicks() / 1000.0f;

		//update hero's input
        hero->GetInputObject()->Update( *hero );
		//Update hero's position
        hero->GetPhysics()->Update( *hero, timeStep, renderer->GetScreenHeight(), renderer->GetScreenWidth() );
		//Update hero's graphic's position
        hero->GetGraphics()->Update( *hero, timeStep, mouseCollision );
		//Update doge's positions
        dogeHandler->Update( timeStep, hero->GetGraphics()->GetMouseDest(), leftClick );
		//Update the timer
        gameText->UpdateScore();

		//restart the step timer to ensure the same time is used in all calculations, so the Frames per second indirectly affect the game
        stepTimer.Start();
        //==============================
        // Drawing the next frame
        //==============================
        dogeHandler->Draw();
        hero->GetGraphics()->Draw();
        hero->GetGraphics()->DrawMouse();
        gameText->DisplayScore();

        renderer->UpdateScreen();
    }
    //Stop game stuff
    gameText->PauseTimer(); 
    gameText->PingScore();
	gameText->SaveScore();
    gameText->StopTimer();
    gameSounds->StopMusic();
    renderer->ClearScreen();
    SDL_SetRelativeMouseMode( SDL_FALSE );
}

void Main_Loop::MenuLoop()
{
    bool menuQuit = false;

    menuHandler->SetOpenMenu( MENU_ID_MAIN );
    while( !menuQuit )
    {
        //Clear the screen first
        renderer->ClearScreen();

        //==============================
        // Taking input for updating 
        //==============================
        while( SDL_PollEvent( &gameEvent ) != 0 ) 
        {
            switch( gameEvent.type ) 
            {
            case SDL_QUIT:
                menuQuit = true;
                quit = true;
                break;

            case SDL_KEYDOWN:
                if( gameEvent.key.keysym.sym == SDLK_ESCAPE ){     //quit game
                    menuQuit = true; 
                    quit = true;
                } else                                               //Get input
                    menuHandler->HandleInput( gameEvent );

            case SDL_KEYUP:
                menuHandler->HandleInput( gameEvent );
                break;

			case SDL_MOUSEMOTION:
                hero->GetInputObject()->HandleMouse( gameEvent );

            case SDL_MOUSEBUTTONUP:
                hero->GetInputObject()->HandleMouse( gameEvent );
                break;

            case SDL_MOUSEBUTTONDOWN:
                hero->GetInputObject()->HandleMouse( gameEvent );
                break;
            }
        }

        //==============================
        // Using input to update logic
        //==============================
        menuHandler->UpdateInput();
        menuHandler->UpdateGraphics();

        //Check if exiting menus
        if( menuHandler->GetOpenMenu() == MENU_ID_PLAY_DODGE || menuHandler->GetOpenMenu() == MENU_ID_PLAY_ATTACK ) {
            character = menuHandler->GetOpenMenu();
            menuQuit = true;
        } else {
            //==============================
            // Drawing the next frame
            //==============================
            menuHandler->DrawGraphics();
        
            renderer->UpdateScreen();
        }
    }
}