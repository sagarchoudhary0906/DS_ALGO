#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class StackAsVector
{
    vector<T> arr;

public:
    void push_back(T data)
    {
        arr.push_back(data);
    }

    int getTop()
    {
        int idxToUse = arr.size() - 1;
        return arr[idxToUse];
    }

    bool isEmpty()
    {
        return arr.size() == 0;
    }

    void pop_back()
    {
        if (!isEmpty())
        {
            arr.pop_back();
        }
        else
        {
            cout << "Stack Is emty cant popuop anything";
        }
    }

    void printStack()
    {
        int i = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << "\n";
        }

        cout << "---------------\n";
    }
};