#include "Millo_Menu_Data.h"
#include "Millo_Menu_Opcion.h"
#include "Millo_Constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Millo_Menu_Clear(Millo_Menu_Data *menu){
    for(int i = 0;i < MILLO_MENU_MAX;i++){
        free(menu->opciones[i]->texto);
        free(menu->opciones[i]->color);
        free(menu->opciones[i]->posicion);
        free(menu->opciones[i]->font);
        free(menu->opciones[i]);
    }

    free(menu);
}

 Millo_Menu_Data *Millo_Menu_Resolver(int pantalla){
    Millo_Menu_Data *menu = (Millo_Menu_Data *) malloc(sizeof(Millo_Menu_Data));
    menu->indicador = 1;
    menu->resaltado = 1;

    switch(pantalla){
        case MILLO_PANTALLA_MAIN:
            Millo_Menu_Carga(&menu,MILLO_MENU_MAIN);
            break;
        case MILLO_PANTALLA_INSTRUCCIONES:
            Millo_Texto_Carga(&menu,MILLO_MENU_INSTRUCCIONES);
            break;
        case MILLO_PANTALLA_PREGUNTAS:
            Millo_Menu_Carga_Preguntas(&menu);
            break;
        case MILLO_PANTALLA_SIN_CONTINUE:
            Millo_Texto_Carga(&menu,MILLO_MENU_SIN_CONTINUE);
            break;
    }

    return menu;
}

void Millo_Menu_Carga_Preguntas(Millo_Menu_Data **menu){
    // TODO: cargar pregunta aqui y respuestas aqui.
}

void Millo_Menu_Carga(Millo_Menu_Data **menu, const char **opciones){
    for(int i = 0;i < MILLO_MENU_MAX;i++){
        (*menu)->opciones[i] = (Millo_Menu_Opcion *) malloc(sizeof(Millo_Menu_Opcion));
        (*menu)->opciones[i]->texto = (char *) calloc(100,sizeof(char));
        (*menu)->opciones[i]->font = TTF_OpenFont(MILLO_FONT_MENU, 36);
        (*menu)->opciones[i]->color = NULL;
        (*menu)->opciones[i]->posicion = NULL;
        strcpy((*menu)->opciones[i]->texto,opciones[i]);
    }
}

void Millo_Texto_Carga(Millo_Menu_Data **menu, const char **opciones){ // La diferencia es el tamano del texto y la posicion
    (*menu)->indicador = 0;
    (*menu)->resaltado = 0;

    for(int i = 0;i < MILLO_MENU_MAX;i++){
        SDL_Rect *dst = (SDL_Rect * )malloc(sizeof(SDL_Rect));
        dst->x = 30;
        dst->y = 30 + (20* i);

        (*menu)->opciones[i] = (Millo_Menu_Opcion *) malloc(sizeof(Millo_Menu_Opcion));
        (*menu)->opciones[i]->texto = (char *) calloc(100,sizeof(char));
        (*menu)->opciones[i]->font = TTF_OpenFont(MILLO_FONT_MENU, 16);
        (*menu)->opciones[i]->color = NULL;
        (*menu)->opciones[i]->posicion = dst;
        strcpy((*menu)->opciones[i]->texto,opciones[i]);
    }
}