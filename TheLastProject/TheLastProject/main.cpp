#include <iostream>
#include "Queue.h"

void sequence(Queue*);

int main() {
	Queue* q = new Queue();
	sequence(q);
}

void sequence(Queue* q) {
	q->enqueue(5);
	q->enqueue(7);

	q->dequeue();
	q->enqueue(3);
	q->enqueue(6);
	q->enqueue(9);

	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->dequeue();
}