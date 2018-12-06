#include "SDL.h"
#include "SDL_ttf.h"
#include "lib/Millo_Constantes.h"
#include "lib/Millo_Game_Data.h"
#include "lib/Millo_Game.h"
#include "lib/Millo_Player_Data.h"
#include "lib/Millo_Menu_Data.h"
#include "lib/Millo_Error.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        Millo_Error_SDL();
        exit(-1);
    }

    if(TTF_Init() < 0){
        Millo_Error_TTF();
        exit(-1);
    }

    Millo_Game *engine = Millo_Init_Engine();
    Millo_Game_Data *context = Millo_Init_Context();

    while(!engine->quit){
        Millo_Game_Render(engine,&context);

        while(SDL_PollEvent(&engine->event)){
            switch(engine->event.type){
                case SDL_KEYDOWN:
                    Millo_Game_Keydown(engine,&context);
                    break;
                case SDL_QUIT:
                    engine->quit = 1;
                    break;
                default:
                    break;
            }
        }
    }   

    TTF_Quit();
    SDL_Quit();
    exit(0);
}