#include <iostream>
using namespace std;

struct Node {
    int data;
   
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void display(Node* head) {
    Node* current = head;
    while (current) {
       cout << current->data << " ";
        current = current->next;
    }
    cout << std::endl;
}

void insertionSort(Node*& head) {
    if (!head) return;

    Node* sorted = NULL;
    Node* current = head;

    while (current) {
        Node* next = current->next;

        if (!sorted || current->data <= sorted->data) {
            current->prev = NULL;
            current->next = sorted;
            if (sorted)
                sorted->prev = current;
            sorted = current;
        } else {
            Node* traverse = sorted;
            while (traverse->next && traverse->next->data < current->data) {
                traverse = traverse->next;
            }
            current->prev = traverse;
            current->next = traverse->next;
            if (traverse->next)
                traverse->next->prev = current;
            traverse->next = current;
        }

        current = next;
    }

    head = sorted;
}

void bubbleSort(Node*& head) {
    if (!head) return;

    bool swapped;
    Node* last = NULL;
    do {
        swapped = false;
        Node* current = head;
        Node* prev = NULL;

        while (current->next != last) {
            if (current->data > current->next->data) {
                if (prev)
                    prev->next = current->next;
                else
                    head = current->next;
                current->prev = current->next;
                current->next = current->next->next;
                current->prev->next = current;
                if (current->next)
                    current->next->prev = current;
                swapped = true;
            }

            prev = current;
            current = current->next;
        }
        last = current;
    } while (swapped);
}

void selectionSort(Node*& head) {
    if (!head) return;

    Node* current = head;

    while (current) {
        Node* minNode = current;
        Node* traverse = current->next;

        while (traverse) {
            if (traverse->data < minNode->data) {
                minNode = traverse;
            }
            traverse = traverse->next;
        }

        if (minNode != current) {
            if (current->prev)
                current->prev->next = minNode;
            else
                head = minNode;
            if (minNode->prev)
                minNode->prev->next = current;
            else
                head = current;

            Node* tempPrev = current->prev;
            Node* tempNext = current->next;
            current->prev = minNode->prev;
            current->next = minNode->next;
            minNode->prev = tempPrev;
            minNode->next = tempNext;
        }

        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    
    insert(head, 3);
    insert(head, 1);
    insert(head, 2);
    insert(head, 5);
    insert(head, 4);

    cout << "Original list: ";
    display(head);

    insertionSort(head);
    cout << "Sorted using Insertion Sort: ";
    display(head);

    bubbleSort(head);
    cout << "Sorted using Bubble Sort: ";
    display(head);

    selectionSort(head);
    cout << "Sorted using Selection Sort: ";
    display(head);

    return 0;
}
