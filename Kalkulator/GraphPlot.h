#pragma once

#define _USE_MATH_DEFINES
#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include <string>

class GraphPlot {
public:
	// Zainicjowane wartoœci domyœlne dla rozmiaru wykresu
	int minX = -10, maxX = 10, minY = -10, maxY = 10, res = 1; 

	//Wspolrzedne x, y
	void graphAxis(void);

	//Podstawowe
	void linear(double a, double b);
	void cubic(double a, double b, double c);
	void polynomial(int n);
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