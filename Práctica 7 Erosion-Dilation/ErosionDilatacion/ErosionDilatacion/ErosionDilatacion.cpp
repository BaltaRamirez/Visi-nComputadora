#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const int filas = 5;
	const int columnas = 6;
	const int filEstruct = 3;
	const int colEstruct = 3;
	double matrizOriginal[filas][columnas] = { 0 };
	double matrizDilatada[filas][columnas] = { 0 };


	matrizOriginal[0][0] = 1;
	matrizOriginal[1][1] = 1;
	matrizOriginal[3][1] = 1;
	matrizOriginal[2][2] = 1;
	matrizOriginal[3][2] = 1;
	matrizOriginal[1][3] = 1;
	matrizOriginal[2][3] = 1;
	matrizOriginal[3][3] = 1;
	matrizOriginal[1][4] = 1;
	matrizOriginal[2][4] = 1;
	matrizOriginal[3][4] = 1;

	cout << "\t\t Imagen Original" << endl;
	cout << "\n" << endl;

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			cout << matrizOriginal[i][j] << " ";
		}
		cout << "\n" << endl;
	}

	/*Se define la estructura con la que se va a dilatar*/

	double estructura[filEstruct][colEstruct] = { 0 };

	cout << "\t\t Estructura " << endl;
	cout << "\n" << endl;
	
	estructura[0][1] = 1;
	estructura[1][1] = 1;
	estructura[2][1] = 1;
	double centroX = (int)filEstruct / 2;
	double centroY = (int)colEstruct / 2;
	

	for (int i = 0; i < filEstruct; i++) {
		for (int j = 0; j < colEstruct; j++) {
			cout << estructura[i][j] << " ";
		}
		cout << "\n" << endl;
	}


	/*Para verificar que la estructura se encuentre en la matriz*/
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			
		}
	}
	


	
	cout << "\t\t Imagen Dilatada" << endl;
	cout << "\n" << endl;

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			cout << matrizDilatada[i][j] << " ";
		}
		cout << "\n" << endl;
	}

}

