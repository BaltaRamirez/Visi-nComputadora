#include <stdio.h>
#include <stdlib.h>
#ifndef filas
#define filas 3
#endif
#ifndef columnas
#define columnas 3
#endif

int i = 0;
int j = 0;
void sumar(int matriz1[filas][columnas], int matriz2[filas][columnas]);
void restar(int matriz1[filas][columnas], int matriz2[filas][columnas]);
void multiplicar(int matriz1[filas][columnas], int matriz2[filas][columnas]);
void multiplicarVectorMatriz(int vector[][columnas], int matriz1[filas][columnas]);
void multiplicarEscalarMatriz(int escalar, int matriz1[filas][columnas]);
void multiplicarEscalarVector(int escalar, int vectorFila[][columnas]);

int main(int argc, char const *argv[])
{

	int matriz1[filas][columnas] = {{1, 2, 3},
								    {4, 5, 6},
									{7, 8, 9}};


	int matriz2[filas][columnas] = {{7, 8, 9},
									{10, 11, 12},
									{7, 8, 9}};

	int vectorFila[1][columnas] = {-4, 5, 8};


	int escalar = 2;
	printf("Suma:\n");
	sumar(matriz1, matriz2);
	printf("-------------\n");
	printf("Resta:\n");
	restar(matriz1, matriz2);
	printf("-------------\n");
	printf("Multiplicacion:\n");
	multiplicar(matriz1, matriz2);
	printf("-------------\n");
	printf("Multiplicacion Vector Fila por Matriz:\n");
	multiplicarVectorMatriz(vectorFila, matriz1);
	printf("-------------\n");
	printf("Multiplicacion Escalar por Matriz:\n");
	multiplicarEscalarMatriz(escalar, matriz1);
	printf("Multiplicacion Escalar por Vector:\n");
	multiplicarEscalarVector(escalar, vectorFila);
	
	return 0;
}


void sumar(int matriz1[filas][columnas], int matriz2[filas][columnas])
{	
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf(" %d", matriz1[i][j] + matriz2[i][j]);
		}
		printf("\n");
	}

}
void restar(int matriz1[][columnas], int matriz2[][columnas])
{
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf(" %d", matriz1[i][j] - matriz2[i][j]);
		}
		printf("\n");
	}

}

void multiplicar(int matriz1[filas][columnas], int matriz2[filas][columnas])
{

	int matrizAuxiliar[filas][columnas] = {0};
	int k = 0;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			for(k = 0; k < columnas; k++){
				matrizAuxiliar[i][j] = matrizAuxiliar[i][j] + matriz1[i][k] * matriz2[k][j];
			}
			printf(" %d", matrizAuxiliar[i][j]);
		}
		printf("\n");
	}
	

}
void multiplicarVectorMatriz(int vectorFila[][columnas], int matriz1[filas][columnas])
{
	int matrizAuxiliar[filas][columnas] = {0};
	int k = 0;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			for(k = 0; k < columnas; k++){
				matrizAuxiliar[i][j] = matrizAuxiliar[i][j] + vectorFila[i][k] * matriz1[k][j];
			}
			printf(" %d", matrizAuxiliar[i][j]);
		}
		printf("\n");
	}

}
void multiplicarEscalarMatriz(int escalar, int matriz1[filas][columnas])
{
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf(" %d", escalar*matriz1[i][j]);
		}
		printf("\n");
	}

}
void multiplicarEscalarVector(int escalar, int vectorFila[][columnas])
{
	for(i = 0; i < 1; i++){
		for(j = 0; j < columnas; j++){
			printf(" %d", escalar*vectorFila[i][j]);
		}
		printf("\n");
	}

}

