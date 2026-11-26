#pragma once //csak egyszer include-olja az aktualis .h file-t
#ifndef STATICSTACK_H_INCLUDED
#define STATICSTACK_H_H_INCLUDED
using namespace std;
class Stack {//osztaly deklaralasa
public:
    virtual void push(int) = 0;//tiszta virtualis fuggveny/absztract fuggveny
    virtual int pop() = 0;
    virtual int peek() = 0;
    virtual bool isempty() = 0;
    virtual bool isfull() = 0;
    virtual void print() = 0;

    class Stack_Overflow {};//felulcsordulas;
    class Stack_Underflow {};//alulcsordulas;

};
class Array_Stack :public Stack {
private:
    int* tomb;
    int top;
    int max;
public:
    Array_Stack(int max = 100);
    Array_Stack(const Array_Stack&);//
    ~Array_Stack();//destruktor
    virtual void push(int);
    virtual int pop();
    virtual int peek();
    virtual bool isempty();
    virtual bool isfull();
    virtual void print();
};

#endif // STATICSTACK_H_H_INCLUDED
