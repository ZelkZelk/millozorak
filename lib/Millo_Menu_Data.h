#include "Millo_Constantes.h"
#include "Millo_Menu_Opcion.h"

#ifndef MILLO_MENU_DATA_H
    #define MILLO_MENU_DATA_H

    /**
        En este archivo definimos los menues a ser dibujados en cada Pantalla del Juego.
    */

    typedef struct Millo_Menu_Data {
        Millo_Menu_Opcion *opciones[MILLO_MENU_MAX];
        unsigned short int indicador;                   // Indica si dibujamos el indicador de posicion del menu
        unsigned short int resaltado;                   // Indica si le cambiamos el color a la opcion seleccionada
    } Millo_Menu_Data;

    /**
        Resuelve las opciones de un Menu, dando una pantalla. 
    */
   
    void Millo_Menu_Clear(Millo_Menu_Data *menu);
    Millo_Menu_Data *Millo_Menu_Resolver(int pantalla);
    void Millo_Menu_Carga(Millo_Menu_Data **menu, const char **opciones);
    void Millo_Texto_Carga(Millo_Menu_Data **menu, const char **opciones);
    void Millo_Menu_Carga_Preguntas(Millo_Menu_Data **menu);
#endif