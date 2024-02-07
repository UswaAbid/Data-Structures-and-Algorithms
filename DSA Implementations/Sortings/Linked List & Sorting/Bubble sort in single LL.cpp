#include <iostream>

// Define a node structure for the singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to perform Bubble Sort on a singly linked list
void bubbleSort(Node* &head) {
    if (!head) return; // Empty list

    bool swapped;
    Node* temp;
    Node* end = NULL;

    do {
        swapped = false;
        temp = head;

        while (temp->next != end) {
            if (temp->data > temp->next->data) {
                // Swap data using std::swap
                std::swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
        end = temp;
    } while (swapped);
}

// Function to insert a new node at the end of the linked list
void insert(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = NULL;
    int sz, num;

    std::cout << "Enter the total number of elements: ";
    std::cin >> sz;

    std::cout << "Enter the linked list elements: ";
    for (int i = 0; i < sz; i++) {

           std::cin >> num;
        insert(head, num);
    }
    
    std::cout << "Linked List before Bubble Sort: ";
    display(head);

    bubbleSort(head);

    std::cout << "Linked List after Bubble Sort: ";
    display(head);

    return 0;
}

