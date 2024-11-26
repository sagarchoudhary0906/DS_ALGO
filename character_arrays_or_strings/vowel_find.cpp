#include<iostream>
#include<string>
using namespace std;

string vowel(string S) {
    string ans = "";
    for (char ch: S) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ans = ans + ch;
        }
    }

    return ans;
}


int main() {
    string S = "aeoibsddaeioudb";
    cout << vowel(S);
    return 0;
}