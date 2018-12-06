#include "Millo_Game.h"
#include "Millo_Constantes.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "Millo_Game_Data.h"
#include "Millo_Menu_Data.h"
#include "Millo_Menu_Opcion.h"
#include "Millo_Error.h"
#include <stdlib.h>
#include <string.h>

Millo_Game *Millo_Init_Engine(){
    Millo_Game *engine = (Millo_Game *) malloc(sizeof(Millo_Game));
    engine->quit = 0;
    engine->screen = Millo_Init_Screen();

    return engine;
}

Millo_Game_Data *Millo_Init_Context(){
    Millo_Game_Data *context = (Millo_Game_Data *) malloc(sizeof(Millo_Game_Data));
    context->player = (Millo_Player_Data *) malloc(sizeof(Millo_Player_Data));
    context->player->pantalla = MILLO_PANTALLA_MAIN;
    context->player->menu = 0;
    context->player->pregunta = 0;
    context->dibujar = 1;
    context->menu = Millo_Menu_Resolver(MILLO_PANTALLA_MAIN);
    return context;
}

SDL_Surface *Millo_Init_Screen(){
    SDL_Surface *screen = SDL_SetVideoMode(MILLO_VIDEO_W,MILLO_VIDEO_H,16,SDL_HWSURFACE);
    
    if(screen == NULL){
        Millo_Error_SDL();
        exit(-1);
    }

    SDL_WM_SetCaption(MILLO_TITLE,MILLO_TITLE);
    return screen;
}

void Millo_Game_Render(Millo_Game *engine, Millo_Game_Data **context){
    if((*context)->dibujar == 1){
        printf("render %d\n",(*context)->dibujar); fflush(stdout);
        SDL_FillRect(engine->screen,NULL,0);
        Millo_Render_Menu_Opciones(engine,*context);
        SDL_Flip(engine->screen);
        (*context)->dibujar = 0;
    }
}

void Millo_Game_Keydown(Millo_Game *engine, Millo_Game_Data **context){
    SDL_KeyboardEvent *key = &engine->event.key;
    printf( "Scancode: 0x%02X\n", key->keysym.scancode);    // Debug de la tecla presionada

    switch(key->keysym.scancode){
        case 0x74:
            Millo_Game_Down(engine,context);    // Flecha abajo
            break;
        case 0x6F:                              // Flecha arriba
            Millo_Game_Up(engine,context);
            break;
        case 0x24:                              // ENTER
            Millo_Game_Enter(engine,context);
            break;
    }
}

void Millo_Game_Enter(Millo_Game *engine, Millo_Game_Data **context){
    // Controlamos el ENTER de cada menu, segun la pantalla en la que estemos posicionados
    int current = (*context)->player->pantalla;

    switch((*context)->player->pantalla){
        case MILLO_PANTALLA_MAIN:
            Millo_Game_Enter_MenuMain(engine,context);
            break;
        case MILLO_PANTALLA_INSTRUCCIONES:
            Millo_Game_Enter_Instrucciones(engine,context);
            break;
        case MILLO_PANTALLA_PREGUNTAS:
            Millo_Game_Enter_Preguntas(engine,context);
            break;
        case MILLO_PANTALLA_SIN_CONTINUE:
            Millo_Game_Enter_SinContinue(engine,context);
            break;
    }

    int next = (*context)->player->pantalla;

    if(next != current){
        // Cambio de pantalla implica cambio de menu
        Millo_Menu_Clear((*context)->menu);
        (*context)->menu = Millo_Menu_Resolver(next);
    }
}

