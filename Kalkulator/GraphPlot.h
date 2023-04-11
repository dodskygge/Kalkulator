#pragma once

#define _USE_MATH_DEFINES
#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include <string>

class GraphPlot {
private:
	// Zainicjowane wartoœci domyœlne dla rozmiaru wykresu
	double minX = -10, maxX = 10, minY = -10, maxY = 10, res = 0.2;
public:

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

	//Gettery i settery
	double get_minX(void);
	double get_maxX(void);
	double get_minY(void);
	double get_maxY(void);
	double get_res(void);

	void set_minX(double set);
	void set_maxX(double set);
	void set_minY(double set);
	void set_maxY(double set);
	void set_res(double set);

};