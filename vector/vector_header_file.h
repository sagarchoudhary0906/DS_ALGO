template<typename T> // This is how you make a class generic in c++ with templates
class Vector
{
    // Data Member
    T *arr;
    int curr_size; // Current Size
    int max_size;

public:
    // Constructor
    Vector(int maxSize = 1)
    {
        curr_size = 0;
        max_size = maxSize;
        arr = new T[max_size];
    };

    void push_back(const T data)
    {
        if (curr_size == max_size)
        {
            // Creating a new array and deleting th eold one , doubling the capacity
            T *oldArr = arr;
            max_size = 2 * max_size;
            arr = new T[max_size];

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

    bool isEmpty() const
    {
        return curr_size == 0;
    }

    int size() const
    {
        return curr_size;
    }

    int capacity() const
    {
        return max_size;
    }

    T front() const {
        return arr[0];
    }

    T last() const{
        return arr[curr_size - 1];
    }

    T at(int index) const{
        return arr[index];
    }

    // Operator overloading
    T operator[] (const int i) {
        return arr[i];
    }
};