#include "StaticQueue.h"
#include <iostream>
using namespace std;

Array_Queue::Array_Queue(int max) {
    this->max = max;
    this->front = 0;
    this->end = 0;
    this->tomb = new int[max];
}

Array_Queue::Array_Queue(const Array_Queue& param) {
    this->max = param.max;
    this->front = param.front;
    this->end = param.end;
    this->tomb = new int[max];

    for (int i = front; i < end; ++i)
        this->tomb[i] = param.tomb[i];
}

Array_Queue::~Array_Queue() {
    this->front = 0;
    this->end = 0;
    this->max = 0;
    delete[] this->tomb;
}

bool Array_Queue::isempty() {
    if (this->front == this->end) return true;
    else return false;
}

bool Array_Queue::isfull() {
    if (this->end == this->max) return true;
    else return false;
}

void Array_Queue::enqueue(int element) {
    if (isfull()) throw Queue_Overflow();
    else this->tomb[this->end++] = element;
}

int Array_Queue::dequeue() {
    if (isempty()) throw Queue_Underflow();
    else return this->tomb[this->front++];
}

void Array_Queue::print() {
    for (int i = front; i < end; ++i) {
        cout << tomb[i] << " ";
    }
}
