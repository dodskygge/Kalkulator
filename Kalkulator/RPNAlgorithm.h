#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include "stack.h"


class ONPCalc {
private:
	Stack numbers;
	StackString operators;


	double getPrecedence(string o)
	{
		if (o == "+" || o == "-")
			return 1;

		return 2;
	}

	double calculate(double a, double b, const string operation)
	{
		if (operation == "+")
			return a + b;
		else if (operation == "-")
			return a - b;
		else if (operation == "*")
			return a * b;
		else if (operation == "/")
			return a / b;
		else if (operation == "^")
			return pow(a, b);
		else
			return -99999;
	}

	void performOperation(void) {
		double n1 = numbers.topElement();
		numbers.pop();
		double n2 = numbers.topElement();
		numbers.pop();
		string op = operators.topElement();
		operators.pop();

		numbers.push(calculate(n2, n1, op));
	}

	double RPN(vector<string>& notation) {

		if (notation.empty())
			return 0;

		numbers.push(stoi(notation[0]));

		for (int i = 1; i < notation.size(); i += 2)
		{
			while (!operators.isEmpty() && getPrecedence(operators.topElement()) >= getPrecedence(notation[i]))
				performOperation();

			numbers.push(stoi(notation[i + 1]));
			operators.push(notation[i]);
		}

		while (!operators.isEmpty())
			performOperation();

		return numbers.topElement();
	}

	vector<string> parse(const string& input)
	{
		vector<string> vec;

		string current;

		for (char c : input)
		{
			if (isdigit(c))
				current += c;
			else if (c)
			{
				if (!current.empty())
				{
					vec.emplace_back(move(current));
					current = " ";
				}

				if (c != ' ')
					vec.emplace_back(1, c);
			}
		}

		if (!current.empty())
			vec.push_back(std::move(current));

		return vec;
	}



public:
	double calculate(string input) {
		vector<string> notation = parse(input);

		return RPN(notation);
	}
};
