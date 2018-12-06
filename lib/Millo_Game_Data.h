#include "Millo_Player_Data.h"
#include "Millo_Menu_Data.h"

#ifndef MILLO_GAME_DATA_H
    #define MILLO_GAME_DATA_H

    /**
        Esta estructura representa el contexto actual del juego.

        Contiene la data del jugador, el menu y las pregunta actual.
    */

    typedef struct Millo_Game_Data {
        Millo_Player_Data *player;
        Millo_Menu_Data *menu;
        unsigned short int dibujar;     // Indica si la pantalla debe refrescarse 
    } Millo_Game_Data;
#endif