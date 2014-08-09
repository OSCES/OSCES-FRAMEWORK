#include "OscesFramework.h"

#include <SDL.h>
#include "SDL_thread.h"
#include "SDL_timer.h"
#include <stdio.h>

OscesFramework_t::OscesFramework_t()
{
    m_IsApplicationRun = true;
}

SysTimerInterface_t* OscesFramework_t::GetSysTimer()
{
    return m_pSysTimer;
}

DisplayInterface_t* OscesFramework_t::GetDisplay()
{
    return m_pDisplay;
}

KeyboardInterface_t* OscesFramework_t::GetKeyboard()
{
    return m_pKeyboard;
}


#ifdef WIN32
#include <windows.h>
int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow ) //For VS2012
//int SDL_main(int argc, char *argv[])
#else
int main()
#endif
{
    OscesFramework_t*  pOscesFramework = new OscesFramework_t();

    pOscesFramework->Init();

    osces_main( pOscesFramework );

    pOscesFramework->DeInit();

    return 0;
}


bool OscesFramework_t::IsApplicationRun()
{
    SDL_Event sdlEvent;

    while( SDL_PollEvent( &sdlEvent ) )
    {
        if( sdlEvent.type == SDL_WINDOWEVENT )
        {
            if( sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED )
            {
                m_pDisplay->WindowResize( sdlEvent.window.data1,sdlEvent.window.data2 );
            }
        }
            

        if( sdlEvent.type == SDL_KEYDOWN )
        {
//            m_pKeyboard->ReceiveEvent( KEYBOARD_PRESSED, sdlEvent.key.keysym.sym );
        }
        else if( sdlEvent.type == SDL_KEYUP )
        {
//            m_pKeyboard->ReceiveEvent( KEYBOARD_UNPRESSED, sdlEvent.key.keysym.sym );
        }

            

        if(  SDL_QUIT == sdlEvent.quit.type )
        {
            m_IsApplicationRun = false;
        }
            
    }

    return m_IsApplicationRun;
}

OscesFrameworkStatus_t OscesFramework_t::Init()
{
    OscesFrameworkStatus_t status = OSCES_FRAMEWORK_INIT_SUCCESS;

    do
    {
        if( 0 != SDL_Init( SDL_INIT_TIMER ) )
        {
            status = OSCES_FRAMEWORK_INIT_FAILED;
            break;
        }

        if( 0 != SDL_Init( SDL_INIT_VIDEO ) )
        {
            status = OSCES_FRAMEWORK_INIT_FAILED;
            break;
        }


        m_pDisplay  = new DisplayPlatform_t;
        m_pKeyboard = new KeyboardPlatform_t;
        m_pSysTimer = new SysTimerPlatform_t;

    }while( false );

    m_pDisplay->Init( 400, 300);

    m_pDisplay->Clear();
    m_pDisplay->Flip();
    m_pDisplay->Clear();
    m_pDisplay->Flip();

    return status;
}


void OscesFramework_t::DeInit()
{
    delete m_pSysTimer;
    delete m_pKeyboard;
    delete m_pDisplay;
}