#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "Enter String = "; 
    char sentence[1000];
    cin.getline(sentence, 1000);
    cout << sentence<< endl << strlen(sentence) << endl<<sizeof(sentence);

    return 0;
}