#include<iostream>
#include<cstring>
using namespace std;

int main() {
    //  char sentence[1000] = "sagar";
     char sentence[] = {'s', 'a', 'g', 'a', 'r', '\0'};
     cout << strlen(sentence) << endl << sizeof(sentence) << endl; // Output is 5 if talk about storage it actually has 6 charcater that is null charcter at the end

    char b[1000];
    strcpy(b , sentence);
    cout << endl << b << endl;

    // Compare 
    cout << strcmp(sentence, b)<< endl; // If 0 means strings are equals if not it will give some +ve or negative value accoridng to the scii value

    char a1[] = "abc";
    char a2[] = "def";

    cout << strcmp(a2, a1)<< endl; // If 0 means strings are equals if not it will give some +ve or negative value accoridng to the scii value

    // Concat 

    char b1[] = "www.";
    char b2[] = "coding.sagar.com";
    cout << strcat(b1, b2) << endl << b1;
    
    return 0;
}