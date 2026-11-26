#pragma once
#ifndef STATICQUEUE_H_INCLUDED
#define STATICQUEUE_H_INCLUDED

using namespace std;

class Queue {
public:
    virtual void enqueue(int) = 0;
    virtual int dequeue() = 0;
    virtual bool isempty() = 0;
    virtual bool isfull() = 0;
    virtual void print() = 0;

    class Queue_Overflow {};
    class Queue_Underflow {};
};

class Array_Queue : public Queue {
private:
    int* tomb;
    int front;
    int end;
    int max;

public:
    Array_Queue(int max = 100);
    Array_Queue(const Array_Queue&);
    ~Array_Queue();

    virtual void enqueue(int);
    virtual int dequeue();
    virtual bool isempty();
    virtual bool isfull();
    virtual void print();
};

#endif