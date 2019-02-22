/********************************************************************/
/*	Program Assignment: Programa #1 							  	*/
/*	Name: José Baltazar Ramírez Rodríguez							*/
/*	Date: 05 de febrero de 2018										*/
/*	Description: Programa para detectar bordes de una imagen		*/
/*				 y mostrar sus coordenadas							*/
/********************************************************************/

/********************************************************************/
/* Compilation instructions											*/
/* ejecutar en consola: gcc borde.c -o borde						*/
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define columnas 10
#define filas 8
#define TRUE 1
#define FALSE 0

typedef struct Posiciones
{
	int fil;
	int col;
	int region;

}Posiciones;
int region = 1;
int vecino = 0;
int main(int argc, char const *argv[])
{
	int matriz[filas][columnas];
	//Posiciones posicionesMatriz[20];
	Posiciones posicionesMatriz[15] = {0};
	int i=0;
	int j=0;


	//Llenar la matriz de 0's
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			matriz[i][j] = 0;
		}
	}

	//Asignando valores de 1 a la matriz
	matriz[2][2] = 1;
	matriz[2][3] = 1;
	matriz[2][4] = 1;
	matriz[2][5] = 1;
	matriz[3][2] = 1;
	matriz[3][5] = 1;
	matriz[4][2] = 1;
	matriz[4][5] = 1;
	matriz[5][2] = 1;
	matriz[5][3] = 1;
	matriz[5][4] = 1;
	matriz[5][5] = 1;

	 matriz[2][6] = 1;
	 matriz[2][7] = 1;
	 matriz[2][8] = 1;
	 matriz[3][6] = 1;
	 matriz[3][8] = 1;
	 matriz[4][6] = 1;
	 matriz[4][8] = 1;
	 matriz[5][6] = 1;
	 matriz[5][7] = 1;
	 matriz[5][8] = 1;
	
	
	

	
	//Visualizar matriz
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf(" %d ", matriz[i][j]);
		}
		printf("\n");
	}

	printf("-----------------------------\n");
	
	
	for(i = 0; i < filas; i++)
	{
		for(j = 0; j < columnas; j++)
		{
			
			//if(vecino != TRUE)
			//{
			//Para encontrar un uno!
				if(matriz[i][j] == 1)
				{
					//Algun vecino es 0?
					if(matriz[i-1][j] == 0 || matriz[i][j-1] == 0 || matriz[i+1][j] == 0 || matriz[i][j+1] == 0 || matriz[i-1][j-1] == 0 || matriz[i-1][j+1] == 0 || matriz[i+1][j-1] == 0 || matriz[i+1][j+1] == 0)
					{
						
						posicionesMatriz[i].fil = i;
						posicionesMatriz[i].col = j;
						posicionesMatriz[i].region = region;
									
					}
					else
					{
						vecino = FALSE;
						printf("\n");
					}
					printf(" %d,%d", posicionesMatriz[i].fil, posicionesMatriz[i].col);

				}
			//}
		}
			printf("\n");
	}


	return 0;
}