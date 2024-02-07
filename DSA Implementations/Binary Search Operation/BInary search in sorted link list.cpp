#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};
                                             
                                                 
 void INSERT_AT_START(struct Node** head, int nodedata)
{
	struct Node *newnode1 = new Node;
	newnode1 ->data = nodedata;
	newnode1 ->next = (*head);
	(*head) = newnode1;
}


bool binarySearch(Node* head, int item, int& loc) {
    Node* current = head;
    int index = 0;

    while (current) {
        if (current->data == item) {
            loc = index;
            return true;       // Element found
        } else if (current->data > item) {
            return false;      // Element not found (list is sorted)
        }

        current = current->next;
        index++;
    }

    loc = -1; // Element not found
    return false;
}

int main() {
    struct Node* head = NULL;
   
INSERT_AT_START(&head,25);
INSERT_AT_START(&head,30);
INSERT_AT_START(&head,40);

    int loc; // Initialize loc

    int item;
    cout << "Enter the number to search for: ";
    cin >> item;

    if (binarySearch(head, item, loc)) {
        cout << "Element found at index " << loc << endl;
    } else {
        cout << "Element not found in the linked list." << endl;
    }


    return 0;
}

