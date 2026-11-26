#include"StaticStack.h"
#include<iostream>
using namespace std;
Array_Stack::Array_Stack(int max) {//definialjuk az osztaly osszes metodusat
    this->max = max;
    this->top = 0;
    this->tomb = new int[max];
}
Array_Stack::Array_Stack(const Array_Stack& param) {
    this->max = param.max;
    this->top = param.top;
    this->tomb = new int[max];
    for (int i = 0; i < top; ++i)
        this->tomb[i] = param.tomb[i];
}
Array_Stack::~Array_Stack() {
    this->top = 0;
    this->max = 0;
    delete[] this->tomb;
}
bool Array_Stack::isempty() {
    if (this->top == 0) return true;
    else
        return false;


}
bool Array_Stack::isfull() {
    if (this->top == this->max) return true;
    else return false;

}
int Array_Stack::peek() {
    if (isempty()) throw Stack_Underflow();
    else return this->tomb[this->top - 1];
}
int Array_Stack::pop() {
    if (isempty()) throw Stack_Underflow();
    else return this->tomb[--this->top];

}
void Array_Stack::push(int element) {
    if (isfull()) throw Stack_Overflow();
    else this->tomb[this->top++] = element;

}
void Array_Stack::print() {
    for (int i = 0; i < top; ++i) {
        cout << tomb[i] << " ";
    }
}
