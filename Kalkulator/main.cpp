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
	




	graph->minY = -15;
	graph->minY = 15;
	graph->graphAxis();
	graph->polynomial(5);

	plt::xlim(graph->minX, graph->maxX); 	
	plt::ylim(graph->minY, graph->maxY);

	plt::show();


	delete graph;
	return 0;
}