#ifndef MILLO_PLAYER_DATA_H
    #define MILLO_PLAYER_DATA_H

    /**
        Cada entero en esta estructura define la ubicacion actual del jugador en el juego.

        Pantalla almacena informacion acerca de la Pantalla Actual donde se encuentra el jugador.
        El codigo de la pantalla es utilizado posteriormente por el motor del juego para dibujar los elementos correspondientes.

        Menu almacena informacion acerca de la opcion seleccionada por el jugador dentro de la pantalla.
        Util para dibujar algun indicador grafico que especifique claramente cual opcion del menu esta seleccionandose.

        Pregunta almacena el indice de la Pregunta Actual que debe contestar el jugador, sin embargo solo entra en accion si la Pantalla
        corresponde a la Pantalla de Pregunta.
    */

    typedef struct Millo_Player_Data {
        unsigned short int pantalla;
        unsigned short int menu;
        unsigned int pregunta;
    } Millo_Player_Data;

    // TODO: implementar SAVE y LOAD states basado en esta estructura.
#endif