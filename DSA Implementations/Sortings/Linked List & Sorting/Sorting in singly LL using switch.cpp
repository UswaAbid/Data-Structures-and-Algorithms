#include <iostream>

using namespace std;

// Define a singly linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

// Selection Sort for Linked List
void selectionSort(Node*& head) {
    Node* ptr = head;
    while (ptr) {
        Node* minNode = ptr;
        Node* temp = ptr->next;

        while (temp) {
            if (temp->data < minNode->data) {
                minNode = temp;
            }
            temp = temp->next;
        }

        swap(ptr->data, minNode->data);
        ptr = ptr->next;
    }
}

// Insertion Sort for Linked List
void insertionSort(Node*& head) {
    if (!head || !head->next) return;

    Node* sorted = NULL;
    Node* current = head;

    while (current) {
        Node* next = current->next;

        if (!sorted || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* search = sorted;
            while (search->next && search->next->data < current->data) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = next;
    }

    head = sorted;
}

// Bubble Sort for Linked List
void bubbleSort(Node*& head) {
    if (!head || !head->next) return;

    bool swapped;
    Node* end = NULL;

    do {
        swapped = false;
        Node* current = head;
        Node* previous = NULL;

        while (current->next != end) {
            if (current->data > current->next->data) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }

                Node* temp = current->next->next;
                current->next->next = current;
                current->next = temp;

                previous = current->next;
                swapped = true;
            } else {
                previous = current;
                current = current->next;
            }
        }

        end = current;
    } while (swapped);
}

int main() {
    Node* head = NULL;
    int n, val;

    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtBeginning(head, val);
    }

    cout << "Original Linked List: ";
    printList(head);

    int choice;
    cout << "Choose sorting algorithm:" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            selectionSort(head);
            cout << "Linked List after Selection Sort: ";
            break;
        case 2:
            insertionSort(head);
            cout << "Linked List after Insertion Sort: ";
            break;
        case 3:
            bubbleSort(head);
            cout << "Linked List after Bubble Sort: ";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    printList(head);

    return 0;
}

