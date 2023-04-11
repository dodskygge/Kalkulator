//	============================================================================================	//
//									Prosty kalkulator graficzny
// 
//	Data: 04.2023
//	Prowadz�cy: mgr. in�. Jacek Adamczyk
//	Autorzy: Oskar Makuch, Szymon Prota��, Victor Mroziewicz
//	
//	Wymagania:
//	* Python39 (w tym dodanie lokalizacji Pythona39 do projektu)
//	* Cierpliwo��� :)
//
//	Opis:
//	Kalkulator u�ywa algorytmu Odwr�conej Notacji Polskiej (ONP) i biblioteki matplotlibcpp, kt�ra
//	��czy si� z Pythonem i rysuje wybrany wz�r.
// 
//	Pliki:
//		main.cpp - g��wna klasa
//		graphplot.h - plik nag��wkowy klasy graphplot
//		graphplot.cpp - definicje metod klasy graphplot
//		matplotlibcpp.h - biblioteka zawieraja kod do rysowania wykresu w Pythonie
//		ONPCalc.h - plik nag��wkowy zawieraj�cy klas� ...... z algorytmem ONP
// 
//	============================================================================================	//

#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include <iostream>
#include "graphplot.h"
#include <stack>


//PRZESTRZE� NAZW
using namespace std; 
namespace plt = matplotlibcpp; //Przestrze� znak�w dla matplotlibcpp

//DEKLARACJE FUNKCJI I ZMIENNYCH
void onpCalc(void); //Funkcja ONP
void graphMain(void); //Funkcja do wy�wietlania funkcji
GraphPlot* graph; // Utworzenie wska�nika do obiektu graph
string menuLine = "==========================================================="; // String z lini� dla menu
static int selectMain = 0; //Zmienna wyboru w main


int main() {
	//DEKLARACJE ZMIENNYCH I USTAWIENIE POLSKICH ZNAK�W
	int select = 0;
	system("chcp 1250");
	system("CLS");

	//P�TLA MAIN
	while (select != 3) {
		//MENU PROGRAMU - wyb�rr funkcji
		if (selectMain != 3) { // Zako�cz je��li funkcja podrz�dna zmieni�a warto��� selectMain na 3
		cout << menuLine << endl;
		cout << "                        KALKULATOR                         " << endl << endl;
		cout << "	1. Kalkulator                                           " << endl;
		cout << "	2. Wykres funkcji										" << endl;
		cout << "	3. Wyjd�												" << endl << endl;
		cout << menuLine << endl;
			cin >> selectMain;
		}
		//SPRAWDZENIE POPRAWNO�CI WYBORU
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}

		//WYB�R
		switch (selectMain) {
		case 1:
			system("CLS");
			return 0;
		case 2:
			system("CLS");
			graphMain();
			break;
		case 3:
			system("CLS");
			cout << menuLine << endl;
			cout << "Zako�czono pomy�lnie" << endl;
			cout << menuLine << endl;
			return 0;
		default:
			system("CLS");
			cout << "�le wybrano!" << endl;
			break;
		}

	}

	return 0;

}

void onpCalc(void) {
	return;
};

void graphMain(void) {
	//UTWORZENIE OBIEKTU WE WSKA�NIKU
	graph = new GraphPlot;

	//DEKLARACJE
	int select = 0;
	int selectSettings = 0;
	int selectGraph = 0;
	double inputValue = 0;
	

	//P�TLA PROGRAMU GRAPHMAIN
	while (!(select == 3 || select == 4)) {

		//MENU
		system("CLS");
		cout << menuLine << endl << endl;
		cout << "1. Wykres" << endl;
		cout << "2. Ustawienia" << endl;
		cout << "3. Wr��" << endl;
		cout << "4. Wyjd�" << endl << endl;
		cout << "Je�eli wykres �le si� wy�wietla to nale�y zmieni� w ustawieniach" << endl;
		cout << "warto�ci minimalne i maksymalne dla X i Y!" << endl;
		cout << menuLine << endl;
		cin >> select;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}

		//MENU SWITCH
		switch (select) {
		//	                                                                       =================SWITCH G��WNY START=================
		case 1: //CASE 1 - WYKRES
			
			//MENU
			system("CLS");
			cout << menuLine << endl << endl;
			cout << "FUNKCJA" << endl << endl;
			cout << "1. Liniowa" << endl;
			cout << "2. Kwadratowa" << endl;
			cout << "3. Wielomian [max 5 pot�ga]" << endl;
			cout << "4. Warto�� bezwzgl�dna" << endl;
			cout << "5. Sin" << endl;
			cout << "6. Cos" << endl;
			cout << "7. Tan" << endl;
			cout << "8. Logarytmiczna" << endl;
			cout << "9. Wyk�adnicza" << endl;
			//cout << "" << endl; custom funkcja - w trakcie wymy�lania :/
			cout << "0. Wr��" << endl << endl;
			cout << "Je�eli wykres �le si� wy�wietla to nale�y zmieni� w ustawieniach" << endl;
			cout << "warto�ci minimalne i maksymalne dla X i Y!" << endl;
			cout << menuLine << endl;
			cin >> selectGraph;

			//WYKRES MENU SWITCH
			switch (selectGraph) {
				//																	=============SWITCH WYKRES START=============
			case 1: //LINIOWA
				system("CLS");
				int a;
				int b;
				cout << "f(x) = ax+b" << endl;
				cout << "Podaj a i b: " << endl;
				cout << "a = ";
				cin >> a;
				cout << "b = ";
				cin >> b;
				graph->linear(a, b);
				break;

			case 2: //KWADRATOWA
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 0:
				break;
				//																	=============SWITCH WYKRES STOP=============
			}

			break;

		case 2: // CASE 2 - USTAWIENIA
			while (!(selectSettings == 4)) {
				//MENU USTAWIE�
				system("CLS");
				cout << menuLine << endl;
				cout << "1. Przedzia� X   [Min X = " << graph->get_minX() << " Max X = " << graph->get_maxX() << "]" << endl;
				cout << "2. Przedzia� Y   [Min Y = " << graph->get_minY() << " Max Y = " << graph->get_maxY() << "]" << endl;
				cout << "3. Dok�adno�� = " << graph->get_res() << " - co ile wykres ma oblicza� Y" << endl;
				cout << "4. Wr��" << endl;
				cout << "Im wi�ksza dok�adno�� tym d�u�ej program mo�e liczy� wykres!" << endl;
				cout << menuLine << endl;
				cin >> selectSettings;

				//SPRAWDZENIE WYBORU
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}

				//WPISANIE WARTO�CI
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
					cout << "Dok�adno��� = ";
					cin >> inputValue;
					graph->set_res(inputValue);
					system("CLS");
					break;
				case 4:
					system("CLS");
					break;
				default:
					system("CLS");
					cout << "�le wybrano!" << endl;
					break;
				}
			}
			break;

		case 3: // CASE 3 - WR��
			system("CLS");
			delete graph;
			return;

		case 4: // CASE 4 - KONIEC
			system("CLS");
			delete graph;
			selectMain = 3;
			return;
		default:
			system("CLS");
			cout << "�le wybrano!" << endl;
			break;
			//	                                                                       =================SWITCH G��WNY KONIEC=================
		}
		
	}


	//ZNISZCZENIE OBIEKTU I ZAKO�CZENIE FUNKCJI
	delete graph;
	return;
}
