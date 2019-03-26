/********************************************************************/
/*	Program Assignment: Programa #6 							  	*/
/*	Name: José Baltazar Ramírez Rodríguez							*/
/*	Date: 05 de marzo de 2018										*/
/*	Description: Programa para calcular el histograma de una imagen	*/
/*				y mejorarla utilizando Histogram Matching			*/
/********************************************************************/

//#include "stdafx.h"
#include "pch.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>	
#include <iostream>
#include <string>
#include <vector>

//double obtenerSalidaGris(vector<double> &myvectorAux, double totalPixeles);


double pdf = 0;
double cdf = 0;
double nk = 0;
double sk = 0;
double multiplicacion = 0;
double L = 256; //Maximo valor de r 


using namespace cv;
using namespace std;

double obtenerSalidaGris(vector<double> &myvectorAux, double totalPixeles) {

	double salidaGris = 0;
	

	for (unsigned i = 0; i < myvectorAux.size(); i++) {
		pdf = myvectorAux.at(i) / totalPixeles;
		
		cdf += pdf;
		
		multiplicacion = (L - 1)*cdf;
		
		salidaGris = rint(multiplicacion);
		if (salidaGris > L)
			salidaGris = L - 1;
		cout << i << " " << myvectorAux.at(i) << " PDF " << pdf << " CDF " << cdf << " " << salidaGris << endl;
		

		
	}
	//cout << " PDF " << pdf << " CDF " << cdf << " " << salidaGris << endl;
	return salidaGris;
}

int main(int argc, char** argv)
{

	//leer la imagen
	Mat imagen = imread("C:/Users/HOLA/Desktop/Balta/Visual Studio/HolaMundo/GM_GreyScale.png");

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

	/*
	String escalaGrises = "Escala de grises"; //Nombre de la ventana
	namedWindow(escalaGrises, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(escalaGrises, matrizGrises); // Mostrar la imagen dentro de la ventana en escala de grises antes de ser tratada
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada
	*/
	
	double s = 0;	//intensidad de salida
	double totalPixeles = filas * columnas;
	double r = 0;	//Intensidad del pixel
	double salidaNivelGris = 0;


	vector<double> myvector(L);		//Vector de 255 para guardar aqui la cantidad de ocurrencias
	vector<double> myvectorAux(L);

	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;

		
	
	//Para guardar los valores de las ocurrencias
	for (int x = 0; x < matrizGrises.rows; x++) {
		for (int y = 0; y < matrizGrises.cols; y++) {
			Scalar intensity = matrizGrises.at<uchar>(x, y);
			r = intensity.val[0];		//intensidad del pixel
			myvector.at(r) = myvector.at(r) + 1;
		}
	}

	myvectorAux = myvector;		//Crear una copia del vector con los valores de ocurrencias

	salidaNivelGris = obtenerSalidaGris(myvectorAux, totalPixeles);

	/*
	//Para calcular el histograma y aplicarlo a la imagen
	for (int x = 0; x < matrizGrises.rows; x++) {
		for (int y = 0; y < matrizGrises.cols; y++) {
		}
	}
	*/
	
		
	/*
	String histogram = "Histogram"; //Nombre de la ventana
	namedWindow(histogram, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(histogram, matrizGrises1); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada
	*/

	return 0;
}
/*
double obtenerSalidaGris(vector<double> &myvectorAux, double totalPixeles) {

	double salidaGris = 0;

	for (unsigned i = 0; i < myvectorAux.size(); i++) {
		pdf = myvectorAux.at(i) / totalPixeles;
		cdf += pdf;
		multiplicacion = (L - 1)*cdf;
		salidaGris = rint(multiplicacion);
		if (salidaGris > L) {
			salidaGris = L - 1;
		}
		cout << i << " " << myvectorAux.at(i) << " PDF " << pdf << " CDF " << cdf << " " << salidaGris << endl;
	}

	return salidaGris;
}
*/