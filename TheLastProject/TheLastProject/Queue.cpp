#include "Queue.h"
#include <iostream>

Queue::Queue()
{
}

Queue::~Queue()
{
}

void Queue::enqueue(int data)
{
	// Push into stackA
	stackA.push(data);
	this->printStacks();
}

int Queue::dequeue()
{
	//if b is empty
	if (!this->stackB.empty())
		;
	// if B is not empty
	else {
		// while A is not empty
		while (!this->stackA.empty()) {
			// push A's top into B
			stackB.push(this->stackA.top()), this->stackA.pop();
		}
	}
	// pop and return B's top
	int b_top = this->stackB.top();
	this->stackB.pop();
	this->printStacks();
	return b_top;
}

bool Queue::isEmpty()
{
	if (this->stackA.empty() && this->stackB.empty())
		return true;
}

int Queue::size()
{
	if (this->stackA.empty() && this->stackB.empty())
		return 0;
	else
		return this->stackA.size() + this->stackB.size();
}

void Queue::printStacks() {
	// construct temp queues
	std::stack<int> tempA = this->stackA;
	std::stack<int> tempB = this->stackB;

	// print stackA
	std::cout << "Stack A: ";
	while (!tempA.empty())
		std::cout << tempA.top() << " ", tempA.pop();
	std::cout << std::endl;
	std::cout << "Stack B: ";
	while (!tempB.empty())
		std::cout << tempB.top() << " ", tempB.pop();
	std::cout << std::endl << std::endl;
	return;
}
