#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void display(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << endl;
}

 void insertionSort(Node*& head) {
    if (!head) return;

    Node* sorted = NULL;
    Node* current = head;

    while (current) {
        Node* next = current->next;

        if (!sorted || current->data <= sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* traverse = sorted;
            while (traverse->next && traverse->next->data < current->data) {
                traverse = traverse->next;
            }
            current->next = traverse->next;
            traverse->next = current;
        }

        current = next;
    }

    head = sorted;
}


int main() {
    Node* head = NULL;
    
    insert(head, 3);
    insert(head, 1);
    insert(head, 2);
    insert(head, 5);
    insert(head, 4);

    cout << " \n Original list: ";
    display(head);

    insertionSort(head);
    cout << " \n Sorted using Insertion Sort: ";
    display(head);

    return 0;
}
