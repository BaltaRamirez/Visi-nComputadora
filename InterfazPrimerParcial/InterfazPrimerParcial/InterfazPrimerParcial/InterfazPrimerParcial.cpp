/********************************************************************/
/*	Program Assignment: Aplicación interfaz 						*/
/*	Name: José Baltazar Ramírez Rodríguez							*/
/*	Date: 02 de abril de 2019										*/
/*	Description:													*/
/*				Interfaz de comandos para aplicación de algoritmos	*/
/*				 de Regiones y Vecinos, Affine Transformation		*/
/*		Spatial Transformation, Piecewise Transformation, Histogram */
/*		Histogram Matching, Morfología Matemática.					*/
/********************************************************************/

//#include "stdafx.h"
#include "pch.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>	
#include <iostream>
#include <string>
#include <vector>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{

	double opcion = 0;	//Variable para elegir opcion de procesamiento

	cout << "\t\t INTERFAZ DE COMANDOS PARA PROCESAMIENTO DE IMAGENES " << endl;
	cout << "Que operacion deseas realizar?" << endl;
	cout << "\n" << endl;
	cout << "1. Extraccion de regiones en una imagen binaria" << endl;
	cout << "2. Extraccion de bordes de regiones en una imagen binaria" << endl;
	cout << "3. Transformacion Espacial de Rotacion" << endl;
	cout << "4. Transformacion Espacial de Escala (Scaling)" << endl;
	cout << "5. Transformacion Espacial de Distorsion Vertical (Vertical Shear)" << endl;
	cout << "6. Transformacion Espacial de Distorsion Horizontal (Horizontal Shear)" << endl;
	cout << "7. Transformacion Lineal de Intensidad de Imagen (negativo de una imagen)" << endl;
	cout << "8. Transformacion Logaritmica de Intensidad de Imagen" << endl;
	cout << "9. Transformacion de Potencias de Intensidad de Imagen" << endl;
	cout << "10. Transformacion lineal por partes: Estiramiento de Contraste" << endl;
	cout << "11. Transformacion lineal por partes: Segmentacion de Nivel de Intensidad" << endl;
	cout << "12. Transformacion lineal por partes: Segmentacion por planos de bit" << endl;
	cout << "13. Calculo del histograma de una imagen en escala de grises" << endl;
	cout << "14. Histogram Matching" << endl;
	cout << "15. Erosion de una imagen binaria " << endl;
	cout << "16. Dilatacion de una imagen binaria " << endl;
	cout << "17. Algoritmos Morfologicos: Apertura (Opening) " << endl;
	cout << "18. Algoritmos Morfologicos: Cerradura (Closing) " << endl;
	cout << "19. Algoritmos Morfologicos: Extraccion de contornos " << endl;



	cin >> opcion;	//falta validar opcion numerica



	return 0;
}
