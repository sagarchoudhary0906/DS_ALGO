#include<iostream>
#include"stack_as_array.h"
using namespace std;

int main() {
    Stack<int> s(5);

    s.pushFront(1);
    s.pushFront(2);
    s.pushFront(3);
    s.pushFront(4);
    s.pushFront(5);

    while (!s.isEmpty()) {
        cout << s.getTop() << endl;
        s.popFront();
    }
    return 0;
}