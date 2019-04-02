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
#include <fstream>
#include <string>
#include <vector>



using namespace cv;
using namespace std;
double L = 256; //Maximo valor de r 
double s = 0;	//intensidad de salida
void menu();
void transformacionEspacial(Mat& imagen);
void transformacionPartes(Mat& imagen);
void histograma(Mat& imagen);
void histogramMatching(Mat& imagenReferencia, Mat& imagenHistogramMatching);

int main(int argc, char** argv)
{

	int opcion = 0;	//Variable para elegir opcion de procesamiento
	string rutaArchivo = "";
	Mat imagen;
	Mat imagenReferencia;
	Mat imagenHistogramMatching;

	const int filas = 10;
	const int columnas = 10;
	int matriz[filas][columnas] = { 0 };
	int i = 0;
	int j = 0;
	

	do
	{
		menu();

		cin >> opcion;	//falta validar opcion numerica
		system("cls");

		switch (opcion) 
		{
			case 1:
				cout << "\t\t 1.Extraccion de regiones en una imagen binaria" << endl;
				system("pause");
				system("cls");

			break;

			case 2:
				cout << "\t\t 2.Extraccion de bordes de regiones en una imagen binaria" << endl;
				cout << "\n" << endl;
				//Llenar la matriz de 0's
				for (i = 0; i < filas; i++) {
					for (j = 0; j < columnas; j++) {
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


				printf("Matriz Original\n");
				//Visualizar matriz
				for (i = 0; i < filas; i++) {
					for (j = 0; j < columnas; j++) {
						printf(" %d ", matriz[i][j]);
					}
					printf("\n");
				}

				cout << "\n" << endl;
				for (i = 0; i < filas; i++) {
					for (j = 0; j < columnas; j++) {
						if (matriz[i][j] == 1) {
							if (matriz[i - 1][j] == 0 || matriz[i][j - 1] == 0 || matriz[i + 1][j] == 0 || matriz[i][j + 1] == 0 || matriz[i - 1][j - 1] == 0 || matriz[i - 1][j + 1] == 0 || matriz[i + 1][j - 1] == 0 || matriz[i + 1][j + 1] == 0)
							{
								printf("%d,%d | ", i, j);
							}
						}
					}
				}

				system("pause");
				system("cls");

			break;

			case 3:

			break;

			case 4:

			break;

			case 5:

				break;
			case 6:

				break;

			case 7:				/*Transformaciones Espaciales*/
				cout << "\t\t 7.Transformaciones Espaciales" << endl;
				cout << " Teclea el nombre y extension del archivo que deseas procesar" << endl;
				cout << "\n" << endl;
				cin >> rutaArchivo;
				system("cls");
				// Leer la imagen
				imagen = imread("C:/Users/HOLA/Desktop/imagenesEntrada/" + rutaArchivo);
				transformacionEspacial(imagen);
				
				break;

			case 8:				/*Transformaciones por partes*/
				cout << "\t\t 8.Transformacion por partes" << endl;
				cout << " Teclea el nombre y extension del archivo que deseas procesar" << endl;
				cout << "\n" << endl;
				cin >> rutaArchivo;
				system("cls");
				// Leer la imagen
				imagen = imread("C:/Users/HOLA/Desktop/imagenesEntrada/" + rutaArchivo);
				transformacionPartes(imagen);

				break;

			case 9:			/*Histograma*/
				cout << "\t\t 9.Histograma" << endl;
				cout << " Teclea el nombre y extension del archivo que deseas procesar" << endl;
				cout << "\n" << endl;
				cin >> rutaArchivo;
				system("cls");
				// Leer la imagen
				imagen = imread("C:/Users/HOLA/Desktop/imagenesEntrada/" + rutaArchivo);
				histograma(imagen);
				break;

			case 10:		/*Histogram Matching*/
				cout << "\t\t 10.Histogram Matching" << endl;
				cout << " Teclea el nombre y extension del archivo que deseas usar como referencia" << endl;
				cin >> rutaArchivo;
				// Leer la imagen
				imagenReferencia = imread("C:/Users/HOLA/Desktop/imagenesEntrada/" + rutaArchivo);
				cout << "\n" << endl;

				cout << " Teclea el nombre y extension del archivo al que deseas aplicar el matching" << endl;
				cin >> rutaArchivo;
				system("cls");
				// Leer la imagen
				imagenHistogramMatching = imread("C:/Users/HOLA/Desktop/imagenesEntrada/" + rutaArchivo);
				histogramMatching(imagenReferencia, imagenHistogramMatching);
				break;

		}
		
	} while (opcion != 11);

	return 0;
}
void menu() {
	cout << "\t\t INTERFAZ DE COMANDOS PARA PROCESAMIENTO DE IMAGENES " << endl;
	cout << "Que operacion deseas realizar?" << endl;
	cout << "\n" << endl;
	cout << "1. Extraccion de regiones en una imagen binaria" << endl;
	cout << "2. Extraccion de bordes de regiones en una imagen binaria" << endl;
	cout << "3. Transformacion Espacial de Rotacion" << endl;
	cout << "4. Transformacion Espacial de Escala (Scaling)" << endl;
	cout << "5. Transformacion Espacial de Distorsion Vertical (Vertical Shear)" << endl;
	cout << "6. Transformacion Espacial de Distorsion Horizontal (Horizontal Shear)" << endl;
	cout << "7. Transformaciones Espaciales de Imagen" << endl;
	cout << "8. Transformaciones por partes de Imagen" << endl;
	cout << "9. Histograma" << endl;
	cout << "10. Histogram Matching" << endl;

	cout << "11. Salir " << endl;
	cout << "\n " << endl;
}

void transformacionEspacial(Mat& imagen){
	
	string rutaSalida = " ";
	if (imagen.empty()) // Verificar que se haya cargado la imagen
	{
		cout << "No se pudo abrir o encontrar la imagen." << endl;
		system("pause");
		//return -1;
	}

	int filas = imagen.rows;
	int columnas = imagen.cols;
	Mat matrizEscGrises = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizEscGrises, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises1 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises1, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises
	Mat matrizGrises2 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises2, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises



	//Para Linear Transformation
	for (int x = 0; x < matrizGrises.rows; x++) {
		for (int y = 0; y < matrizGrises.cols; y++) {
			Scalar intensity = matrizGrises.at<uchar>(x, y);
			double r = intensity.val[0];
			s = L - 1 - r;
			matrizGrises.at<uchar>(x, y) = s;
		}
	}
	cout << "\t\t TRANSFORMACION LINEAL " << endl;
	cout << "Ingresa nombre y extension de tu imagen de salida con Trans. Lineal" << endl;
	cin >> rutaSalida;
	imwrite("C:/Users/HOLA/Desktop/imagenesSalida/ " + rutaSalida, matrizGrises);
	cout << "\n" << endl;


	cout << "\t\t TRANSFORMACION LOGARITMICA " << endl;
	double c;
	cout << "Ingresa valor de la constante para la transformacion logaritmica" << endl;
	//double c = 50;
	cin >> c;
	//cout << "\n" << endl;

	//Logarithmic Transform
	for (int x = 0; x < matrizGrises1.rows; x++) {
		for (int y = 0; y < matrizGrises1.cols; y++) {
			Scalar intensity = matrizGrises1.at<uchar>(x, y);
			double r = intensity.val[0];
			s = c * log(1 + r);
			if (s <= 255) {
				matrizGrises1.at<uchar>(x, y) = s;
			}
			else if (s > 255) {
				matrizGrises1.at<uchar>(x, y) = 255;
			}
		}
	}
	cout << "Ingresa nombre y extension de tu imagen de salida con Trans. Logaritmica" << endl;
	cin >> rutaSalida;
	imwrite("C:/Users/HOLA/Desktop/imagenesSalida/ " + rutaSalida, matrizGrises1);
	cout << "\n" << endl;


	cout << "\t\t TRANSFORMACION DE POTENCIA " << endl;
	double gamma;
	cout << "Ingresa valor de la constante para power law" << endl;
	cin >> c;
	cout << "Ingresa valor de la gamma para power law" << endl;
	cin >> gamma;
	//Power Law Transform

	for (int x = 0; x < matrizGrises2.rows; x++) {
		for (int y = 0; y < matrizGrises2.cols; y++) {
			Scalar intensity = matrizGrises2.at<uchar>(x, y);
			double r = intensity.val[0];
			s = c * pow(r, gamma);
			if (s <= 255) {
				matrizGrises2.at<uchar>(x, y) = s;
			}
			else if (s > 255) {
				matrizGrises2.at<uchar>(x, y) = 255;
			}

		}
	}

	cout << "Ingresa nombre y extension de tu imagen de salida con Power-Law Trans." << endl;
	cin >> rutaSalida;
	imwrite("C:/Users/HOLA/Desktop/imagenesSalida/ " + rutaSalida, matrizGrises2);


		
	String windowName1 = "Linear Transformation"; //Nombre de la ventana
	namedWindow(windowName1, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName1, matrizGrises); // Mostrar la imagen dentro de la ventana
	//waitKey(0);


	//Para mostrar la imagen en escala de grises antes de la transformada logarítmica
	String windowName2 = "Escala de grises"; //Nombre de la ventana
	namedWindow(windowName2, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName2, matrizEscGrises); // Mostrar la imagen dentro de la ventana
	//waitKey(0);
	

	
	String windowName3 = "Logarithmic Transform"; //Nombre de la ventana
	namedWindow(windowName3, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName3, matrizGrises1); // Mostrar la imagen dentro de la ventana
	//waitKey(0);

	String windowName4 = "Power Law Transform"; //Nombre de la ventana
	namedWindow(windowName4, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(windowName4, matrizGrises2); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	destroyWindow(windowName2);//destruir la ventana creada
	destroyWindow(windowName1);//destruir la ventana creada
	destroyWindow(windowName3); //destruir la ventana creada
	destroyWindow(windowName4);//destruir la ventana creada
	system("pause");
	system("cls");
}

void transformacionPartes(Mat& imagen) {
	string rutaSalida = " ";
	if (imagen.empty()) // Verificar que se haya cargado la imagen
	{
		cout << "No se pudo abrir o encontrar la imagen." << endl;
		system("pause");
		//return -1;
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


/*-----------------------------------------CONTRAST STRETCHING------------------------------*/

	double r1;
	double r2;
	double s1;
	double s2;
	
	cout << "\t\t CONTRAST STRETCHING " << endl;
	cout << "Ingresa valor de R1 para Constrast Stretching" << endl;
	cin >> r1;
	cout << "Ingresa valor de R2 para Constrast Stretching" << endl;
	cin >> r2;
	cout << "Ingresa valor de S1 para Constrast Stretching" << endl;
	cin >> s1;
	cout << "Ingresa valor de S2 para Constrast Stretching" << endl;
	cin >> s2;

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
			else if (r2 < r && r <= 255) {
				s = ((255 - s2) / (255 - r2))*(r - r2) + s2;
				matrizGrises.at<uchar>(x, y) = s;
			}

		}
	}

	cout << "Ingresa nombre y extension de tu imagen con Contrast Stretching" << endl;
	cin >> rutaSalida;
	imwrite("C:/Users/HOLA/Desktop/imagenesSalida/ " + rutaSalida, matrizGrises);
	cout << "\n" << endl;
	

	/*-----------------------------------------INTENSITY-LEVEL SLICING------------------------------*/
	double A;
	double B;

	cout << "\t\t INTENSITY-LEVEL SLICING " << endl;
	cout << "Ingresa valor de A para Intensity-Level Slicing" << endl;
	cin >> A;
	cout << "Ingresa valor de B para Intensity-Level Slicing" << endl;
	cin >> B;
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

	cout << "Ingresa nombre y extension de tu imagen de salida con Intensity-Level Slicing" << endl;
	cin >> rutaSalida;
	imwrite("C:/Users/HOLA/Desktop/imagenesSalida/ " + rutaSalida, matrizGrises1);

	String escalaGrises = "Escala de grises"; //Nombre de la ventana
	namedWindow(escalaGrises, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(escalaGrises, matrizGrises2); // Mostrar la imagen dentro de la ventana en escala de grises antes de ser tratada
	//waitKey(0);


	String contrastStreching = "Contrast Stretching"; //Nombre de la ventana
	namedWindow(contrastStreching, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(contrastStreching, matrizGrises); // Mostrar la imagen dentro de la ventana
	//waitKey(0);


	String intensityLevelSlicing = "Intensity-Level Slicing"; //Nombre de la ventana
	namedWindow(intensityLevelSlicing, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(intensityLevelSlicing, matrizGrises1); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	destroyWindow(escalaGrises);//destruir la ventana creada
	destroyWindow(contrastStreching);//destruir la ventana creada
	destroyWindow(intensityLevelSlicing);//destruir la ventana creada
	system("pause");
	system("cls");

}

void histograma(Mat& imagen) {

	string rutaSalida = " ";
	if (imagen.empty()) // Verificar que se haya cargado la imagen
	{
		cout << "No se pudo abrir o encontrar la imagen." << endl;
		system("pause");
		//return -1;
	}

	int filas = imagen.rows;
	int columnas = imagen.cols;
	//Se crean matrices para trabajar con ellas en escala de grises
	Mat matrizGrises = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagen, matrizGrises, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises


	/*Variables necesarias para calcular el histograma*/
	
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

	ofstream archivoHistograma;  //Para guardar el histograma en un csv

	archivoHistograma.open("C:/Users/HOLA/Desktop/imagenesSalida/histograma.csv");
	archivoHistograma << "InputGrayLevel,Ocurrences,PDF,CDF,(L-1)*CDF, OutputGrayLevel\n";
	char delimiter = ',';
	//Para calcular el histograma
	for (int i = 0; i < myvector.size(); i++) {

		pdf = myvector.at(i) / totalPixeles;
		cdf += pdf;
		multiplicacion = (L - 1)*cdf;
		salidaNivelGris.at(i) = rint(multiplicacion);

		if (salidaNivelGris.at(i) > L)	//¿Se encuentra fuera del nivel máximo en escala de grises? Si es así, igualar al nivel máximo (255)
			salidaNivelGris.at(i) = L - 1;


		//cout << i << " " << myvector.at(i) << " PDF " << pdf << " CDF " << cdf << " " << salidaNivelGris.at(i) << endl;
		archivoHistograma << i << delimiter << myvector.at(i) << delimiter << pdf << delimiter << cdf << delimiter << multiplicacion << delimiter << salidaNivelGris.at(i) << "\n";

	}
	archivoHistograma.close();

	//Para ecualizar la imagen
	for (int x = 0; x < matrizGrises.rows; x++) {
		for (int y = 0; y < matrizGrises.cols; y++) {
			Scalar intensity = matrizGrises.at<uchar>(x, y);
			r = intensity.val[0];		//intensidad del pixel
			for (int i = 0; i < myvector.size(); i++) {
				if (r == i)		//¿Encontró la intensidad dentro del vector de salida? Asignar nuevo valor de salida para esa intensidad
					matrizGrises.at<uchar>(x, y) = salidaNivelGris.at(r);
			}
		}
	}

	cout << "Ingresa nombre y extension para imagen ecualizada" << endl;
	cin >> rutaSalida;
	imwrite("C:/Users/HOLA/Desktop/imagenesSalida/ " + rutaSalida, matrizGrises);
	cout << "\n" << endl;

	/*Para mostrar la imagen en escala de grises*/
	String escalaGrises = "Escala de grises"; //Nombre de la ventana
	namedWindow(escalaGrises, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(escalaGrises, matrizGrises); // Mostrar la imagen dentro de la ventana en escala de grises antes de ser tratada
	//waitKey(0);


	String histogram = "Histogram"; //Nombre de la ventana
	namedWindow(histogram, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(histogram, matrizGrises); // Mostrar la imagen dentro de la ventana
	waitKey(0);
	destroyWindow(escalaGrises);//destruir la ventana creada
	destroyWindow(histogram);//destruir la ventana creada
	system("pause");
	system("cls");

}

void histogramMatching(Mat& imagenReferencia, Mat& imagenHistogramMatching) {
	string rutaSalida = " ";
	if (imagenReferencia.empty()) // Verificar que se haya cargado la imagen
	{
		cout << "No se pudo abrir o encontrar la imagen." << endl;
		system("pause");
		//return -1;
	}

	if (imagenHistogramMatching.empty()) // Verificar que se haya cargado la imagen
	{
		cout << "No se pudo abrir o encontrar la imagen." << endl;
		system("pause");
		//return -1;
	}

	int filas = imagenReferencia.rows;
	int columnas = imagenReferencia.cols;
	Mat matrizGrises1 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagenReferencia, matrizGrises1, COLOR_BGR2GRAY);	//Para convertir la imagen de referencia a escala de grises
	Mat matrizGrises2 = Mat::zeros(filas, columnas, CV_64FC1);
	cvtColor(imagenHistogramMatching, matrizGrises2, COLOR_BGR2GRAY);	//Para convertir la imagen a escala de grises


	/*-----------------------------HISTOGRAM MATCHING-----------------------------*/
	double multiplicacion = 0;
	double L = 256; //Maximo valor de r 
	double totalPixeles = filas * columnas;
	double r = 0;	//Intensidad del pixel
	vector<double> myvectorAux(L);		//Vector de 255 para guardar aqui la cantidad de ocurrencias de la imagen de referencia para histogram Matching
	vector<double> myvectorAuxHM(L);		//Vector de 255 para guardar aqui la cantidad de ocurrencias de la imagen final para histogram Matching
	vector<double> salidaNivelGrisReferencia(L);	//Vector de 255 para almacenar la nueva salida para la imagen de referencia
	vector<double> salidaNivelGrisHM(L);	//Vector de 255 para almacenar la salida de la imagen con Histogram Matching

	/*Limpiar variables para cálculo nuevo del histograma de la imagen de referencia*/
	double pdf = 0;
	double cdf = 0;
	double nk = 0;
	double sk = 0;

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


	ofstream archivoHistogramMatching;  //Para guardar el histograma en un csv

	archivoHistogramMatching.open("C:/Users/HOLA/Desktop/imagenesSalida/histogramMatching.csv");
	archivoHistogramMatching << "InputGrayLevel,Ocurrences,PDF,CDF,(L-1)*CDF, OutputGrayLevel\n";
	char delimiter = ',';

	//Para calcular el histograma de la imagen de referencia
	for (int i = 0; i < myvectorAux.size(); i++) {

		pdf = myvectorAux.at(i) / totalPixeles;
		cdf += pdf;
		multiplicacion = (L - 1)*cdf;
		salidaNivelGrisReferencia.at(i) = rint(multiplicacion);

		if (salidaNivelGrisReferencia.at(i) > L)	//¿Se encuentra fuera del nivel máximo en escala de grises? Si es así, igualar al nivel máximo (255)
			salidaNivelGrisReferencia.at(i) = L - 1;


		//cout << i << " " << myvectorAux.at(i) << " PDF " << pdf << " CDF " << cdf << " " << salidaNivelGrisReferencia.at(i) << endl;
		archivoHistogramMatching<< i << delimiter << myvectorAux.at(i) << delimiter << pdf << delimiter << cdf << delimiter << multiplicacion << delimiter << salidaNivelGrisReferencia.at(i) << "\n";

	}
	archivoHistogramMatching.close();

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

	archivoHistogramMatching.open("C:/Users/HOLA/Desktop/imagenesSalida/histogramMatching.csv");
	archivoHistogramMatching << "InputGrayLevel,Ocurrences,PDF,CDF,(L-1)*CDF, OutputGrayLevel\n";
	//Para calcular el histograma de la imagen de referencia
	for (int i = 0; i < myvectorAuxHM.size(); i++) {

		pdf = myvectorAuxHM.at(i) / totalPixeles;
		cdf += pdf;
		multiplicacion = (L - 1)*cdf;
		salidaNivelGrisHM.at(i) = rint(multiplicacion);

		if (salidaNivelGrisHM.at(i) > L)	//¿Se encuentra fuera del nivel máximo en escala de grises? Si es así, igualar al nivel máximo (255)
			salidaNivelGrisHM.at(i) = L - 1;


		//cout << i << " " << myvectorAuxHM.at(i) << " PDF " << pdf << " CDF " << cdf << " " << salidaNivelGrisHM.at(i) << endl;
		archivoHistogramMatching << i << delimiter << myvectorAuxHM.at(i) << delimiter << pdf << delimiter << cdf << delimiter << multiplicacion << delimiter << salidaNivelGrisHM.at(i) << "\n";

	}
	archivoHistogramMatching.close();


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


	/*Para mostrar la imagen de referencia en escala de grises*/
	String escalaGrisesReferencia = "Escala de grises de Referencia"; //Nombre de la ventana
	namedWindow(escalaGrisesReferencia, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(escalaGrisesReferencia, matrizGrises1); // Mostrar la imagen dentro de la ventana en escala de grises antes de ser tratada
	//waitKey(0);

	/*Para mostrar la imagen ya con el Histogram Matching en escala de grises*/
	String histogramMatching = "Histogram Matching"; //Nombre de la ventana
	namedWindow(histogramMatching, WINDOW_AUTOSIZE); // Crear la ventana
	imshow(histogramMatching, matrizGrises2); // Mostrar la imagen dentro de la ventana en escala de grises antes de ser tratada
	waitKey(0);
	destroyWindow(escalaGrisesReferencia);//destruir la ventana creada
	destroyWindow(histogramMatching);//destruir la ventana creada
	system("pause");
	system("cls");
}