﻿//	============================================================================================	//
//									Simple Graphic Calculator
// 
//	Date: 04.2023
//	Authors : Oskar Makuch, Szymon Protaś, Victor Mroziewicz
//	
//	Requirements:
//	* Python39 (Remember to set path to your Python39 installation)
//	* Patience :)
//
//	Description:
//	Program uses Reversed Polish Notation (RPN) Algrotihm, matplotlib-cpp library
//	from https://github.com/lava/matplotlib-cpp
// 
//	Pliki:
//		main.cpp - main
//		graphplot.h - header with class to drawing function using matplotlib
//		graphplot.cpp - mthod definitions in graphplot class
//		matplotlibcpp.h - plotting library
//		ONP_Algorytm.h - RPN algorithm class
// 
//	============================================================================================	//


//INCLUDE
#include "matplotlibcpp.h"
#include "RPNAlgorithm.h"
#include <cmath>
#include <math.h>
#include <vector>
#include <iostream>
#include "graphplot.h"
#include <stack>


//NAMESPACES
using namespace std; 
namespace plt = matplotlibcpp;

//DECLARATIONS
void onpCalc(void); //Calculator mode function
void graphMain(void); //Plotting mode function
GraphPlot* graph; // Pointer to  plotter
ONPCalc* calc;	//Pointer to calculator
string menuLine = "==========================================================="; //Menu string
static int selectMain = 0; //Main select index



int main() {
	//DECLARATIONS
	int select = 0;
	system("chcp 1250");
	system("CLS");

	//MAIN LOOP
	while (select != 3) {
		//MENU - mode select
		if (selectMain != 3) { 
		cout << menuLine << endl;
		cout << "                        KALKULATOR                         " << endl << endl;
		cout << "	1. Kalkulator                                           " << endl;
		cout << "	2. Wykres funkcji										" << endl;
		cout << "	3. Wyjdź												" << endl << endl;
		cout << menuLine << endl;
			cin >> selectMain;
		}
		//CHECK CIN
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}

		//SWITCH MAIN
		switch (selectMain) {
		case 1:
			system("CLS");
			onpCalc();
			break;
		case 2:
			system("CLS");
			graphMain();
			break;
		case 3:
			system("CLS");
			cout << menuLine << endl;
			cout << "Zakończono pomyślnie" << endl;
			cout << menuLine << endl;
			return 0;
		default:
			system("CLS");
			cout << "Źle wybrano!" << endl;
			break;
		}

	}

	return 0;

}

void onpCalc(void) {
	//DECLARATIONS
	calc = new ONPCalc;
	string expression = "0";
	string check = "k";

	//LOOP onpCalc
	while (!(expression == check)) {
		cout << menuLine << endl;
		cout << "Wpisz wyrażenie bez nawiasów [ 'k' żeby wyjść ]: " << endl;
		cin >> expression;
		cout << endl;

		//CHECK IF END
		if (!(expression == check)) {

			cout << "Wynik: " << calc->calculate(expression) << endl;
		}
	}

	//DELETE POINTER AND END FUNCTION
	system("CLS");
	delete calc;
	return;
};

