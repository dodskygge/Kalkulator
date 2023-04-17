#pragma once
#include<iostream>

using namespace std;

class Stack {
private:
	//Maximum Size of Stack is Private 
	double* stack;
	double* dummy;
	int top, max;
	double temp;

	// Increase the size of stack by 1
	double incStack() {
		dummy = stack;
		stack = new double[max + 1];
		for (int i = 0; i < max; i++) {
			stack[i] = dummy[i];
		}
		max++;
		delete[] dummy;
		return 1;
	}
	// Doubling the stack by twice
	double doubleStack() {
		dummy = stack;
		stack = new double[max * 2];
		for (int i = 0; i < max; i++) {
			stack[i] = dummy[i];
		}
		max = max * 2;
		delete[] dummy;
		return 1;
	}

public:
	// Constructor of Stack
	Stack(void) {
		stack = new double[1];
		top = -1;
		max = 1;
		temp = 0;
	}

	// Push operations on stack
	int push(double value) {
		if (top >= max - 1) {
			//incStack();
			doubleStack();
		}
		top = top + 1;
		stack[top] = value;
		return 1;
	}

	// Pop operations on stack
	int pop() {
		if (top > -1) {
			top--;
			return 1;
		}
		cout << "stack is empty" << endl;
		return 0;
	}

	// Top operations on stack

	double topElement() {
		if (top > -1) {
			return stack[top];
		}
		cout << "stack is empty" << endl;
		return 0;
	}

	// Length of stack

	int length() {
		return top + 1;
	}

	//is empty
	bool isEmpty() {
		if (top > -1) {
			return false;
		}
		return true;
	}
};


class StackString {
private:
	//Maximum Size of Stack is Private 
	string* stack;
	string* dummy;
	int top, max;
	string temp;

	// Increase the size of stack by 1
	double incStack() {
		dummy = stack;
		stack = new string[max + 1];
		for (int i = 0; i < max; i++) {
			stack[i] = dummy[i];
		}
		max++;
		delete[] dummy;
		return 1;
	}
	// Doubling the stack by twice
	double doubleStack() {
		dummy = stack;
		stack = new string[max * 2];
		for (int i = 0; i < max; i++) {
			stack[i] = dummy[i];
		}
		max = max * 2;
		delete[] dummy;
		return 1;
	}

public:
	// Constructor of Stack
	StackString(void) {
		stack = new string[1];
		top = -1;
		max = 1;
	}

	// Push operations on stack
	int push(string value) {
		if (top >= max - 1) {
			//incStack();
			doubleStack();
		}
		top++;
		stack[top] = value;
		return 1;
	}

	// Pop operations on stack
	int pop() {
		if (top > -1) {
			temp = stack[top];
			top--;
			return 1;
		}
		cout << "Stack empty";
		return 0;
	}

	// Top operations on stack

	string topElement() {
		if (top > -1) {
			return stack[top];
		}
		cout << "Stack empty";
		return "e";
	}

	// Length of stack

	int length() {
		return top + 1;
	}

	//is empty
	bool isEmpty() {
		if (top > -1) {
			return false;
		}
		return true;
	}
};
