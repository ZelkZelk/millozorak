#include "SDL.h"
#include "SDL_ttf.h"

#ifndef MILLO_MENU_OPCION_H
    #define MILLO_MENU_OPCION_H

    typedef struct Millo_Menu_Opcion {
        char *texto;
        SDL_Color *color;
        SDL_Rect *posicion;
        TTF_Font *font;
    } Millo_Menu_Opcion;

#endif