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
    int data;   // Data of the node
    Node *next; // Pointer to the next node

    // Constructor: Initializes data and sets next to NULL
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

// LinkedList class: Manages the entire linked list
class LinkedList
{

public:
    Node *head; // Pointer to the first node (head)
    Node *tail; // Pointer to the last node (tail)
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

    ~LinkedList()
    {
        if (head != NULL)
        {
            delete head;
        }
    }

    /**
     * Function to delete the first node (head) from the linked list and shift the head to the next node.
     *
     * Example:
     * Suppose the linked list is:  10 -> 20 -> 30 -> 40
     * After calling popFront(), the list becomes: 20 -> 30 -> 40
     *
     * Step-by-step:
     * 1. Store the current head node in a temporary pointer (tempNode).
     * 2. Move the head pointer to the next node (head = head->next).
     * 3. Disconnect the tempNode from the list (tempNode->next = NULL).
     * 4. Delete tempNode to free memory.
     *
     * If the list is already empty (head == NULL), print a message and do nothing.
     */
    void popFront()
    {
        if (head == NULL)
        {
            cout << "Linekd LIst was already empty" << endl;
            return;
        }

        Node *tempNode = head;
        head = head->next;
        tempNode->next = NULL;
        delete tempNode;
    }

    Node *deleteTailRecursively(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        if (head->next != NULL)
        {
            Node *tempNode = deleteTailRecursively(head->next);
            if (tempNode == NULL)
            {
                head->next = NULL;
            }
            return head;
        }
        else
        {
            cout << "Deleting Tail Node with data = " << head->data << endl;
            delete head;
            return NULL;
        }
    }

    void deleteTailLinearly()
    {
        if (head == NULL)
        {
            cout << "Linekd List is already empty" << endl;
            return;
        }

        Node *tempNode = head;
        Node *secondLastNode = head;
        while (tempNode != NULL)
        {
            if (tempNode->next == NULL)
            {
                cout << "deleting last node with data = " << tempNode->data;
                secondLastNode->next = NULL;
                delete tempNode;
                break;
            }
            secondLastNode = tempNode;
            tempNode = tempNode->next;
        }
    }

    /**
     * Function to reverse a singly linked list in linear time (O(n)).
     *
     * Example:
     * Original List:  1 -> 2 -> 3 -> 4 -> 5
     * After reverse:  5 -> 4 -> 3 -> 2 -> 1
     *
     * Step-by-step explanation:
     * - We use three pointers:
     *     1. tn (tempNode): Traverses the list.
     *     2. cn (currentNode): Points to the current node being processed.
     *     3. pn (prevNode): Points to the previous node (initially NULL).
     * - For each node:
     *     a. Store the current node in cn.
     *     b. Move tn to the next node.
     *     c. Reverse the link: cn->next = pn.
     *     d. Move pn to cn (advance prevNode).
     * - After the loop, set head = cn (which will be the new head).
     *
     * Visual Example:
     * Iteration 1: 1->2, pn=NULL, cn=1, tn=2
     *     1->NULL, pn=1, cn=2, tn=2
     * Iteration 2: 2->3, pn=1, cn=2, tn=3
     *     2->1, pn=2, cn=3, tn=3
     * ... and so on, until the list is fully reversed.
     */
    void reverseALinkedListLienarly()
    {
        Node *tn = head;
        Node *cn = tn;
        Node *pn = NULL;
        while (tn != NULL)
        {
            cn = tn;
            tn = tn->next;
            cn->next = pn;
            pn = cn;
        }
        head = cn;
    }

    int sizeOfLinekdList()
    {
        Node *tn = head;
        int count = 0;
        while (tn != NULL)
        {
            count++;
            tn = tn->next;
        }
        return count;
    }

    int kthLastElement(int k)
    {
        if (head == NULL)
        {
            return -1;
        }
        int size = sizeOfLinekdList();
        int indexForKthElementFromStart = size - k + 1;
        int kthElemnt = -1;
        Node *tn = head;
        while (tn != NULL)
        {
            if (indexForKthElementFromStart == 0)
            {
                break;
            }
            kthElemnt = tn->data;
            tn = tn->next;
            indexForKthElementFromStart = indexForKthElementFromStart - 1;
        }
        return kthElemnt;
    }


    /**
     * Function to find the kth last element of a singly linked list using the two-pointer technique.
     *
     * Example:
     * List: 10 -> 20 -> 30 -> 40 -> 50
     * k = 2
     * kth last element = 40 (2nd from the end)
     *
     * Detailed Explanation:
     * - We use two pointers: 'fast' and 'slow', both starting at the head.
     * - First, move the 'fast' pointer k steps ahead in the list.
     *   (So there is a gap of k nodes between 'fast' and 'slow')
     * - Then, move both 'fast' and 'slow' one step at a time until 'fast' reaches the end (NULL).
     * - At this point, 'slow' will be at the kth last node.
     *
     * Why does this work?
     * - When 'fast' is k nodes ahead and reaches the end, 'slow' is exactly k nodes from the end.
     * - This method only requires one traversal (O(n) time, O(1) space).
     *
     * Edge Cases:
     * - If k is greater than the length of the list, this function will cause a null pointer access.
     *   (You may want to add a check for robustness.)
     */
    int kthLastElementTwoPointer(Node *head, int k)
    {
        Node *fast = head;
        Node *slow = head;

        int cnt = 0;
        while (cnt < k)
        {
            fast = fast->next;
            cnt++;
        }

        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow->data;
    }

    void swapLinkedListFirstTwoNodes() {
        Node *firstNode = head;
        Node *secondNode = head->next;
        cout << endl;
        cout << "---------" << endl;
        cout << firstNode->data << " " << secondNode->data << endl;

        // Swapping Now
        Node* tempNode = secondNode;
        Node *tempNodeNext = tempNode->next;
        secondNode = firstNode;
        firstNode = tempNode;
        firstNode->next = secondNode;
        secondNode->next = tempNodeNext;
        head = firstNode;
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

    // Pushing Element at particular position in linked list
    linkedList.pushAtPost(1, -3);
    linkedList.pushAtPost(1, -1);
    linkedList.pushAtPost(20, 20);

    // Print the linked list
    linkedList.printLinkedList();

    linkedList.popFront();
    linkedList.popFront();
    linkedList.popFront();
    linkedList.popFront();
    cout << endl;
    linkedList.printLinkedList();
    cout << endl;
    linkedList.deleteTailRecursively(linkedList.head);
    cout << endl;
    cout << "LinkedList Post Deletion" << endl;
    linkedList.printLinkedList();

    cout << endl;
    linkedList.deleteTailLinearly();
    cout << endl;
    cout << "LinkedList Post Linear Deletion" << endl;
    linkedList.printLinkedList();

    cout << "Reversing a linked list now " << endl;
    linkedList.reverseALinkedListLienarly();
    linkedList.printLinkedList();
    cout << endl;

    cout << "5th element from last = " << linkedList.kthLastElement(5) << endl;

    cout << linkedList.kthLastElementTwoPointer(linkedList.head, 5) << endl;

    //Swapping
    linkedList.swapLinkedListFirstTwoNodes();
    cout << endl;
    linkedList.printLinkedList();
    cout << endl;
    return 0;
}