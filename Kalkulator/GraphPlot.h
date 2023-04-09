#pragma once

#define _USE_MATH_DEFINES
#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include <string>

class GraphPlot {
public:
	//Wspolrzedne x, y
	void graphAxis(double minX, double maxX, double minY, double maxY);


	//Podstawowe
	void linear(double a, double b);
	void cubic(double a, double b, double c);
	void polynomial(double n);
	void modulus(double a, double b, double c);

	//Funkcje trygonometryczne
	void sinus(void);
	void cosinus(void);
	void tangent(void);

	//Funkcje wyk³adnicze
	void logarithmic(double a);
	void exponential(double a);

	//Funkcja custom
	void userCustom(std::string customExpression);
};