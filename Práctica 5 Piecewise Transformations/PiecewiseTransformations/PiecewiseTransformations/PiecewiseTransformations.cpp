/********************************************************************/
/*	Program Assignment: Programa #5 							  	*/
/*	Name: José Baltazar Ramírez Rodríguez							*/
/*	Date: 01 de marzo de 2018										*/
/*	Description: Programa para mejorar la calidad de una imagen		*/
/*																	*/
/********************************************************************/

//#include "stdafx.h"
#include "pch.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>	
#include <iostream>
#include <string>
#include <math.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

	//leer la imagen
	Mat imagen = imread("C:/Users/HOLA/Desktop/Balta/Visual Studio/HolaMundo/GM_GreyScaleCorrupted.png");

	if (imagen.empty()) // Verificar que se haya cargado la imagen
	{
		cout << "No se pudo abrir o encontrar la imagen." << endl;
		system("pause");
		return -1;
	}

	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	Mat matrizGrises = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises1 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises1, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises2 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises2, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises3 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises3, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises4 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises4, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises5 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises5, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises


	String escalaGrises = "Escala de grises"; //Nombre de la ventana
	namedWindow(escalaGrises, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(escalaGrises, matrizGrises); // Mostrar la imagen dentro de la ventana en escala de grises antes de ser tratada
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada

	double L = 256; //Maximo valor de r 
	double s = 0;	//intensidad de salida

/*-----------------------------------------CONTRAST STRETCHING------------------------------*/

	/*Valores para realizar el contrast stretching*/
	double r1 = 50;
	double r2 = 100;
	double s1 = 50;
	double s2 = 200;

	double minimo = 0;
	double maximo = 255;
	
	//Para Contrast Stretching 
	for (int x = 0; x < matrizGrises.rows; x++) {
		for (int y = 0; y < matrizGrises.cols; y++) {
			Scalar intensity = matrizGrises.at<uchar>(x, y);
			double r = intensity.val[0];
			if (0 <= r && r <= r1) {
				s = (s1 / r1)*r;
				matrizGrises.at<uchar>(x, y) = s;
			}
			else if (r1 < r && r <= r2) {
				s = ((s2 - s1) / (r2 - r1)) * (r - r1) + s1;
				matrizGrises.at<uchar>(x, y) = s;
			}
			else if (r2 < r && r <=255){
				s = ((255 - s2) / (255 - r2))*(r - r2) + s2;
				matrizGrises.at<uchar>(x, y) = s;
			}
			
		}
	}
	
	String contrastStreching = "Contrast Stretching"; //Nombre de la ventana
	namedWindow(contrastStreching, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(contrastStreching, matrizGrises); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada

	/*-----------------------------------------INTENSITY-LEVEL SLICING------------------------------*/
	double A = 5;
	double B = 50;


	for (int x = 0; x < matrizGrises1.rows; x++) {
		for (int y = 0; y < matrizGrises1.cols; y++) {
			Scalar intensity = matrizGrises1.at<uchar>(x, y);
			double r = intensity.val[0];
			if (A < r && r < B) {	//¿Se encuentra la intensidad del pixel dentro del rango de A y B?
				matrizGrises1.at<uchar>(x, y) = 255;
			}
			else {
				matrizGrises1.at<uchar>(x, y) = 0;
			}
		}
	}

	String intensityLevelSlicing = "Intensity-Level Slicing"; //Nombre de la ventana
	namedWindow(intensityLevelSlicing, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(intensityLevelSlicing, matrizGrises1); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada



	//Para Linear Transformation
	for (int x = 0; x < matrizGrises2.rows; x++) {
		for (int y = 0; y < matrizGrises2.cols; y++) {
			Scalar intensity = matrizGrises2.at<uchar>(x, y);
			double r = intensity.val[0];
			s = L - 1 - r;
			matrizGrises2.at<uchar>(x, y) = s;
		}
	}

	String windowName1 = "Linear Transformation"; //Nombre de la ventana
	namedWindow(windowName1, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName1, matrizGrises2); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada

	double c = 20;
	//Logarithmic Transform
	for (int x = 0; x < matrizGrises3.rows; x++) {
		for (int y = 0; y < matrizGrises3.cols; y++) {
			Scalar intensity = matrizGrises3.at<uchar>(x, y);
			double r = intensity.val[0];
			s = c * log(1 + r);
			if (s <= 255) {
				matrizGrises3.at<uchar>(x, y) = s;
			}
			else if (s > 255) {
				matrizGrises3.at<uchar>(x, y) = 255;
			}
		}
	}

	String windowName3 = "Logarithmic Transform"; //Nombre de la ventana
	namedWindow(windowName3, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName3, matrizGrises3); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada



	//Power Law Transform
	double gamma = 0.5;
	c = 15;
	for (int x = 0; x < matrizGrises.rows; x++) {
		for (int y = 0; y < matrizGrises.cols; y++) {
			Scalar intensity = matrizGrises.at<uchar>(x, y);
			double r = intensity.val[0];
			s = c * pow(r, gamma);
			if (s <= 255) {
				matrizGrises.at<uchar>(x, y) = s;
			}
			else if (s > 255) {
				matrizGrises.at<uchar>(x, y) = 255;
			}

		}
	}
	
		String windowName4 = "Power Law Transform"; //Nombre de la ventana
		namedWindow(windowName4, WINDOW_AUTOSIZE); // Crear la ventana
		imshow(windowName4, matrizGrises); // Mostrar la imagen dentro de la ventana
		waitKey(0);
		//destroyWindow(windowName);//destruir la ventana creada
		


	return 0;
}
