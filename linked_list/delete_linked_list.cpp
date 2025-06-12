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

    /**
     * What happens here?
     * When a Node object is deleted, its destructor is called.
     * If the node’s next pointer is not NULL, it recursively deletes the next node.
     * This process continues until the end of the list (next == NULL).
     * Each node prints a message when it is deleted.
     */
    ~Node() {
        if (next != NULL) {
            delete next;
        }
        cout << "Deleteing next node woth data = " << data << endl;
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

    void pushAtPost(int pos, int data) {
        pos = pos - 1;

        if (pos == 0 && head != NULL) {
            Node *newNode = new Node(data);
            Node *nextNode = head;
            newNode->next = nextNode;
            head = newNode;
            return;
        }

        Node *tempNode = head;
        while (tempNode != NULL && pos >= 1) {
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

        if (tempNode == NULL && pos > 1) {
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

    /**
     * What happens here?
     * When a LinkedList object is destroyed (for example, when it goes out of scope at the end of main()), its destructor is called.
     * The destructor deletes the head node.
     * Because of the recursive destructor in the Node class, deleting the head node triggers deletion of the entire list.
     * 
     * STEP BY STEP EXAMPLE :
     * Linked LIST -> 1 -> 2 -> 3 -> 4 -> 5
     * delete head (node 1)
     * -> node 1 destructor: delete next (node 2)
     * -> node 2 destructor: delete next (node 3)
     * -> node 3 destructor: delete next (node 4)
     * -> node 4 destructor: delete next (node 5)
     * -> node 5 destructor: next is NULL, done
     */
    ~LinkedList() {
        if (head != NULL) {
            delete head;
        }
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

    //Pushing Element at particular position in linked list
    linkedList.pushAtPost(1, -3);
    linkedList.pushAtPost(1, -1);
    linkedList.pushAtPost(20, 20);

    // Print the linked list
    linkedList.printLinkedList();
    return 0;
}