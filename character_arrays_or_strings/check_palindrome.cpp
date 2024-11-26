#include<iostream>
#include<cstring>
using namespace std;

int main() {
    string str = "abcdcda";
    int si = 0 ; 
    int ei = str.length() - 1;

    bool isPalindrome = true;
    while (si < ei) {
        char siChar = str[si];
        char eiChar = str[ei];
        cout << "Comapring " << siChar << " " << eiChar << endl;
        if (siChar != eiChar) {
            isPalindrome = false;
            break;
        }
        si++;
        ei--;
    } 

    cout << "Is Palindrome = " << isPalindrome<< endl;
    return 0;
}