#include "Options_Menu_Graphics.h"
#include "Menu.h"

Options_Menu_Graphics::Options_Menu_Graphics( Game_Renderer* gRenderer ) :
    Component_Menu_Graphics( gRenderer )
{
    background      = new Sprite( gRenderer->LoadTexture( OPTIONS_MENU_BACKGROUND_PATH ), gRenderer->GetScreenWidth(), gRenderer->GetScreenHeight() );
    yPosition[ 0 ]  = OPTIONS_TOP_Y;
    yPosition[ 1 ]  = OPTIONS_MUSIC_Y;
    yPosition[ 2 ]  = OPTIONS_BOT_Y;
    y               = 0;

    for( int i = 0; i < OPTIONS_DD_AMOUNT; i++ )
    {
        ddPosition[ i ].x = CHECK_BOX_XPOS;
        ddPosition[ i ].h = CHECK_ON_HEIGHT;
        ddPosition[ i ].w = CHECK_ON_WIDTH;
        ddPosition[ i ].y = OPTIONS_TOP_Y;
    }

    ddPosition[ DD_MUSIC ].y = OPTIONS_MUSIC_Y;
    ddPosition[ DD_SOUNDS ].y = OPTIONS_BOT_Y;

    music           = CHECK_ON;
    sounds          = CHECK_ON;
}

Options_Menu_Graphics::~Options_Menu_Graphics()
{
}

void Options_Menu_Graphics::Update( Menu& menu, int& curMenu )
{
    if( y == 0 && menu.GetGraphics()->GetIndicatorY() != OPTIONS_TOP_Y )
        menu.GetGraphics()->SetIndicatorY( OPTIONS_TOP_Y );
    if( menu.GetGraphics()->GetIndicatorX() != INDICATOR_START_X )
        menu.GetGraphics()->SetIndicatorX( INDICATOR_START_X );

    switch( menu.GetInputDir() )
    {
    case KEY_BACK:
        curMenu = MENU_ID_MAIN;
        menu.GetSounds()->PlayMenuSel();
        break;

    case KEY_DOWN:
        if( menu.GetGraphics()->GetIndicatorY() != OPTIONS_BOT_Y )
        {
            y++;
            menu.GetGraphics()->SetIndicatorY( yPosition[ y ] );
            menu.GetSounds()->PlayMenuSel();
        }
        break;
    
    case KEY_UP:
        if( menu.GetGraphics()->GetIndicatorY() != OPTIONS_TOP_Y )
        {
            y--;
            menu.GetGraphics()->SetIndicatorY( yPosition[ y ] );
            menu.GetSounds()->PlayMenuSel();
        }
        break;

    case KEY_ENTER:
        switch( yPosition[ y ] )
        {
        case OPTIONS_TOP_Y:     //Back
            curMenu = MENU_ID_MAIN;
            menu.GetSounds()->PlayMenuSel();
            break;
        case OPTIONS_MUSIC_Y: //Music
            music = !music;
            menu.GetSounds()->PlayMenuSel();
            menu.GetSounds()->SetMusic( music );
            break;
        case OPTIONS_BOT_Y: //Sounds
            sounds = !sounds;
            menu.GetSounds()->PlayMenuSel();
            menu.GetSounds()->SetSound( sounds );
            break;
        }
        break;
    }
}

void Options_Menu_Graphics::DrawDoodads()
{
    if( music )
        renderer->DrawScreen( checkOn->GetTexture(), &ddPosition[ DD_MUSIC ], &checkOn->GetClip() );
    else
        renderer->DrawScreen( checkOff->GetTexture(), &ddPosition[ DD_MUSIC ], &checkOff->GetClip() );

    if( sounds )
        renderer->DrawScreen( checkOn->GetTexture(), &ddPosition[ DD_SOUNDS ], &checkOn->GetClip() );
    else
        renderer->DrawScreen( checkOff->GetTexture(), &ddPosition[ DD_SOUNDS ], &checkOff->GetClip() );
}