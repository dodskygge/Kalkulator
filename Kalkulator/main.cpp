// 
//

#define _USE_MATH_DEFINES
#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include <iostream>
#include "GraphPlot.h"
#include <stack>

using namespace std;

namespace plt = matplotlibcpp;

int main() {
	


	//Linia wspolrzednej x
	std::vector<double> yx;
	std::vector<double> xx;

	//Linia wspolrzednej y
	std::vector<double> yy;
	std::vector<double> xy;

	//Funkcja1
	std::vector<double> y1;
	std::vector<double> x1;

	//Rozdzielczosc i rozmiar
	double minX = -10;
	double maxX = 10;
	double minY = -10;
	double maxY = 10;
	double res = 0.1;



	for (double i = -10; i <= 10; i = i + 1) {
		x1.insert(x1.begin(), i);
		y1.insert(y1.begin(), i*i);
	}
	
//Linia wspolrzednej x
	for (double i = minX; i <= maxX; i = i + res) {
		xx.insert(xx.begin(), i);
		yx.insert(yx.begin(), 0);
	}

//Linia wspolrzednej x
	for (double i = minY; i <= maxY; i = i + res) {
		xy.insert(xy.begin(), 0);
		yy.insert(yy.begin(), i);
	}



	plt::xlim(-10, 10); 	
	plt::ylim(-10, 10);		
	plt::plot(xx, yx, "black"); //Narysuj linie wsp. x
	plt::plot(xy, yy, "black"); //Narysuj linie wsp. y
	plt::plot(x1, y1, "red"); //Narysuj f1

	plt::show();
}