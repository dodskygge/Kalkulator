#pragma once

#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include <string>

class GraphPlot {
private:
	// DECLARATIONS
	double minX = -10, maxX = 10, minY = -10, maxY = 10, res = 0.2;
	std::string axisColor = "grey", functionColor = "red";
public:

	//X Y AXIS
	void graphAxis(void);

	//METHODS
	void linear(double a, double b);
	void cubic(double a, double b, double c);
	void polynomial(double a, double b, double c, double d, double e, double f);
	void modulus(void);
	void sinus(void);
	void cosinus(void);
	void tangent(void);
	void logarithmic(void);
	void exponential(double a);
	void userCustom(std::string customExpression); 

	//GETTERS & SETTERS
	double get_minX(void);
	double get_maxX(void);
	double get_minY(void);
	double get_maxY(void);
	double get_res(void);
	std::string get_color(void);


	void set_minX(double set);
	void set_maxX(double set);
	void set_minY(double set);
	void set_maxY(double set);
	void set_res(double set);
	void set_color(std::string set);

};