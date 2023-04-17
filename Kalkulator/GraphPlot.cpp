#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include "graphplot.h"
#include <string>

namespace plt = matplotlibcpp;


//X Y AXIS
void GraphPlot::graphAxis(void) {
	
	//Linia wspolrzednej x
	std::vector<double> yx = {0, 0};
	std::vector<double> xx = {-1000000, 1000000};

	//Linia wspolrzednej y
	std::vector<double> yy = {-1000000, 1000000};
	std::vector<double> xy = {0, 0};

	plt::plot(xx, yx, axisColor); //Narysuj linie wsp. x
	plt::plot(xy, yy, axisColor); //Narysuj linie wsp. y
	plt::xlim(minX, maxX);
	plt::ylim(minY, maxY);
};

//FUNCTIONS
void GraphPlot::linear(double a, double b) { //ax+b
	graphAxis();
	std::vector<double> y1;
	std::vector<double> x1;

	for (double i = minX; i <= maxX; i = i + res) {
		x1.insert(x1.begin(), i);
		y1.insert(y1.begin(), (a*i)+b);
	}

	plt::plot(x1, y1, functionColor);
	plt::show();
	return;
};

void GraphPlot::cubic(double a, double b, double c) {
	graphAxis();
	std::vector<double> y2;
	std::vector<double> x2;

	for (double i = minX; i <= maxX; i = i + res) {
		x2.insert(x2.begin(), i);
		y2.insert(y2.begin(), a*pow(i,2) + b * i + c);
	}

	plt::plot(x2, y2, functionColor);
	plt::show();
	return;
};

void GraphPlot::polynomial(double a, double b, double c, double d, double e, double f) {
	graphAxis();
	std::vector<double> y3;
	std::vector<double> x3;


	for (double i = minX; i <= maxX; i = i + res) { //Pêtla wpisuj¹ca wartoœci pod x i y
		x3.insert(x3.begin(), i);
		y3.insert(
			y3.begin(),
			a * pow(i, 5) +
			b * pow(i, 4) +
			c * pow(i, 3) +
			d * pow(i, 2) +
			e * i + f);
	}

	plt::plot(x3, y3, functionColor);
	plt::show();
	return;
};

void GraphPlot::modulus(void) {
	graphAxis();
	std::vector<double> y4;
	std::vector<double> x4;

	for (double i = minX; i <= maxX; i = i + res) {
		x4.insert(x4.begin(), i);
		y4.insert(y4.begin(), sqrt(i*i));
	}

	plt::plot(x4, y4, functionColor);
	plt::show();
	return;
};

void GraphPlot::sinus(void) {
	graphAxis();
	std::vector<double> y5;
	std::vector<double> x5;

	for (double i = minX; i <= maxX; i = i + res) {
		x5.insert(x5.begin(), i);
		y5.insert(y5.begin(), sin(i));
	}

	plt::plot(x5, y5, functionColor);
	plt::show();
	return;
};

void GraphPlot::cosinus(void) {
	graphAxis();
	std::vector<double> y6;
	std::vector<double> x6;

	for (double i = minX; i <= maxX; i = i + res) {
		x6.insert(x6.begin(), i);
		y6.insert(y6.begin(), cos(i));
	}

	plt::plot(x6, y6, functionColor);
	plt::show();
	return;
};

void GraphPlot::tangent(void) {
	graphAxis();
	std::vector<double> y7;
	std::vector<double> x7;

	for (double i = minX; i <= maxX; i = i + res) {
		x7.insert(x7.begin(), i);
		y7.insert(y7.begin(), tan(i));
	}

	plt::plot(x7, y7, functionColor);
	plt::show();
	return;
};

void GraphPlot::logarithmic(void) {
	graphAxis();
	std::vector<double> y8;
	std::vector<double> x8;

	for (double i = minX; i <= maxX; i = i + res) {
		x8.insert(x8.begin(), i);
		y8.insert(y8.begin(), log(i));
	}

	plt::plot(x8, y8, functionColor);
	plt::show();
	return;
};

void GraphPlot::exponential(double a) {
	graphAxis();
	std::vector<double> y9;
	std::vector<double> x9;

	for (float i = minX; i <= maxX; i = i + res) {
		x9.insert(x9.begin(), i);
		y9.insert(y9.begin(), pow(a, i));
	}

	plt::plot(x9, y9, functionColor);
	plt::show();
	return;
};

//Custom function
void GraphPlot::userCustom(std::string customExpression) {
};


//GETTERS & SETTERS
double GraphPlot::get_minX(void) {
	return minX;
};
double GraphPlot::get_maxX(void) {
	return maxX;
};
double GraphPlot::get_minY(void) {
	return minY;
};
double GraphPlot::get_maxY(void) {
	return maxY;
};
double GraphPlot::get_res(void) {
	return res;
};
std::string GraphPlot::get_color(void) {
	return functionColor;
};

void GraphPlot::set_minX(double set) {
	minX = set;
};
void GraphPlot::set_maxX(double set) {
	maxX = set;
};
void GraphPlot::set_minY(double set) {
	minY = set;
};
void GraphPlot::set_maxY(double set) {
	maxY = set;
};
void GraphPlot::set_res(double set) {
	res = set;
};
void GraphPlot::set_color(std::string set) {
	functionColor = set;
};