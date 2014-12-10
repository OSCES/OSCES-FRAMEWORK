#ifndef KEYBOARD_PLATFORM_H
#define KEYBOARD_PLATFORM_H

#include <stdint.h>
#include "crossplatform/System/Keyboard/Keyboard.h"


class KeyboardPlatform_t : public Keyboard_t
{
public:
    void OnEvent(Key_t& key);
};

#endif // KEYBOARD_H
