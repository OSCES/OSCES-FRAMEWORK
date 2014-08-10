
#include "Keyboard.h"
#include "CodePageTable.h"


#define EXTEND_KEY_OFFSET 0x83

static uint8_t Set2KeyCodeTable[] =
{
    0x00, 0x40, 0x00, 0x3C, 0x3A, 0x38, 0x39, 0x43, 0x00, 0x41, 0x3F, 0x3D, 0x3B, 0x2B, 0x25, 0x00,
    0x00, 0x30, 0x2D, 0x00, 0x2E, 0x11, 0x1C, 0x00, 0x00, 0x00, 0x1A, 0x13, 0x01, 0x17, 0x1D, 0x00,
    0x00, 0x03, 0x18, 0x04, 0x05, 0x1F, 0x1E, 0x00, 0x00, 0x2A, 0x16, 0x06, 0x14, 0x12, 0x20, 0x00,
    0x00, 0x0E, 0x02, 0x08, 0x07, 0x19, 0x21, 0x00, 0x00, 0x00, 0x0D, 0x0A, 0x15, 0x22, 0x23, 0x00,
    0x00, 0x66, 0x0B, 0x09, 0x0F, 0x1B, 0x24, 0x00, 0x00, 0x67, 0x68, 0x0C, 0x64, 0x10, 0x26, 0x00,
    0x00, 0x00, 0x65, 0x00, 0x47, 0x27, 0x00, 0x00, 0x2C, 0x31, 0x36, 0x63, 0x00, 0x28, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x5A, 0x00, 0x5D, 0x60, 0x00, 0x00, 0x00,
    0x59, 0x58, 0x5B, 0x5E, 0x5F, 0x61, 0x37, 0x52, 0x42, 0x56, 0x5C, 0x55, 0x54, 0x62, 0x45, 0x00,
    0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x34, 0x44, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4C, 0x00, 0x4F, 0x49,
    0x00, 0x00, 0x00, 0x48, 0x4B, 0x50, 0x00, 0x51, 0x4E, 0x00, 0x00, 0x00, 0x00, 0x4D, 0x00, 0x00,
    0x4A
};

Keyboard_t::Keyboard_t() :
    m_fpCallBack( 0 ),
    m_pContext  ( 0 ),
    m_pCodePage ( 0 )
{
}

Keyboard_t::~Keyboard_t()
{
}

void Keyboard_t::RegisterCallBack( void* pContext, KeyboardCallBack_t fpCallBack )
{
    m_fpCallBack = fpCallBack;
    m_pContext   = pContext;
}

void Keyboard_t::UnRegisterCallBack( KeyboardCallBack_t fpCallBack )
{
    m_fpCallBack = 0;
    m_pContext   = 0;
}

void Keyboard_t::SetCodePage( CodePage_t codePage )
{
    switch( codePage )
    {
        case CP_ASCII: m_pCodePage = CPTable::AsciiTable ; break;
        case CP_UTF8 : m_pCodePage = CPTable::Utf8Table  ; break;
        case CP_1251 : m_pCodePage = CPTable::Cp1251Table; break;

        default:
            m_pCodePage = 0;
        break;
    }
}

uint8_t Keyboard_t::ScanCodeToKeyCode(uint8_t scanCode, uint8_t extendKeyFlag)
{
    if( extendKeyFlag )
    {
        scanCode += EXTEND_KEY_OFFSET;
    }

    return Set2KeyCodeTable[ scanCode ];
}

uint8_t Keyboard_t::KeyCodeToCharCode( uint8_t keyCode )
{
    uint16_t CharCode = 0xFF;

    if( m_pCodePage )
    {
        CharCode = m_pCodePage[ keyCode ];
    }
    return CharCode;
}
