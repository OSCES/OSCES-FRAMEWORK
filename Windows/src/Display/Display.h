#ifndef _Display_h_
#define _Display_h_

#include <stdint.h>
#include "SDL.h"

struct PixelStruct_t
{
    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
};

class Display_t
{
    public:
        void Init( uint16_t xSize, uint16_t ySize );
        void WindowResize( uint16_t xSize, uint16_t ySize );

        void Present( PixelStruct_t* pData );
        void DrawPixel( uint16_t xPos, uint16_t yPos, uint8_t red, uint8_t green, uint8_t blue );
        void Flip( void );
        void Clear();
        ~Display_t();

    private:
        void SurfaceLock( void );
        void SurfaceUnock( void );
        

    private:
        SDL_Window*    m_pWindow;   
        SDL_GLContext  m_pOpenGLContext;
        PixelStruct_t* m_pFrame[ 2 ];
        uint16_t       m_WindowSizeX;
        uint16_t       m_WindowSizeY;
        uint16_t       m_SurfaceSizeX;
        uint16_t       m_SurfaceSizeY;
        uint8_t        m_CurrentFrame;
};

#endif