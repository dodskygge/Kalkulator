#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <iostream>


class ONPCalc {
private:
	std::stack<int> numbers;
	std::stack<std::string> operators;


	int getPrecedence(std::string& o)
	{
		if (o == "+" || o == "-")
			return 1;

		return 2;
	}

	int calculate(int a, int b, const std::string& operation)
	{
		if (operation == "+")
			return a + b;
		if (operation == "-")
			return a - b;
		if (operation == "*")
			return a * b;
		if (operation == "/")
			return a / b;
		return -1;
	}

	void performOperation(std::stack<int>& numbers, std::stack<std::string>& operators) {
		int n1 = numbers.top();
		numbers.pop();
		int n2 = numbers.top();
		numbers.pop();
		std::string op = operators.top();
		operators.pop();

		numbers.push(calculate(n2, n1, op));
	}

	int RPN(std::vector<std::string>& notation) {

		std::stack<int> numbers;
		std::stack<std::string> operators;

		if (notation.empty())
			return 0;

		numbers.push(stoi(notation[0]));

		for (int i = 1; i < notation.size(); i += 2)
		{
			while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(notation[i]))
				performOperation(numbers, operators);

			numbers.push(std::stoi(notation[i + 1]));
			operators.push(notation[i]);
		}

		while (!operators.empty())
			performOperation(numbers, operators);

		return numbers.top();
	}

	std::vector<std::string> parse(const std::string& input)
	{
		std::vector<std::string> vec;

		std::string current;

		for (char c : input)
		{
			if (isdigit(c))
				current += c;
			else if (c)
			{
				if (!current.empty())
				{
					vec.emplace_back(std::move(current));
					current = "";
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
	int ONP(std::string input) {
		std::vector<std::string> notation = parse(input);

		return RPN(notation);
	}
};
