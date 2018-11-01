#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


const int filas=5;
const int columnas=5;
const int barcos=5;

void cargaMatrizPalabras(int tablero[][columnas], int barcos);
void muestraMatrizEnteros(int tablero[][columnas], int filas, int columnas);
int eliminarBarco(int tablero[][columnas], int filas, int columnas);
int buscarBarco(int tablero[][columnas], int barcos);


int main (void)
{
  int tablero[filas][columnas];
  cargaMatrizPalabras(tablero, barcos);
  muestraMatrizEnteros(tablero, filas, columnas);
  buscarBarco(tablero, barcos);
  //muestraMatrizEnteros(tablero, filas, columnas);
  return 0;
}

void cargaMatrizPalabras(int tablero[][columnas], int barcos)
{

  int i=0, j;
  while(i<filas){
      j=0;
      while(j<columnas){
          tablero[i][j]=0;
          j++;
      }
      i++;
  }
    i=0;
    srand(time(NULL));

    while(i<barcos)
    {
        int fila = rand() % 5;
        int columna = rand() % 5;
        if (tablero[fila][columna] == 0) {
          tablero[fila][columna]=1;
          i++;
        }
    }
}

void muestraMatrizEnteros(int tablero[][columnas], int filas, int columnas)
{
    int i=0, j;
    while(i<filas)
    {
        j=0;
        while(j<columnas)
        {
            if (tablero[i][j]<10)
            {
                printf("[%d]", tablero[i][j]);
            }
            else
            {
                printf("[%d]", tablero[i][j]);
            }
            j++;
        }
        printf("\n");
        i++;
    }
}


int buscarBarco(int tablero[][columnas], int barcos)
{
  char filaChar, columnaChar;
  int barcosRestantes = barcos;
  while (barcosRestantes > 0) {
    printf("Ingrese una fila del 1 al 5 \n");
    scanf(" %c", &filaChar);
    int filaIndex = (int)filaChar;
    filaIndex = filaIndex - 49;
    if (barcos < filaIndex || filaIndex < 0) {
      printf("Numero invalido \n");
    } else {
      printf("Ingrese una columna de la A a la E \n");
      scanf(" %c", &columnaChar);
      int columnaIndex = (int)columnaChar;
      columnaIndex = columnaIndex - 65;
      if (columnaIndex < 0 || columnaIndex > barcos) {
        printf("Letra invalida, deben ser en mayusculas \n");
      } else {
        int eliminado = eliminarBarco(tablero, filaIndex, columnaIndex);
        if (eliminado == 1) {
          barcosRestantes = barcosRestantes - 1;
        }
      }
    }
  }
  if (barcosRestantes == 0) {
    printf("Felicitaciones has ganado la partida! \n");
  }
  return 1;
}

int eliminarBarco(int tablero[][columnas], int fila, int columna ) {
  if (tablero[fila][columna] == 1) {
    tablero[fila][columna] = 0;
    printf("Enhorabuena has hundido un barco :) \n");
    //muestraMatrizEnteros(tablero, 5, 5);
    return 1;
  } else {
    printf("Agua!! Vuelve a intentarlo \n");
    //muestraMatrizEnteros(tablero, 5, 5);
  }
  return 0;
}
