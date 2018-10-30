#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


const int filas=5;
const int columnas=5;
const int barcos=5;


void cargaMatrizPalabras(int tablero[][columnas], int barcos);
void muestraMatrizPalabras(int tablero[][columnas], int barcos);
void muestraMatrizEnteros(int tablero[][columnas], int filas, int columnas);
//int buscaPalabra(int matChar[][columnas], int validos, char palabraBuscada[]);

int main (void)
{
  getchar( );
  int tablero[filas][columnas];
  cargaMatrizPalabras(tablero, barcos);
  muestraMatrizEnteros(tablero, filas, columnas);
  return 0;
}

void cargaMatrizPalabras(int tablero[][columnas], int barcos)
{
    int i=0;
    while((i<barcos))
    {
        srand(time(NULL));
        int fila = rand() % 4;
        int columna = rand() % 4;
        tablero[fila][columna]=1;
        i++;
    }
}

void muestraMatrizPalabras(char tablero[][columnas],int validos)
{
    int i=0;
    for (size_t j = 0; j < validos; j++) {
      for (size_t k = 0; k < validos; k++) {
        printf("%s\n", matChar[i]);
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
                printf("[0%d]", tablero[i][j]);
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

//
// int buscaPalabra(char matChar[][columnas], int validos, char palabraBuscada[])
// {
//     int i=0, esta=0;
//     while((i<validos)&&(esta==0))
//     {
//         if(strcmp(matChar[i], palabraBuscada)==0)
//         {
//             esta=1;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     return esta;
// }
