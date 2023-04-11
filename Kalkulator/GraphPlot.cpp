#define _USE_MATH_DEFINES
#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include "graphplot.h"
#include <string>

namespace plt = matplotlibcpp;


//Linie wspó³rzêdnych
void GraphPlot::graphAxis(void) {
	
	//Linia wspolrzednej x
	std::vector<double> yx = {0, 0};
	std::vector<double> xx = {-1000000, 1000000};

	//Linia wspolrzednej y
	std::vector<double> yy = {-1000000, 1000000};
	std::vector<double> xy = {0, 0};

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

	plt::plot(x1, y1, "red");
};

void GraphPlot::cubic(double a, double b, double c) {
	std::vector<double> y2;
	std::vector<double> x2;

	for (double i = -10; i <= 10; i = i + 1) {
		x2.insert(x2.begin(), i);
		y2.insert(y2.begin(), (a * i) + b);
	}

	plt::plot(x2, y2, "black");
};

void GraphPlot::polynomial(int n) { 
	if (n > 5) {
		return;
	}

	int factorArray[6] = {0, 0, 0, 0, 0, 0};
	int factorIndex = 0;

	std::vector<double> y3;
	std::vector<double> x3;


	while (factorIndex <= n) { // Wpisanie wybranej iloœci wspó³czynników
		std::cout << "Podaj wspó³czynnik przy przy X ^ " << factorIndex << ":";
		std::cin >> factorArray[factorIndex];

		factorIndex++;
	}

	for (double i = -10; i <= 10; i = i + 1) { //Pêtla wpisuj¹ca wartoœci pod x i y
		x3.insert(x3.begin(), i);
		y3.insert(
			y3.begin(),
			factorArray[5] * pow(i, 5) +
			factorArray[4] * pow(i, 4) +
			factorArray[3] * pow(i, 3) +
			factorArray[2] * pow(i, 2) +
			factorArray[1] * i +
			factorArray[0]
		);
	}

	plt::plot(x3, y3, "black");

	return;
};




void GraphPlot::modulus(double a, double b, double c) {
};

//Funkcje trygonometryczne
void GraphPlot::sinus(void) {
};
void GraphPlot::cosinus(void) {
};
void GraphPlot::tangent(void) {
};

//Funkcje wyk³adnicze
void GraphPlot::logarithmic(double a) {
};
void GraphPlot::exponential(double a) {
};

//Funkcja custom ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
void GraphPlot::userCustom(std::string customExpression) {
};


//Gettery i settery
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



