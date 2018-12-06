#include "Millo_Error.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <stdio.h>

void Millo_Error_SDL(){
    fprintf( stderr, "ERROR SDL: %s\n", SDL_GetError());
}
void Millo_Error_TTF(){
    fprintf( stderr, "ERROR TTF: %s\n", TTF_GetError());
}