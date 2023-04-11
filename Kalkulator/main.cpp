//	============================================================================================	//
//									Prosty kalkulator graficzny
// 
//	Data: 04.2023
//	ProwadzĄcy: mgr. inż. Jacek Adamczyk
//	Autorzy: Oskar Makuch, Szymon Protaś, Victor Mroziewicz
//	
//	Wymagania:
//	* Python39 (w tym dodanie lokalizacji Pythona39 do projektu)
//	* Cierpliwość :)
//
//	Opis:
//	Kalkulator uľywa algorytmu Odwr˘conej Notacji Polskiej (ONP) i biblioteki matplotlibcpp, która
//	łączy się z Pythonem i rysuje wybrany wz˘r.
// 
//	Pliki:
//		main.cpp - główna klasa
//		graphplot.h - plik nagłówkowy klasy graphplot
//		graphplot.cpp - definicje metod klasy graphplot
//		matplotlibcpp.h - biblioteka zawieraja kod do rysowania wykresu w Pythonie
//		ONPCalc.h - plik nagłówkowy zawierający klasę ...... z algorytmem ONP
// 
//	============================================================================================	//

#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include <iostream>
#include "graphplot.h"
#include <stack>


//PRZESTRZEŃ NAZW
using namespace std; 
namespace plt = matplotlibcpp; //Przestrzeń znaków dla matplotlibcpp

//DEKLARACJE FUNKCJI I ZMIENNYCH
void onpCalc(void); //Funkcja ONP
void graphMain(void); //Funkcja do wywietlania funkcji
GraphPlot* graph; // Utworzenie wskaźnika do obiektu graph
string menuLine = "==========================================================="; // String z linią dla menu
static int selectMain = 0; //Zmienna wyboru w main


int main() {
	//DEKLARACJE ZMIENNYCH I USTAWIENIE POLSKICH ZNAKŕW
	int select = 0;
	system("chcp 1250");
	system("CLS");

	//PĘTLA MAIN
	while (select != 3) {
		//MENU PROGRAMU - wybórr funkcji
		if (selectMain != 3) { // Zakończ jeśli funkcja podrzędna zmienia wartość selectMain na 3
		cout << menuLine << endl;
		cout << "                        KALKULATOR                         " << endl << endl;
		cout << "	1. Kalkulator                                           " << endl;
		cout << "	2. Wykres funkcji										" << endl;
		cout << "	3. Wyjdź												" << endl << endl;
		cout << menuLine << endl;
			cin >> selectMain;
		}
		//SPRAWDZENIE POPRAWNOŚCI WYBORU
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}

		//WYBÓR
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
	return;
};

void graphMain(void) {
	//UTWORZENIE OBIEKTU WE WSKAŹNIKU
	graph = new GraphPlot;

	//DEKLARACJE
	int select = 0;
	int selectSettings = 0;
	int selectGraph = 0;
	double inputValue = 0;
	

	//PĘTLA PROGRAMU GRAPHMAIN
	while (!(select == 3 || select == 4)) {

		//MENU
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
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}

		//MENU SWITCH
		switch (select) {
		//	                                                                       =================SWITCH GŁÓWNY START=================
		case 1: //CASE 1 - WYKRES
			
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
			//cout << "" << endl; custom funkcja - w trakcie wymyślania :/
			cout << "0. Wróć" << endl << endl;
			cout << "Jeżeli wykres źle się wyświetla to należy zmienić w ustawieniach" << endl;
			cout << "wartości minimalne i maksymalne dla X i Y!" << endl;
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
				//MENU USTAWIEŃ
				system("CLS");
				cout << menuLine << endl;
				cout << "1. Przedział X   [Min X = " << graph->get_minX() << " Max X = " << graph->get_maxX() << "]" << endl;
				cout << "2. Przedział Y   [Min Y = " << graph->get_minY() << " Max Y = " << graph->get_maxY() << "]" << endl;
				cout << "3. Dokładność = " << graph->get_res() << " - co ile wykres ma obliczać Y" << endl;
				cout << "4. Wróć" << endl;
				cout << "Im większa dokładność tym dłużej program może liczyć wykres!" << endl;
				cout << menuLine << endl;
				cin >> selectSettings;

				//SPRAWDZENIE WYBORU
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}

				//WPISANIE WARTOŚCI
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
					cout << "Dokadność = ";
					cin >> inputValue;
					graph->set_res(inputValue);
					system("CLS");
					break;
				case 4:
					system("CLS");
					break;
				default:
					system("CLS");
					cout << "Źle wybrano!" << endl;
					break;
				}
			}
			break;

		case 3: // CASE 3 - WRÓĆ
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
			cout << "Źle wybrano!" << endl;
			break;
			//	                                                                       =================SWITCH GŁÓWNY KONIEC=================
		}
		
	}


	//ZNISZCZENIE OBIEKTU I ZAKOŃCZENIE FUNKCJI
	delete graph;
	return;
}
