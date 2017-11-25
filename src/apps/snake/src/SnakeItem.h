#ifndef _SNAKE_ITEM_H_
#define _SNAKE_ITEM_H_

#include "OscesFrameworkInterface.h"


class SnakeItem_t
{
public:
    SnakeItem_t( DisplayInterface_t* pDisplay, uint16_t size );
    SnakeItem_t();
    void SetNext( SnakeItem_t* next );
    SnakeItem_t* GetNext();
    void Move( uint16_t xPos, uint16_t yPos );
    void Redraw();
    

public:
    uint16_t     m_PosX;
    uint16_t     m_PosY;

private:
    SnakeItem_t* m_pNext;
    uint16_t     m_SnakeItemSize;
};

#endif