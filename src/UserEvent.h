//
// Created by Jacob on 11/08/2020.
//

#ifndef PROJECT_PHEONIX_USEREVENT_H
#define PROJECT_PHEONIX_USEREVENT_H

#include <SDL_surface.h>

class UserEvent {
    public:
    static int User_KeyPress(int key, int type);

    static bool KEY_SHIFT;
    static bool KEY_PRESS_UP;
    static bool KEY_PRESS_DOWN;
    static bool KEY_PRESS_LEFT;
    static bool KEY_PRESS_RIGHT;

    private:
    static void SDL_GetMouseState(int *pInt, int *pInt1);
};

#endif //PROJECT_PHEONIX_USEREVENT_H
