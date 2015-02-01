#include "GraphicalPrimitives/Surface.h"

Surface_t::Surface_t( SurfeceLocation_t location, PixelFormat_t pixelFormat, DisplayInterface_t* pDisplay )
{
    m_Location = location;
    m_pDisplay = pDisplay;
}

PixelFormat_t Surface_t::GetPixelFormat()
{
    return m_PixelFormat;
}
	

uint32_t Surface_t::GetSizeVertical()
{
    return m_pDisplay->GetSizeVertical();
}

uint32_t Surface_t::GetSizeHorizontal()
{
    return m_pDisplay->GetSizeHorizontal();
}

void* Surface_t::GetFrameBuffer()
{
    return m_pDisplay->GetFrameBuffer();
}