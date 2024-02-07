  #include <iostream>
  using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int value, int prio) : data(value), priority(prio), next(NULL) {}
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() : front(NULL) {}

    // Function to insert an element with priority into the priority queue
    
    void insert(int data, int priority)
	 {
        Node* newNode = new Node(data, priority);

        if (!front || priority < front->priority) {
            newNode->next = front;
            front = newNode;
        } 
		else 
		{
            Node* current = front;

            while (current->next && priority >= current->next->priority)
			{
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }


    // Function to display the elements in the priority queue
    
    void display() {
        Node* current = front;

      cout << " \n Priority Queue: ";
        while (current) 
		{
            cout << "(" << current->data << ", " << current->priority << ")" <<"->";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(10, 2);
    pq.insert(20, 1);
    pq.insert(30, 3);
    pq.insert(40, 2);

    pq.display();             // Output: Priority Queue: (20, 1) (10, 2) (40, 2) (30, 3)
    return 0;
}

