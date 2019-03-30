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

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{

	//leer la imagen
	Mat imagen = imread("C:/Users/HOLA/Desktop/Balta/Visual Studio/HolaMundo/reduced size/fogata.png");
	Mat imagenReferencia = imread("C:/Users/HOLA/Desktop/Balta/Visual Studio/HolaMundo/reduced size/GM_GreyScaleHCRS.png");
	Mat imagenHistogramMatching = imread("C:/Users/HOLA/Desktop/Balta/Visual Studio/HolaMundo/reduced size/GM_GreyScaleLCRS.png");

	if (imagen.empty()) // Verificar que se haya cargado la imagen
	{
		cout << "No se pudo abrir o encontrar la imagen." << endl;
		system("pause");
		return -1;
	}


	int filas = imagen.rows;
	int columnas = imagen.cols;
	//Se crean matrices para trabajar con ellas en escala de grises
	Mat matrizGrises = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises1 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagenReferencia, matrizGrises1, COLOR_BGR2GRAY);	//Para convertir la imagen de referencia a escala de grises
	Mat matrizGrises2 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagenHistogramMatching, matrizGrises2, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises

	/*Para mostrar la imagen en escala de grises*/
	String escalaGrises = "Escala de grises"; //Nombre de la ventana
	namedWindow(escalaGrises, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(escalaGrises, matrizGrises); // Mostrar la imagen dentro de la ventana en escala de grises antes de ser tratada
	waitKey(0);
	
	/*Variables necesarias para calcular el histograma*/
	double s = 0;	//intensidad de salida
	double totalPixeles = filas * columnas;
	double r = 0;	//Intensidad del pixel
	double pdf = 0;
	double cdf = 0;
	double nk = 0;
	double sk = 0;
	double multiplicacion = 0;
	double L = 256; //Maximo valor de r 
	vector<double> myvector(L);		//Vector de 255 para guardar aqui la cantidad de ocurrencias
	vector<double> salidaNivelGris(L);	//Vector de 255 para almacenar la nueva salida para la imagen ecualizada


	/*Llenar el arreglo para las ocurrencias de forma ordenada para cada nivel de entrada de gris*/
	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;

	
		
	
	//Para guardar los valores de las ocurrencias
	for (int x = 0; x < matrizGrises.rows; x++) {
		for (int y = 0; y < matrizGrises.cols; y++) {
			Scalar intensity = matrizGrises.at<uchar>(x, y);
			r = intensity.val[0];		//intensidad del pixel
			myvector.at(r) = myvector.at(r) + 1;	//Donde encuentre ese nivel de intensidad en el vector, le sumará 1 para calcular total de ocurrencias
		}
	}


	//Para calcular el histograma
	for (int i = 0; i < myvector.size(); i++) {

		pdf = myvector.at(i) / totalPixeles;
		cdf += pdf;
		multiplicacion = (L - 1)*cdf;
		salidaNivelGris.at(i) = rint(multiplicacion);

		if (salidaNivelGris.at(i) > L)	//¿Se encuentra fuera del nivel máximo en escala de grises? Si es así, igualar al nivel máximo (255)
			salidaNivelGris.at(i) = L - 1;
			
		
		cout << i << " " << myvector.at(i) << " PDF " << pdf << " CDF " << cdf << " " << salidaNivelGris.at(i) << endl;

	}

	cout << "\n" << endl;
	
	//Para ecualizar la imagen
	for (int x = 0; x < matrizGrises.rows; x++) {
		for (int y = 0; y < matrizGrises.cols; y++) {
			Scalar intensity = matrizGrises.at<uchar>(x, y);
			r = intensity.val[0];		//intensidad del pixel
			for (int i = 0; i < myvector.size(); i++) {
				if(r == i)		//¿Encontró la intensidad dentro del vector de salida? Asignar nuevo valor de salida para esa intensidad
					matrizGrises.at<uchar>(x, y) = salidaNivelGris.at(r);
			}
		}
	}

	String histogram = "Histogram"; //Nombre de la ventana
	namedWindow(histogram, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(histogram, matrizGrises); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	

	/*-----------------------------HISTOGRAM MATCHING-----------------------------*/

	vector<double> myvectorAux(L);		//Vector de 255 para guardar aqui la cantidad de ocurrencias de la imagen de referencia para histogram Matching
	vector<double> myvectorAuxHM(L);		//Vector de 255 para guardar aqui la cantidad de ocurrencias de la imagen final para histogram Matching
	vector<double> salidaNivelGrisReferencia(L);	//Vector de 255 para almacenar la nueva salida para la imagen de referencia
	vector<double> salidaNivelGrisHM(L);	//Vector de 255 para almacenar la salida de la imagen con Histogram Matching

	/*Limpiar variables para cálculo nuevo del histograma de la imagen de referencia*/
	pdf = 0;
	cdf = 0;
	nk = 0;
	sk = 0;
	multiplicacion = 0;

	/*Para mostrar la imagen de referencia en escala de grises*/
	String escalaGrisesReferencia = "Escala de grises de Referencia"; //Nombre de la ventana
	namedWindow(escalaGrisesReferencia, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(escalaGrisesReferencia, matrizGrises1); // Mostrar la imagen dentro de la ventana en escala de grises antes de ser tratada
	waitKey(0);

		/*Llenar el arreglo para las ocurrencias de forma ordenada para cada nivel de entrada de gris*/
	for (unsigned i = 0; i < myvectorAux.size(); i++)
		myvectorAux.at(i) = i;

	//Se calcula histograma de imagen de referencia
	//Para guardar los valores de las ocurrencias
	for (int x = 0; x < matrizGrises1.rows; x++) {
		for (int y = 0; y < matrizGrises1.cols; y++) {
			Scalar intensity = matrizGrises1.at<uchar>(x, y);
			r = intensity.val[0];		//intensidad del pixel
			myvectorAux.at(r) = myvectorAux.at(r) + 1;	//Donde encuentre ese nivel de intensidad en el vector, le sumará 1 para calcular total de ocurrencias
		}
	}

	//Para calcular el histograma de la imagen de referencia
	for (int i = 0; i < myvectorAux.size(); i++) {

		pdf = myvectorAux.at(i) / totalPixeles;
		cdf += pdf;
		multiplicacion = (L - 1)*cdf;
		salidaNivelGrisReferencia.at(i) = rint(multiplicacion);

		if (salidaNivelGrisReferencia.at(i) > L)	//¿Se encuentra fuera del nivel máximo en escala de grises? Si es así, igualar al nivel máximo (255)
			salidaNivelGrisReferencia.at(i) = L - 1;


		cout << i << " " << myvectorAux.at(i) << " PDF " << pdf << " CDF " << cdf << " " << salidaNivelGrisReferencia.at(i) << endl;

	}


	/*Limpiar variables para cálculo nuevo del histograma de la imagen que se quiere hacer match con los nuevos datos de entrada de la imagen de referencia*/
	pdf = 0;
	cdf = 0;
	nk = 0;
	sk = 0;
	multiplicacion = 0;


	/*Llenar el arreglo para las ocurrencias de forma ordenada para cada nivel de entrada de gris*/
	for (unsigned i = 0; i < myvectorAuxHM.size(); i++)
		myvectorAuxHM.at(i) = i;

	//Para guardar los valores de las ocurrencias de la imagen con la que se aplicaron los valores de la imagen de referencia
	for (int x = 0; x < matrizGrises2.rows; x++) {
		for (int y = 0; y < matrizGrises2.cols; y++) {
			Scalar intensity = matrizGrises2.at<uchar>(x, y);
			r = intensity.val[0];		//intensidad del pixel
			myvectorAuxHM.at(r) = myvectorAuxHM.at(r) + 1;	//Donde encuentre ese nivel de intensidad en el vector, le sumará 1 para calcular total de ocurrencias
		}
	}

	cout << "\n" << endl;

	//Para calcular el histograma de la imagen de referencia
	for (int i = 0; i < myvectorAuxHM.size(); i++) {

		pdf = myvectorAuxHM.at(i) / totalPixeles;
		cdf += pdf;
		multiplicacion = (L - 1)*cdf;
		salidaNivelGrisHM.at(i) = rint(multiplicacion);

		if (salidaNivelGrisHM.at(i) > L)	//¿Se encuentra fuera del nivel máximo en escala de grises? Si es así, igualar al nivel máximo (255)
			salidaNivelGrisHM.at(i) = L - 1;


		cout << i << " " << myvectorAuxHM.at(i) << " PDF " << pdf << " CDF " << cdf << " " << salidaNivelGrisHM.at(i) << endl;

	}


	//Para ecualizar la imagen de bajo contraste con la referencia (alto contraste)
	for (int x = 0; x < matrizGrises2.rows; x++) {
		for (int y = 0; y < matrizGrises2.cols; y++) {
			Scalar intensity = matrizGrises2.at<uchar>(x, y);
			r = intensity.val[0];		//intensidad del pixel
			for (int i = 0; i < myvectorAuxHM.size(); i++) {
				if (r == i)		//¿Encontró la intensidad dentro del vector de salida? Asignar nuevo valor de salida para esa intensidad
					matrizGrises2.at<uchar>(x, y) = salidaNivelGrisHM.at(r);
			}
		}
	}
	
	/*Para mostrar la imagen ya con el Histogram Matching en escala de grises*/
	String histogramMatching = "Histogram Matching"; //Nombre de la ventana
	namedWindow(histogramMatching, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(histogramMatching, matrizGrises2); // Mostrar la imagen dentro de la ventana en escala de grises antes de ser tratada
	waitKey(0);
	
	

	return 0;
}
