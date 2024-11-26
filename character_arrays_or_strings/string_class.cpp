#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s; // Dynamic array size can be changed at runtime also
    s = "Hello World";
    getline(cin, s); // This function has also third deilemeter which tells function when to stop if no third argumnet means it will stop at enter or new line
    cout << s << endl;
    return 0;
}