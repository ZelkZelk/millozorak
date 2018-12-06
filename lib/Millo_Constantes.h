#ifndef MILLO_CONSTANTES_H
    #define MILLO_CONSTANTES_H
    #define MILLO_TITLE "Millo"
    #define MILLO_VIDEO_H 480
    #define MILLO_VIDEO_W 640
    #define MILLO_MENU_MAX 8

    /* 
        Menues, Codigo y Opciones
        Cada menu debe tener MILLO_MENU_MAX elementos. Aquellos vacios no se dibujan.
     */

    #define MILLO_PANTALLA_MAIN 0
    #define MILLO_MENU_MAIN (const char*[MILLO_MENU_MAX]) { "Continuar", "Nuevo Juego", "Instrucciones", "Salir", "", "", "", "" }

    #define MILLO_PANTALLA_INSTRUCCIONES 1
    #define MILLO_MENU_INSTRUCCIONES (const char*[MILLO_MENU_MAX]) { "Muevete con las flechas arriba y abajo","Presiona ENTER para confirmar seleccion","Elige la respuesta correcta y gana puntos","Buena suerte!", "", "", "", "" }

    #define MILLO_PANTALLA_PREGUNTAS 2
    //#define MILLO_MENU_PREGUNTAS (const char*[MILLO_MENU_MAX]) { "Our base is under attack!","","","", "", "", "", "" } 
    // El menu se va a recargar con las preguntas

    #define MILLO_PANTALLA_SIN_CONTINUE 3
    #define MILLO_MENU_SIN_CONTINUE (const char*[MILLO_MENU_MAX]) { "No se ha encontrado Archivo de Continue","","","", "", "", "", "" }

    /*
        Archivos Graficos
    */

    #define MILLO_GFX_MENU_ARROW "gfx/menu.bmp"

    /*
        Fuentes
    */

    #define MILLO_FONT_MENU "fonts/Roboto-MediumItalic.ttf"
#endif