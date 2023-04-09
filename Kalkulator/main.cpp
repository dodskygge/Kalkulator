// 
//

#define _USE_MATH_DEFINES
#include "matplotlibcpp.h"
#include <cmath>
#include <math.h>
#include <vector>
#include <iostream>
#include "graphplot.h"
#include <stack>

using namespace std;

namespace plt = matplotlibcpp;

int main() {
	GraphPlot* graph;
	graph = new GraphPlot;
	//Funkcja1
	std::vector<double> y1;
	std::vector<double> x1;

	//Rozdzielczosc i rozmiar
	double minX = -10;
	double maxX = 10;
	double minY = -10;
	double maxY = 10;
	double res = 0.1;
	
	graph->graphAxis(minX, maxX, minY, maxY);
	graph->linear(1, 2);

	plt::xlim(-10, 10); 	
	plt::ylim(-10, 10);		

	plt::show();


	delete graph;
	return 0;
}