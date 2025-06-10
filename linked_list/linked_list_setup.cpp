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

// Node class: Represents a node in the linked list
class Node
{
public:
    int data;      // Data of the node
    Node *next;    // Pointer to the next node

    // Constructor: Initializes data and sets next to NULL
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// LinkedList class: Manages the entire linked list
class LinkedList
{
    Node *head;    // Pointer to the first node (head)
    Node *tail;    // Pointer to the last node (tail)

public:
    // Constructor: Initializes head and tail to NULL
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    // Insert a node at the front of the linked list
    void pushForward(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            // If the list is empty, both head and tail point to newNode
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            // Insert newNode before the current head and update head
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert a node at the end of the linked list
    void pushBackward(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            // If the list is empty, both head and tail point to newNode
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            // Add newNode after the current tail and update tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print the entire linked list
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

    // Insert nodes at the front
    linkedList.pushForward(5);
    linkedList.pushForward(4);
    linkedList.pushForward(3);
    linkedList.pushForward(2);
    linkedList.pushForward(1);

    // Insert nodes at the end
    linkedList.pushBackward(6);
    linkedList.pushBackward(7);
    linkedList.pushBackward(8);
    linkedList.pushBackward(9);
    linkedList.pushBackward(10);

    // Print the linked list
    linkedList.printLinkedList();
    return 0;
}