void graphMain(void) {
	
	//DECLARATIONS
	graph = new GraphPlot;
	int select = 0;
	int selectSettings = 0;
	int selectGraph = 0;
	double inputValue = 0;
	string inputString;
	double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, n = 0;
	

	//LOOP graphMain
	while (!(select == 3 || select == 4)) {
		//INITIALIZATION
		selectGraph = -1;
		selectSettings = -1;
		select = 0;

		//MENU graphMain
		system("CLS");
		cout << menuLine << endl << endl;
		cout << "1. Wykres" << endl;
		cout << "2. Ustawienia" << endl;
		cout << "3. Wróć" << endl;
		cout << "4. Wyjdź" << endl << endl;
		cout << "Jeżeli wykres źle się wyświetla to należy zmienić w ustawieniach" << endl;
		cout << "wartości minimalne i maksymalne dla X i Y!" << endl;
		cout << menuLine << endl;
		cin >> select;
		//CHECK CIN
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}

		//MENU graphMain
		switch (select) {
		//	                                                                       =================SWITCH GŁÓWNY START=================
		case 1: //CASE 1 - WYKRES/PLOTTER
			
			//MENU
			system("CLS");
			cout << menuLine << endl << endl;
			cout << "FUNKCJA" << endl << endl;
			cout << "1. Liniowa" << endl;
			cout << "2. Kwadratowa" << endl;
			cout << "3. Wielomian [max 5 potęga]" << endl;
			cout << "4. Wartość bezwzględna" << endl;
			cout << "5. Sin" << endl;
			cout << "6. Cos" << endl;
			cout << "7. Tan" << endl;
			cout << "8. Logarytmiczna" << endl;
			cout << "9. Wykładnicza" << endl;
			//cout << "" << endl; custom 
			cout << "0. Wróć" << endl << endl;
			cout << "Jeżeli wykres źle się wyświetla to należy zmienić w ustawieniach" << endl;
			cout << "wartości minimalne i maksymalne dla X i Y!" << endl;
			cout << menuLine << endl;
			cin >> selectGraph;

			//SWITCH - PLOT
			switch (selectGraph) {
				//																	=============SWITCH WYKRES START=============
			case 1: //LINIOWA LINEAR
				system("CLS");
				cout << "f(x) = ax+b" << endl;
				cout << "Podaj a i b: " << endl;
				cout << "a = ";
				cin >> a;
				cout << "b = ";
				cin >> b;
				graph->linear(a, b);
				break;

			case 2: //KWADRATOWA CUBIC
				system("CLS");
				cout << "f(x) = ax^2 + bx + c" << endl;
				cout << "Podaj a, b, c: " << endl;
				cout << "a = ";
				cin >> a;
				cout << "b = ";
				cin >> b;
				cout << "c = ";
				cin >> c;
				graph->cubic(a, b, c);
				break;

			case 3: //WIELOMIAN POLYNOMIAL up to 5 power
				system("CLS");
				cout << "[2] ex + f" << endl;
				cout << "[6] ax^5 + bx^4 + cx^3 + dx^2 + ex + f" << endl;
				cout << "Podaj ilość współczynników [od 1 do 6]: " << endl;
				cout << "n = ";
				cin >> n;
				
				if (n == 0) {
					break;
				}
				if (n == 6) {
					cout << " Podaj współczynnik [A] przy X ^ 5: " << endl;
					cin >> a;
				} 
				if (n >= 5) {
					cout << " Podaj współczynnik [B] przy X ^ 4: " << endl;
					cin >> b;
				}
				if (n >= 4) {
					cout << " Podaj współczynnik [C] przy X ^ 3: " << endl;
					cin >> c;
				}
				if (n >= 3) {
					cout << " Podaj współczynnik [D] przy X ^ 2: " << endl;
					cin >> d;
				}
				if (n >= 2) {
					cout << " Podaj współczynnik [E] przy X ^ 1: " << endl;
					cin >> e;
				}
				if (n >= 1) {
					cout << " Podaj współczynnik [F] : " << endl;
					cin >> f;
				}
				graph->polynomial(a, b, c, d, e, f);
				break;

			case 4: //BEZWZGLĘDNA Modulus
				system("CLS");
				graph->modulus();
				break;
			case 5: //SIN
				system("CLS");
				graph->sinus();
				break;
			case 6: //COS
				system("CLS");
				graph->cosinus();
				break;
			case 7: //TAN
				system("CLS");
				graph->tangent();
				break;
			case 8: //LOG
				system("CLS");
				graph->logarithmic();
				break;
			case 9: //WYKŁADNICZA EXPONENTIAL
				system("CLS");
				cout << "f(x) = a^x" << endl;
				cin >> a;
				graph->exponential(a);
				break;
			case 0:
				system("CLS");
				break;
				//																	=============SWITCH WYKRES STOP=============
			}

			break;

		case 2: // CASE 2 - USTAWIENIA SETTINGS
			while (!(selectSettings == 5)) {
				//MENU PLOT SETTINGS
				system("CLS");
				cout << menuLine << endl;
				cout << "1. Przedział X   [Min X = " << graph->get_minX() << " Max X = " << graph->get_maxX() << "]" << endl;
				cout << "2. Przedział Y   [Min Y = " << graph->get_minY() << " Max Y = " << graph->get_maxY() << "]" << endl;
				cout << "3. Dokładność = " << graph->get_res() << " - co ile wykres ma obliczać Y" << endl;
				cout << "4. Kolor = " << graph->get_color() << endl;
				cout << "5. Wróć" << endl;
				cout << "Im większa dokładność tym dłużej program może liczyć wykres!" << endl;
				cout << menuLine << endl;
				cin >> selectSettings;

				//CHECK CIN
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}

				//SWITCH SETTINGS
				switch (selectSettings) {
				case 1:
					cout << "Min X = ";
					cin >> inputValue;
					graph->set_minX(inputValue);
					cout << "Max X = ";
					cin >> inputValue;
					graph->set_maxX(inputValue);
					system("CLS");
					break;
				case 2:
					cout << "Min Y = ";
					cin >> inputValue;
					graph->set_minY(inputValue);
					cout << "Max Y = ";
					cin >> inputValue;
					graph->set_maxY(inputValue);
					system("CLS");
					break;
				case 3:
					cout << "Dokładność = ";
					cin >> inputValue;
					graph->set_res(inputValue);
					system("CLS");
					break;
				case 4:
					cout << "Kolor wpisuje się po nazwie koloru w CSS (np. black, red, yellow, pink, ...)" << endl;
					cout << "Kolor = ";
					cin >> inputString;
					graph->set_color(inputString);
					system("CLS");
					break;
				case 5:
					system("CLS");
					break;
				default:
					system("CLS");
					cout << "Źle wybrano!" << endl;
					break;
				}
			}
			break;

		case 3: // CASE 3 - WRÓĆ BACK
			system("CLS");
			delete graph;
			return;

		case 4: // CASE 4 - KONIEC END
			system("CLS");
			delete graph;
			selectMain = 3;
			return;
		default:
			system("CLS");
			cout << "Źle wybrano!" << endl;
			break;
			//	                                                                       =================SWITCH GŁÓWNY KONIEC=================
		}
		
	}


	//DELETE POINTER AND END FUNCTION graphMain
	delete graph;
	return;
}
