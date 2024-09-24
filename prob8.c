#include "chess.h"
#include "figures.h"
#include <string.h>

char* nullSquare[] = {
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  "                                                          ",
  0
};


char** inicializarTablero() {
    char **fila1 = repeatH(join(whiteSquare, reverse(whiteSquare)), 4);
    char **fila2 = reverse(fila1);
    char **unionFilas = up(fila1, fila2);
    char **tablero = repeatV(unionFilas, 4);
    
    return tablero;
}

char** reemplazar(char **tablero, char **figura, int posX, int posY) {
    int i = 0;
    while (figura[i] != 0) {
        strncpy(tablero[posY + i], figura[i], strlen(figura[i]));  
        i++;
    }
    return tablero;
}

void colocarFiguras(int posX, int posY, char** figura, char **color, char** tablero) {
    char **ubicacionX = nullSquare;
    char **ubicacionY = nullSquare;
    char **ubicacionFinal;
    
    if (posX == 0) {
        ubicacionX = figura;
    } else {
        for (int i = 1; i < posX; i++) {
            ubicacionX = join(ubicacionX, nullSquare); 
        }
        if (posY == 0) {
            ubicacionFinal = join(ubicacionX, figura);
        } else {
            ubicacionFinal = join(ubicacionX, figura);
            ubicacionY = join(ubicacionX, nullSquare);
            for (int i = 1; i < posY; i++) {
                ubicacionFinal = up(ubicacionY, ubicacionFinal);
            }
        }
    }
    tablero = reemplazar(tablero, ubicacionFinal, posX, posY);
}

void display() {
    char **tablero = inicializarTablero();

    colocarFiguras(7, 3, queen, whiteSquare, tablero);
    colocarFiguras(7, 7, pawn, whiteSquare, tablero);
    colocarFiguras(1, 1, pawn, whiteSquare, tablero);
    
    interpreter(tablero);
}
