#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char sentence[1000];
    cin.getline(sentence, 1000);

    int N = 0;
    int S = 0;
    int E = 0;
    int W = 0;

    char lastChar = ' ';

    for (int i = 0; i < strlen(sentence) && sentence[i] != '\0'; i++)
    {
        char ch = sentence[i];
        cout << "ch is = " << ch << " and last char is = " << lastChar << endl; 
        if (ch == 'N')
        {
            if (lastChar != 'N' && S > 0)
            {
                S--;
            }
            else
            {
                N++;
            }
        }
        else if (ch == 'S')
        {
            if (lastChar != 'S' && N > 0)
            {
                N--;
            }
            else
            {
                S++;
            }
        }
        else if (ch == 'E')
        {
            if (lastChar != 'E' && W > 0)
            {
                W--;
            }
            else
            {
                E++;
            }
        }
        else if (ch == 'W')
        {
            if (lastChar != 'W' && E > 0)
            {
                E--;
            }
            else
            {
                W++;
            }
        }
        lastChar = ch;
        cout << N << " "<< S << " " << E << " " << W << endl; 
    }

    while (N > 0)
    {
        cout << "N";
        N--;
    }
    while (S > 0)
    {
        cout << "S";
        S--;
    }
    while (E > 0)
    {
        cout << "E";
        E--;
    }
    while (W > 0)
    {
        cout << "W";
        W--;
    }
    cout << endl;

    return 0;
}