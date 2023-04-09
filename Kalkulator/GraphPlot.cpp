#define _USE_MATH_DEFINES
#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include "graphplot.h"
#include <string>

namespace plt = matplotlibcpp;

//Linie wspó³rzêdnych
void GraphPlot::graphAxis(double minX, double maxX, double minY, double maxY) {
	//Linia wspolrzednej x
	std::vector<double> yx;
	std::vector<double> xx;

	//Linia wspolrzednej y
	std::vector<double> yy;
	std::vector<double> xy;

	//Linia wspolrzednej x
	for (double i = minX; i <= maxX; i = i + 1) {
		xx.insert(xx.begin(), i);
		yx.insert(yx.begin(), 0);
	}

	//Linia wspolrzednej x
	for (double i = minY; i <= maxY; i = i + 1) {
		xy.insert(xy.begin(), 0);
		yy.insert(yy.begin(), i);
	}

	plt::plot(xx, yx, "grey"); //Narysuj linie wsp. x
	plt::plot(xy, yy, "grey"); //Narysuj linie wsp. y
};

//Podstawowe
void GraphPlot::linear(double a, double b) { //ax+b
	std::vector<double> y1;
	std::vector<double> x1;

	for (double i = -10; i <= 10; i = i + 1) {
		x1.insert(x1.begin(), i);
		y1.insert(y1.begin(), (a*i)+b);
	}

	plt::plot(x1, y1, "black");


};
void GraphPlot::cubic(double a, double b, double c) {};
void GraphPlot::polynomial(double n) {};
void GraphPlot::modulus(double a, double b, double c) {};

//Funkcje trygonometryczne
void GraphPlot::sinus(void) {};
void GraphPlot::cosinus(void) {};
void GraphPlot::tangent(void) {};

//Funkcje wyk³adnicze
void GraphPlot::logarithmic(double a) {};
void GraphPlot::exponential(double a) {};

//Funkcja custom
void GraphPlot::userCustom(std::string customExpression) {};



