#include <iostream>
#include "stack_as_vector.h"
using namespace std;

int main()
{
    StackAsVector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
    s.printStack();
    cout << "Top element of stack " << s.getTop() << endl;
    return 0;
}