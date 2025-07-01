/**
 * Insert at the bottom of the stack
 */


#include<iostream>
#include<stack>
#include<vector>
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


void insertAtBottomUsingDataStructure(stack<int> &s, int data) {
    vector<int> v;

    // Empty the full stack and store its elemnts in an order in a vector
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    //Adding lasy element at the bottom now
    s.push(data);

    // Adding all syored elements back in stack
    for (int i = 0; i < v.size(); i++) {
        s.push(v[i]);
    }
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // insertAtTheBottomRecursion(s, 5);
    insertAtBottomUsingDataStructure(s, 10);

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}