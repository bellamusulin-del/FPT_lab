#include "StaticStack.h"
#include "StaticQueue.h"
#include <iostream>
using namespace std;

int main() {
    Array_Stack st;

    try {
        st.push(10);
        st.push(20);

        int vf = st.peek();
        cout << vf << endl;
    }
    catch (Array_Stack::Stack_Underflow ex) {
        cout << "Stiva goala" << endl;
    }

    Array_Queue q;

    try {
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        q.print();

        cout << endl;

        int vf = q.dequeue();
        cout << "Kivett elem: " << vf << endl;

        q.print();
    }
    catch (Queue::Queue_Underflow ex) {
        cout << "A sor ures";
    }
    catch (Queue::Queue_Overflow ex) {
        cout << "A sor tele van";
    }

    return 0;
}


