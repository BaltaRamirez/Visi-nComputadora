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


double ocurrence(double r, const cv::Mat& matrizGrises);
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

	//leer la imagen
	Mat imagen = imread("C:/Users/HOLA/Desktop/Balta/Visual Studio/HolaMundo/fogata.png");

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
	double L = 256; //Maximo valor de r 
	double s = 0;	//intensidad de salida

	double salidaNivelGris = 0;
	double multiplicacion = 0;
	double totalPixeles = filas * columnas;
	double pdf = 0;
	double cdf = 0; 
	double nk = 0;
	double sk = 0;
	double r = 0;

	vector<double> myvector(L);
	vector<double> myvectorAux(L);
	

	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;
		
	
	//Para calcular Histograma y aplicar ecualización
	for (int x = 0; x < matrizGrises.rows; x++) {
		for (int y = 0; y < matrizGrises.cols; y++) {
			Scalar intensity = matrizGrises.at<uchar>(x, y);
			r = intensity.val[0];		//nivel de gris
			for (unsigned i = 0; i < myvector.size(); i++) {
				
				//¿Es igual el valor de escala de grises a la intensidad?
				if (myvector.at(i) == r) {	
					nk = ocurrence(r, matrizGrises);	//Obtener el número de ocurrencias
					
					pdf = nk / totalPixeles;
					cdf += pdf;
					multiplicacion = (L - 1)*cdf;
					salidaNivelGris = rint(multiplicacion);
					//sk += nk;
					
					cout << myvector.at(i) << " | " << nk << " | " << pdf << " | " << cdf << " | " << multiplicacion << " | " << salidaNivelGris << endl;
					myvector.erase(myvector.begin()+i);	//Eliminar el valor de escala de grises para evitar repetir búsqueda de ocurrencias
					//myvectorAux.insert(myvectorAux.begin()+i, nk);
					//cout << myvectorAux.at(i) << endl;
				}
				
			}
			//matrizGrises1.at<uchar>(x, y) = salidaNivelGris;
		}
	}
	
	//cout << myvectorAux.size() << endl;
		
	
		
	/*
	String histogram = "Histogram"; //Nombre de la ventana
	namedWindow(histogram, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(histogram, matrizGrises1); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	//destroyWindow(windowName);//destruir la ventana creada
	*/

	return 0;
}

double ocurrence(double r, const cv::Mat& matrizGrises) {
	double nk = 0;
	double rk = 0;

	for (int i = 0; i < matrizGrises.rows; i++) {
		for (int j = 0; j < matrizGrises.cols; j++) {
			Scalar intensity2 = matrizGrises.at<uchar>(i, j);
			rk = intensity2.val[0];

			if (r == rk) {
				nk++;
			}
		}
	}

	return nk;
}