#include <iostream>
#include <cstring>
using namespace std;

// ALways terminate a charcter array with a null character
int main()
{
    char a[100];
    char a1[100] = {'a', 'b', 'c', 'e', 'f', 'g', 'h'}; // This type of declaration is wrong
    char a2[100] = {'a', 'b', 'c', '\0'};               // Right
    char a3[100] = "abc";                               // This automatically adds null charcater at the end of "abc" string
    cout << a1 << endl
         << a2 << endl
         << a3 << endl
         << strlen(a1) << endl // This gives actual length of string which is visible to us
         << sizeof(a1) << endl;        // THis gives the size of chaarcter array


    // Taking Input
    // char b[100];
    // cin >> b; // If taking input via cin it will take string till it encounters the first space or new line so if inout is "Hello world" cout will show "Hello" only.
    // cout << b;

    // TAKING PROBLEM AS THERE WAS A PROBLEM WITH CIN to take character array as input
    // While taking input from cin it goes into buffer so if inout is "hello world" ['h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'];
    // As cin does not process space/newline hence input buffer will contain hello only and the space will automatically replcaed by a null character
    cout << endl <<"Enter input for character array" << endl;
    char c[1000];
    char temp = cin.get();

    int len = 0;
    while (temp != '\n') {
        len++;
        cout << temp;
        temp = cin.get();
    }
    cout << endl <<"Length " << len << endl;
    return 0;
}