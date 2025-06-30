#include <iostream>

// Defining Custom Node Class
template <typename T>
class Node
{
public:
    /* data */
    T data;
    Node<T> *next;

    // Constructor
    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

// Defining Custom Stack Class
template <typename T>
class StackAsLinkedList
{
private:
    Node<T> *head;

public:
    // Constructor
    StackAsLinkedList()
    {
        head = NULL;
    };
    // Push Function
    void pushTop(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    // Pop Function
    void popTop()
    {
        if (head != NULL)
        {
            Node<T> *topNode = head;
            head = topNode->next;
            delete topNode;
        }
    }

    // Print Stack Function
    void printStack()
    {
        Node<T> *tempNode = head;
        while (tempNode)
        {
            tempNode = tempNode->next;
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    T printTop()
    {
        return head->data;
    }
};
