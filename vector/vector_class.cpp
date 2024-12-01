#include <iostream>
using namespace std;

class Vector
{
    // Data Member
    int *arr;
    int curr_size; // Current Size
    int max_size;

public:
    // Constructor
    Vector()
    {
        curr_size = 0;
        max_size = 1;
        arr = new int[max_size];
    };

    void push_back(int data)
    {
        if (curr_size == max_size)
        {
            // Creating a new array and deleting th eold one , doubling the capacity
            int *oldArr = arr;
            max_size = 2 * max_size;
            arr = new int[max_size];

            // Copying the older array element to newer array
            for (int i = 0; i < curr_size; i++)
            {
                arr[i] = oldArr[i];
            }
            // Deleting the older array
            delete[] oldArr;
        }
        arr[curr_size] = data;
        curr_size++;
    }

    void pop_back()
    {
        if (curr_size > 0)
        {
            curr_size--;
        }
    }

    bool isEmpty()
    {
        return curr_size == 0;
    }

    void printVector()
    {
        for (int i = 0; i < curr_size; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }

    int size()
    {
        return curr_size;
    }

    int capacity()
    {
        return max_size;
    }
};

int main()
{
    Vector v = Vector();
    cout << "Is Empty " << v.isEmpty() << endl;
    v.push_back(1);
    cout << "Is Empty " << v.isEmpty() << endl;
    v.printVector();
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    cout << "Size of vector is =  " << v.size() << endl;
    cout << "Capcity of vector is =  " << v.capacity() << endl;
    v.printVector();
    v.pop_back();
    cout << "Size of vector is =  " << v.size() << endl;
    cout << "Capcity of vector is =  " << v.capacity() << endl;
    v.printVector();
    return 0;
}