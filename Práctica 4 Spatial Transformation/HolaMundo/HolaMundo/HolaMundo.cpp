/********************************************************************/
/*	Program Assignment: Programa #4 							  	*/
/*	Name: José Baltazar Ramírez Rodríguez							*/
/*	Date: 26 de febrero de 2018										*/
/*	Description: Programa para detectar transformar una imagen		*/
/*		utilizando logarithm, power law y linear transformations	*/
/********************************************************************/

//#include "stdafx.h"
#include "pch.h"
#include <C:/opencv/build/include/opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>	
#include <iostream>
#include <string>
#include <math.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// Leer la imagen
	Mat imagen = imread("C:/Users/HOLA/Desktop/Balta/Visual Studio/HolaMundo/fogata.png");

	if (imagen.empty()) // Verificar que se haya cargado la imagen
	{
		cout << "No se pudo abrir o encontrar la imagen." << endl;
		system("pause"); 
		return -1;
	}

	String windowName = "My HelloWorld Window"; //Nombre de la ventana
	namedWindow(windowName, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName, imagen); // Mostrar la imagen dentro de la ventana
	waitKey(0); 
	//destroyWindow(windowName); //destruir la ventana creada

	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	Mat matrizGrises = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises1 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises1, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises2 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises2, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises

	double L = 256; //Maximo valor de r 
	double s = 0;	//intensidad de salida
	
	//Para Linear Transformation
	for (int x = 0; x < matrizGrises.rows; x++) {
		for (int y = 0; y < matrizGrises.cols; y++) {
			Scalar intensity = matrizGrises.at<uchar>(x, y);
			double r = intensity.val[0];
			s = L - 1 - r;
			matrizGrises.at<uchar>(x, y) = s;
		}
	}

	String windowName1 = "Linear Transformation"; //Nombre de la ventana
	namedWindow(windowName1, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName1, matrizGrises); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada

	
	/*Para mostrar la imagen en escala de grises antes de la transformada logarítmica*/
	String windowName2 = "Escala de grises"; //Nombre de la ventana
	namedWindow(windowName2, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName2, matrizGrises1); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	//destroyWindow(windowName); //destruir la ventana creada

	

	double c = 50;
	//Logarithmic Transform
	for (int x = 0; x < matrizGrises1.rows; x++) {
		for (int y = 0; y < matrizGrises1.cols; y++) {
			Scalar intensity = matrizGrises1.at<uchar>(x, y);
			double r = intensity.val[0];
			s = c * log(1 + r);
			if (s <= 255) {
				matrizGrises1.at<uchar>(x, y) = s;
			}
			else if (s >255){
				matrizGrises1.at<uchar>(x, y) = 255;
			}
		}
	}

	String windowName3 = "Logarithmic Transform"; //Nombre de la ventana
	namedWindow(windowName3, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName3, matrizGrises1); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada


	
	//Power Law Transform
	double gamma = 2.5;
	c = 0.001;
	for (int x = 0; x < matrizGrises2.rows; x++) {
		for (int y = 0; y < matrizGrises2.cols; y++) {
			Scalar intensity = matrizGrises2.at<uchar>(x, y);
			double r = intensity.val[0];
			s = c * pow(r, gamma);
			if (s <= 255) {
				matrizGrises2.at<uchar>(x, y) = s;
			}
			else if (s > 255){
				matrizGrises2.at<uchar>(x, y) = 255;
			}
			
		}
	}

	String windowName4 = "Power Law Transform"; //Nombre de la ventana
	namedWindow(windowName4, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName4, matrizGrises2); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada
	

	return 0;
}