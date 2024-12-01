#include <iostream>
#include "vector_header_file.h"
using namespace std;

int main()
{
    Vector<char> v(1);
    cout << "Size of vector = " << v.size() << endl;
    cout << "Capacity of vector = " << v.capacity() << endl;
    cout << "Is Empty = " << v.isEmpty() << endl;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    v.push_back('d');
    v.push_back('e');
    v.push_back('f');
    v.push_back('g');

    cout << "Size of vector = " << v.size() << endl;
    cout << "Capacity of vector = " << v.capacity() << endl;
    cout << "Is Empty = " << v.isEmpty() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
    return 0;
}