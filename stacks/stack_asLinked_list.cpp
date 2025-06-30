#include<iostream>
#include"stack_as_linked_list.h"
using namespace std;

int main() {
    StackAsLinkedList<int> stll;
    stll.pushTop(1);
    stll.pushTop(2);
    stll.pushTop(3);
    stll.pushTop(4);
    stll.pushTop(5);
    stll.pushTop(6);
    stll.pushTop(7);
    stll.pushTop(8);
    if(!stll.isEmpty()) {
        cout << stll.printTop() << endl;
    }

    while (!stll.isEmpty()) {
        cout << stll.printTop() << endl;
        stll.popTop();
    }
    return 0;
}