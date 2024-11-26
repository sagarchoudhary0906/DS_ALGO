#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char sentence[1000];
    int n;
    cout << "Enter the number of strings = ";
    cin >> n;
    cout << endl;

    cin.get();

    int largestLength = INT_MIN;
    char largestSentence[1000] = "";

    while (n > 0) {
        cin.getline(sentence, 1000);
        int len = strlen(sentence);
        if (len > largestLength) {
            largestLength = len;
            strcpy(largestSentence, sentence);
        }
        n--;
    }
    cout << "Largest Length is = " << largestLength << " and largest string is = " << largestSentence << endl;
    return 0;
}