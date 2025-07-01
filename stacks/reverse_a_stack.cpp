#include<iostream>
#include<stack>
using namespace std;


void insertAtTheBottomRecursion(stack<int> &s, int data) {
    if(s.empty()) {
        s.push(data);
        return;
    }

    int top = s.top();
    s.pop();
    insertAtTheBottomRecursion(s, data);
    s.push(top);
}

void recursivelyReverseAStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }
    //Top Element 
    int top = s.top();
    //Popinp Top Element
    s.pop();
    // Making recursive call to rest of the stack to reverse it
    recursivelyReverseAStack(s);
    // Trusting that the recursion has revrsed the stack and now adding top element at the bottom of the stack
    insertAtTheBottomRecursion(s, top);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    recursivelyReverseAStack(s);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}