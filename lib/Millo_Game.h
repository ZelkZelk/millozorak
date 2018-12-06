#include "Millo_Game_Data.h"
#include "SDL.h"

#ifndef MILLO_GAME_H
    #define MILLO_GAME_H

    typedef struct Millo_Game {
        unsigned short int quit;
        SDL_Event event;
        SDL_Surface *screen;
    } Millo_Game;

    Millo_Game *Millo_Init_Engine();
    Millo_Game_Data *Millo_Init_Context();
    SDL_Surface *Millo_Init_Screen();
    void Millo_Game_Render(Millo_Game *engine, Millo_Game_Data **context);
    void Millo_Game_Keydown(Millo_Game *engine, Millo_Game_Data **context);
    void Millo_Game_Up(Millo_Game *engine, Millo_Game_Data **context);
    void Millo_Game_Down(Millo_Game *engine, Millo_Game_Data **context);
    void Millo_Game_Enter(Millo_Game *engine, Millo_Game_Data **context);
    void Millo_Game_Enter_Instrucciones(Millo_Game *engine, Millo_Game_Data **context);
    void Millo_Game_Enter_MenuMain(Millo_Game *engine, Millo_Game_Data **context);
    void Millo_Render_Menu_Opciones(Millo_Game *engine, Millo_Game_Data *context);
    void Millo_Render_Menu_Arrow(Millo_Game *engine, Millo_Game_Data *context,SDL_Rect posicion);
    void Millo_Game_Enter_Preguntas(Millo_Game *engine, Millo_Game_Data **context);
    void Millo_Game_Enter_SinContinue(Millo_Game *engine, Millo_Game_Data **context);
#endif