#include<iostream>
#include<cstring>
using namespace std;


void printPermutation(string str, int si , int ei) {
    if (si == ei) {
        cout << str << " ";
        return;
    }

    for (int i = si; i <= ei; i++) {
        swap(str[i], str[si]);
        printPermutation(str, si + 1, ei);
        swap(str[i], str[si]);
    }
}

int main() {
    string str = "abc";
    printPermutation(str, 0, str.length() - 1);
    return 0;
}