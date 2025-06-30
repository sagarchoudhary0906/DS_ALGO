template <typename T>
class Stack
{
private:
    T *array;
    int maxCap;
    int size;

public:
    Stack(int capacity)
    {
        array = new T[capacity];
        size = 0;
        maxCap = capacity;
    }

    void pushFront(T data)
    {
        if (size >= maxCap)
        {
            T *newArray = new T[2 * maxCap];
            for (int i = 0; i < maxCap; i++)
            {
                newArray[i] = array[i];
            }
            maxCap = 2 * maxCap;
            array = newArray;
        }
        array[size] = data;
        size++;
    }

    void popFront()
    {
        if (size <= 0)
        {
            return;
        }
        else
        {
            int idxToUse = size - 1;
            array[idxToUse] = -1;
            size--;
        }
    }

    T getTop() {
        int idxToUse = size - 1;
        return array[idxToUse];
    }

    bool isEmpty()
    {
        return size < 0 || size == 0;
    }

    int getSize() {
        return size;
    }
};
