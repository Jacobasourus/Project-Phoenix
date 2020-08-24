//
// Created by Jacob on 11/08/2020.
//

#include <iostream>
#include "UserEvent.h"

enum gKeyPressSurfaces {
    KEY_PRESS_SURFACE_DEFAULT, KEY_PRESS_SURFACE_UP = 119, KEY_PRESS_SURFACE_DOWN = 115, KEY_PRESS_SURFACE_LEFT = 97, KEY_PRESS_SURFACE_RIGHT = 100, KEY_PRESS_SURFACE_TOTAL,
};

bool UserEvent::KEY_SHIFT = false;
bool UserEvent::KEY_PRESS_UP = false;
bool UserEvent::KEY_PRESS_DOWN = false;
bool UserEvent::KEY_PRESS_LEFT = false;
bool UserEvent::KEY_PRESS_RIGHT = false;

int UserEvent::User_KeyPress(int key, int type) {

    switch (key) {
        case KEY_PRESS_SURFACE_DEFAULT:
            return 1;
        case 16:
            if (type && !UserEvent::KEY_SHIFT) {
                UserEvent::KEY_SHIFT = true;
            } else if (!type) {
                UserEvent::KEY_SHIFT = false;
            }
            return 1;
        case KEY_PRESS_SURFACE_UP:
            if (type && !UserEvent::KEY_PRESS_UP) {
                UserEvent::KEY_PRESS_UP = true;
            } else if (!type) {
                UserEvent::KEY_PRESS_UP = false;
            }
            return 1;;
        case KEY_PRESS_SURFACE_DOWN:
            if (type && !UserEvent::KEY_PRESS_DOWN) {
                UserEvent::KEY_PRESS_DOWN = true;
            } else if (!type) {
                UserEvent::KEY_PRESS_DOWN = false;
            }
            return 1;
        case KEY_PRESS_SURFACE_LEFT:
            if (type && !UserEvent::KEY_PRESS_LEFT) {
                UserEvent::KEY_PRESS_LEFT = true;
            } else if (!type) {
                UserEvent::KEY_PRESS_LEFT = false;
            }
            return 1;
        case KEY_PRESS_SURFACE_RIGHT:
            if (type && !UserEvent::KEY_PRESS_RIGHT) {
                UserEvent::KEY_PRESS_RIGHT = true;
            } else if (!type) {
                UserEvent::KEY_PRESS_RIGHT = false;
            }
            return 1;
        case KEY_PRESS_SURFACE_TOTAL:
            return 1;
        default:
            return 0;
    }
}