#include <iostream>
using namespace std;

// Node class: Represents a node in the linked list
class Node
{
public:
    int data;   // Data of the node
    Node *next; // Pointer to the next node

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
    Node *head; // Pointer to the first node (head)
    Node *tail; // Pointer to the last node (tail)

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

    void pushAtPost(int pos, int data)
    {
        pos = pos - 1;

        if (pos == 0 && head != NULL)
        {
            Node *newNode = new Node(data);
            Node *nextNode = head;
            newNode->next = nextNode;
            head = newNode;
            return;
        }

        Node *tempNode = head;
        while (tempNode != NULL && pos >= 1)
        {
            if (pos == 1)
            {
                // Adding Node to the desired position
                Node *newNode = new Node(data);
                Node *nextNode = tempNode->next;
                newNode->next = nextNode;
                tempNode->next = newNode;
                return;
            }
            pos = pos - 1;
            tempNode = tempNode->next;
        }

        if (tempNode == NULL && pos > 1)
        {
            cout << "Node can't be entered at the desired position as there are not such number of elemnts present hence pushing the node at the back of the linked list" << endl;
            Node *newNode = new Node(data);
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

    bool searchInLinkedList(int key)
    {
        Node *tempNode = head;
        while (tempNode != NULL)
        {
            if (tempNode->data == key)
            {
                return true;
            }
            tempNode = tempNode->next;
        }
        return false;
    }
};

int main()
{
    LinkedList linkedList;

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

    cout << "Key 20 is present in linked list = " << linkedList.searchInLinkedList(20);
    return 0;
};