void Millo_Game_Enter_MenuMain(Millo_Game *engine, Millo_Game_Data **context){
    // ENTER del Menu principal, dependiendo de la opcion ejecutamos una accion distinta

    switch((*context)->player->menu){
        case 0:
            // TODO: preguntar por el archivo de continue e inyectarlo al contexto caso contrario...
            (*context)->player->pantalla = MILLO_PANTALLA_SIN_CONTINUE;
            (*context)->player->menu = 0;
            (*context)->dibujar = 1;
            break;
        case 1:
            (*context)->player->pantalla = MILLO_PANTALLA_PREGUNTAS;
            (*context)->player->menu = 1;   // Por que nos interesa que el indicador este en la primera respuesta por default
            (*context)->dibujar = 1;
            break;
        case 2:
            (*context)->player->pantalla = MILLO_PANTALLA_INSTRUCCIONES;
            (*context)->player->menu = 0;
            (*context)->dibujar = 1;
            break;
        case 3:
            engine->quit = 1;
            break;
    }
}
void Millo_Game_Enter_Preguntas(Millo_Game *engine, Millo_Game_Data **context){
    // TODO: Mecanica de contestar la pregunta
}

void Millo_Game_Enter_SinContinue(Millo_Game *engine, Millo_Game_Data **context){
    (*context)->player->pantalla = MILLO_PANTALLA_MAIN;
    (*context)->player->menu = 0;
    (*context)->dibujar = 1;
}

void Millo_Game_Enter_Instrucciones(Millo_Game *engine, Millo_Game_Data **context){
    // Las instrucciones son un pseudomenu, solo texto, sin indicadores de ningun tipo, hasta no parece un menu.
    // Como solo hay una opcion ni hago el switch

    (*context)->player->pantalla = MILLO_PANTALLA_MAIN;
    (*context)->player->menu = 0;
    (*context)->dibujar = 1;
}

void Millo_Game_Up(Millo_Game *engine, Millo_Game_Data **context){
    int current = (*context)->player->menu;
    int next;

    if(current - 1 < 0){
        next = 0;
    }
    else if(strlen((*context)->menu->opciones[current - 1]->texto) == 0){
        next = 0;
    }
    else{
        next = current - 1;
    }

    if(next != current){
        (*context)->player->menu = next;
        (*context)->dibujar = 1;
    }
}

void Millo_Game_Down(Millo_Game *engine, Millo_Game_Data **context){
    int current = (*context)->player->menu;
    int next;

    if(current + 1 > MILLO_MENU_MAX){
        next = current;
    }
    else if(strlen((*context)->menu->opciones[current + 1]->texto) == 0){
        next = current;
    }
    else{
        next = current + 1;
    }

    if(next != current){
        (*context)->player->menu = next;
        (*context)->dibujar = 1;
    }
}

void Millo_Render_Menu_Opciones(Millo_Game *engine, Millo_Game_Data *context){
    SDL_Color selected = {126,126,126};
    SDL_Color white = {255,255,255};
    SDL_Color black = {0,0,0};
    SDL_Rect dst;
    dst.x = 65;
    dst.y = 40;

    for(unsigned short int i = 0;i < MILLO_MENU_MAX;i++){
        Millo_Menu_Opcion *op = context->menu->opciones[i];

        if(strlen(op->texto) > 0){
            SDL_Color *colorTexto;
            SDL_Rect *posicion;

            if(op->color == NULL){
                colorTexto = &white;
            }
            else{
                colorTexto = op->color;
            }

            if(op->posicion == NULL){
                posicion = &dst;
                dst.y += 65;
            }
            else{
                posicion = op->posicion;
            }
            
            if(i == context->player->menu){
                if(context->menu->indicador == 1){
                    Millo_Render_Menu_Arrow(engine,context,*posicion);
                }
                
                if(context->menu->resaltado == 1){
                    colorTexto = &selected;
                }
            }

            SDL_Surface *surface = TTF_RenderUTF8_Shaded(op->font,op->texto,*colorTexto,black);
            SDL_BlitSurface(surface,NULL,engine->screen,posicion);
            SDL_FreeSurface(surface);
        }
    }
}

void Millo_Render_Menu_Arrow(Millo_Game *engine, Millo_Game_Data *context,SDL_Rect posicion){
    posicion.x = 20;

    SDL_Surface *bitmap = SDL_LoadBMP(MILLO_GFX_MENU_ARROW);
    SDL_BlitSurface(bitmap,NULL,engine->screen,&posicion);
    SDL_FreeSurface(bitmap);
}