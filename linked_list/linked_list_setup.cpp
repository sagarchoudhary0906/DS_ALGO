/**
 * A Linked LIst ALywas has only Two pointers Head and Tail
 * Head is the first node of the list
 * Tail is the last node of the list
 * Head and Tail are pointers to the first and last node of the list respectively
 * Head and Tail are used to traverse the list
 * Head and Tail are used to insert and delete nodes from the list
 * Head and Tail are used to search for a node in the list
 * Head and Tail are used to sort the list
 */

/**
 * Node is a class that represents a node in the linked list
 * It has two attributes:
 * 1. data: int
 * 2. next: Node*
 * 3. Constructor: Node(int data)
 * 4. Getter and Setter for data and next
 */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    // Attributes
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    // Puhsing Forwrad in a linked list
    void pushForward(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // Puhsing BackWard in a Linked List
    void pushBackward(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printLinkedList()
    {
        Node *tempNode = head;
        cout << "Printing LinkedList -> ";
        while (tempNode != NULL)
        {
            int data = tempNode->data;
            Node *nextNode = tempNode->next;
            cout << data << " -> ";
            tempNode = nextNode;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList linkedList = LinkedList();
    linkedList.pushForward(5);
    linkedList.pushForward(4);
    linkedList.pushForward(3);
    linkedList.pushForward(2);
    linkedList.pushForward(1);

    linkedList.pushBackward(6);
    linkedList.pushBackward(7);
    linkedList.pushBackward(8);
    linkedList.pushBackward(9);
    linkedList.pushBackward(10);

    linkedList.printLinkedList();
    return 0;
}