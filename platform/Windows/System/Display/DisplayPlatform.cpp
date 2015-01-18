/*
    NES Emulator Project
    Created by Igor Belorus
    06/11/2012
*/

#include "DisplayPlatform.h"


DisplayPlatform_t::DisplayPlatform_t()
{
    m_Texture  = 0;
    m_Renderer = 0;
}

void* DisplayPlatform_t::GetFrameBuffer()
{
    return m_pFrame[ m_CurrentFrame ];
}

uint32_t DisplayPlatform_t::GetSizeVertical()
{
    return m_SurfaceSizeY;
}

uint32_t DisplayPlatform_t::GetSizeHorizontal()
{
    return m_SurfaceSizeX;
}

void DisplayPlatform_t::Clear()
{
    uint32_t len = m_SurfaceSizeX * m_SurfaceSizeY;
    
    for( uint32_t idx = 0; idx < len; idx ++ )
    {
        m_pFrame[ m_CurrentFrame ][ idx ] = 0;
    }
}

void DisplayPlatform_t::Init( uint16_t xSize, uint16_t ySize, bool isVsyncEnable  )
{ 
   Init( xSize, ySize, xSize, ySize, isVsyncEnable );
}

void DisplayPlatform_t::Init( uint16_t xSize, uint16_t ySize, uint16_t xWindowSize, uint16_t yWindowSize, bool isVsyncEnable  )
{
    m_SurfaceSizeX = xSize;
    m_SurfaceSizeY = ySize;
    m_CurrentFrame = 0;
    m_pWindow      = 0;

    /*if( m_pFrame )
    {
        delete m_pFrame;
    }*/

    m_pFrame[ 0 ] = new uint32_t[ m_SurfaceSizeX * m_SurfaceSizeY ];
    m_pFrame[ 1 ] = new uint32_t[ m_SurfaceSizeX * m_SurfaceSizeY ];

    SDL_Init( SDL_INIT_VIDEO );

    if( 0 == m_pWindow )
    {
        m_pWindow = SDL_CreateWindow( "Display", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, xWindowSize, yWindowSize, SDL_WINDOW_RESIZABLE );
    }

    if( 0 == m_Renderer )
    {
		uint32_t additionFlags = ( true == isVsyncEnable ) ? SDL_RENDERER_PRESENTVSYNC : 0;
        m_Renderer = SDL_CreateRenderer( m_pWindow, -1, SDL_RENDERER_ACCELERATED | additionFlags );
    }

    if( 0 == m_Texture )
    {
        m_Texture = SDL_CreateTexture( m_Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, m_SurfaceSizeX, m_SurfaceSizeY );
    }

    WindowResize( xWindowSize, yWindowSize );
}


void DisplayPlatform_t::WindowResize( uint16_t xSize, uint16_t ySize )
{
    m_WindowSizeX  = xSize;
    m_WindowSizeY  = ySize;

    if( 0 != m_pWindow )
    {
        SDL_SetWindowSize( m_pWindow, m_WindowSizeX, m_WindowSizeY );
    }

    if( 0 != m_Renderer )
    {
        SDL_RenderSetScale( m_Renderer, m_WindowSizeX, m_WindowSizeY );
    }
}

void DisplayPlatform_t::DrawPixel( uint16_t xPos, uint16_t yPos, uint8_t red, uint8_t green, uint8_t blue )
{
    if( ( xPos <= m_SurfaceSizeX ) && ( yPos <= m_SurfaceSizeY ) )
    {
        uint32_t pixel = 0;

        pixel |= red   << 16;
        pixel |= green << 8;
        pixel |= blue;

        m_pFrame[ m_CurrentFrame ][ xPos + m_SurfaceSizeX * yPos ] = pixel;
    }
}

void DisplayPlatform_t::DrawPixel( uint16_t xPos, uint16_t yPos )
{
}

void DisplayPlatform_t::DrawPixel( uint16_t xPos, uint16_t yPos, Color_t& color )
{
}


void DisplayPlatform_t::Flip( void )
{
    SDL_UpdateTexture( m_Texture, NULL, m_pFrame[ m_CurrentFrame ], m_SurfaceSizeX * sizeof( uint32_t ) );

    SDL_RenderCopy( m_Renderer, m_Texture, NULL, NULL );
    SDL_RenderPresent( m_Renderer );

    m_CurrentFrame = !m_CurrentFrame;
}

void DisplayPlatform_t::SetTitle( const char* pTitle )
{
    SDL_SetWindowTitle( m_pWindow, pTitle );
}

DisplayPlatform_t::~DisplayPlatform_t()
{
    SDL_DestroyTexture( m_Texture );
    SDL_DestroyRenderer( m_Renderer );
    SDL_DestroyWindow( m_pWindow );

    delete m_pFrame[ 0 ];
    delete m_pFrame[ 1 ];
}