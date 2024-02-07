 
 #include <iostream>
 using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;

    Node(int value, int prio) : data(value), priority(prio), next(NULL) {}
};


    // Function to insert an element with priority into the priority queue
    
    void insert(int data, int priority)
	 {
	    Node* front;
        Node* newNode = new Node(data, priority);

        if (!front || priority > front->priority)
		 {
            newNode->next = front;
            front = newNode;
        } 
		else
		 {
            Node* current = front;

            while (current->next && priority <= current->next->priority)
			 {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }


    // Function to display the elements in the priority queue
    
    void display() {
    	Node* front;
        Node* current = front;

        cout << "Priority Queue: ";
        while (current) {
           cout << "(" << current->data << ", " << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }


int main() {
   
   struct Node* head = NULL;
   
   insert(10, 2);
   insert(20, 1);
   insert(30, 3);
   insert(40, 2);

    display();           // Output: Priority Queue: (20, 1) (10, 2) (40, 2) (30, 3)

    return 0;
}

