#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int filas=5;
const int columnas=5;

int cargaMatrizPalabras(char matChar[][columnas], int filas);
void muestraMatrizPalabras(char matChar[][columnas], int cantPalabras);
int buscaPalabra(char matChar[][columnas], int validos, char palabraBuscada[]);

int main (void)
{


  getchar( );
  int cantPalabras;
  char matrizPalabras[filas][columnas];
  cantPalabras=cargaMatrizPalabras(matrizPalabras, filas);
  muestraMatrizPalabras(matrizPalabras, cantPalabras);
  return 0;
}

int cargaMatrizPalabras(char matChar[][columnas], int filas)
{
    int i=0;
    char c='s';
    while((i<filas)&&(c=='s'))
    {
        printf("Ingrese la palabra a cargar\n");
        fflush(stdin);
        matChar[i][1]=getchar( );
        i++;
        printf("Cargar otra palabra? s/n\n");
        fflush(stdin);
        scanf("%c", &c);
    }
    if(i>=filas)
        printf("Se alcanzó el máximo de palabras\n");
    return i;
}

void muestraMatrizPalabras(char matChar[][columnas],int validos)
{
    int i=0;
    while(i<validos)
    {
        printf("%s\n", matChar[i]);
        i++;
    }
}

int buscaPalabra(char matChar[][columnas], int validos, char palabraBuscada[])
{
    int i=0, esta=0;
    while((i<validos)&&(esta==0))
    {
        if(strcmp(matChar[i], palabraBuscada)==0)
        {
            esta=1;
        }
        else
        {
            i++;
        }
    }
    return esta;
}
