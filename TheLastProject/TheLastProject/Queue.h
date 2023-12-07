#pragma once
#include <iostream>
#include <stack>

class Queue
{
	private:
		std::stack<int> stackA;
		std::stack<int> stackB;
	public:
		Queue();
		~Queue();
		void enqueue(int);
		int dequeue();
		bool isEmpty();
		int size();
		void printStacks();
};
