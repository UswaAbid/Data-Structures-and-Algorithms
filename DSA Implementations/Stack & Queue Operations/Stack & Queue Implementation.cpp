 
  
 #include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Define a class for the stack using an array
class ArrayStack {
private:
    int* stack;
    int top;
    int capacity;

public:
    ArrayStack(int size)
    {
        capacity = size;
        stack = new int[size];
        top = -1;
    }

    void push(int item)
    {
        if (top == capacity - 1)
        {
            cout << "Stack is full. Cannot push." << endl;
        }
        else
        {
            stack[++top] = item;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1;
        }
        else
        {
            return stack[top--];
        }
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    int topElement()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        else
        {
            return stack[top];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack Elements: ";
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

// Define a class for the stack using a linked list
class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack()
    {
        top = NULL;
    }

    void push(int item)
    {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = NULL;

        if (top == NULL)
        {
            top = newNode;
        }
        else
        {
            Node* current = top;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
        }
        else
        {
            if (top->next == NULL)
            {
                delete top;
                top = NULL;
            }
            else
            {
                Node* current = top;
                while (current->next->next != NULL)
                {
                    current = current->next;
                }
                delete current->next;
                current->next = NULL;
            }
        }
    }

    bool isFull() {
        return false;
    }

    bool isEmpty() {
        return top == NULL;
    }

    int topElement()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        else
        {
            Node* current = top;
            while (current->next != NULL)
            {
                current = current->next;
            }
            return current->data;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack Elements: ";
            Node* current = top;
            while (current != NULL) {
                cout << current->data << "->";
                current = current->next;
            }
            cout << endl;
        }
    }
};

// Define a class for the queue using an array
class ArrayQueue {
private:
    int* queue;
    int front;
    int rear;
    int capacity;

public:
    ArrayQueue(int size) {
        capacity = size;
        queue = new int[size];
        front = rear = -1;
    }

    bool isFull() {
        return (rear == capacity - 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void qinsert(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert." << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            queue[++rear] = item;
        }
    }

    void qdelete() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot delete." << endl;
        } else {
            int item = queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue Elements: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

// Define a class for the queue using a linked list
class LinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedListQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void qinsert(int item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void qdelete() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot delete." << endl;
        } else {
            int item = front->data;
            Node* temp = front;
            if (front == rear) {
                front = rear = NULL;
            } else {
                front = front->next;
            }
            delete temp;
        }
    }

    void displaylist() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue Elements: ";
            Node* current = front;
            while (current != NULL) {
                cout << current->data << "->";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int choice;

    ArrayQueue arrayQueue(20);
    LinkedListQueue linkedListQueue;

    ArrayStack arrayStack(20);
    LinkedListStack linkedListStack;

    do {
        MainMenu:
        cout << "\n_________________: WELCOME TO STACK & QUEUE OPERATIONS :_________________" << endl << endl;
        cout << "Main Menu:" << endl;
        cout << "1. Stack" << endl;
        cout << "2. Queue" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1: {
                StackMenu:
                cout << "\nStack Menu:" << endl;
                cout << "1. Using Array" << endl;
                cout << "2. Using Linked List" << endl;
                cout << "3. Go back" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                system("cls");

                switch (choice) {
                    case 1: {
                        int arr[] = {3, 1, 9, 56, 43, 78, 4, 33};
                        int sz = 8;

                        // Push elements from arr into the stack
                        for (int i = 0; i < sz; i++) {
                            arrayStack.push(arr[i]);
                        }
                        arrayStack.display();
                        int subChoice;
                        do {
                            cout << "\nArray Stack Menu:" << endl;
                            cout << "1. Push" << endl;
                            cout << "2. Pop" << endl;
                            cout << "3. Is Full" << endl;
                            cout << "4. Is Empty" << endl;
                            cout << "5. Top" << endl;
                            cout << "6. Go back" << endl;
                            cout << "Enter your choice: ";
                            cin >> subChoice;

                            switch (subChoice) {
                                case 1: {
                                    int item;
                                    cout << "Enter the item to push: ";
                                    cin >> item;
                                    arrayStack.push(item);
                                    arrayStack.display();
                                    break;
                                }
                                case 2: {
                                    arrayStack.pop();
                                    arrayStack.display();
                                    break;
                                }
                                case 3: {
                                    if (arrayStack.isFull()) {
                                        cout << "Stack is full." << endl;
                                    } else {
                                        cout << "Stack is not full." << endl;
                                    }
                                    break;
                                }
                                case 4: {
                                    if (arrayStack.isEmpty()) {
                                        cout << "Stack is empty." << endl;
                                    } else {
                                        cout << "Stack is not empty." << endl;
                                        arrayStack.display();
                                    }
                                    break;
                                }
                                case 5: {
                                    int top = arrayStack.topElement();
                                    if (top != -1) {
                                        cout << "Top element: " << top << endl;
                                    }
                                    break;
                                }
                                case 6: {
                                    system("cls");
                                    goto StackMenu;
                                    break;
                                }
                                default: {
                                    cout << "Invalid choice. Try again." << endl;
                                    break;
                                }
                            }
                        } while (subChoice != 6);
                        break;
                    }
                    case 2: {
                        LinkedListStack stack;

                        stack.push(25);
                        stack.push(30);
                        stack.push(4);
                        stack.push(67);
                        stack.push(54);
                        stack.push(5);
                        stack.push(0);
                        stack.push(7);

                        stack.display();
                        do {
                            LinkedListStackMenu:
                            cout << "\nLinked List Stack Menu:" << endl;
                            cout << "1. Push" << endl;
                            cout << "2. Pop" << endl;
                            cout << "3. Is Full" << endl;
                            cout << "4. Is Empty" << endl;
                            cout << "5. Top" << endl;
                            cout << "6. Go back" << endl;
                            cout << "Enter your choice: ";
                            cin >> choice;

                            switch (choice) {
                                case 1: {
                                    int item;
                                    cout << "Enter the item to push: ";
                                    cin >> item;
                                    stack.push(item);
                                    stack.display();
                                    break;
                                }
                                case 2: {
                                    stack.pop();
                                    stack.display();
                                    break;
                                }
                                case 3: {
                                    cout << "Linked list-based stacks cannot be full." << endl;
                                    break;
                                }
                                case 4: {
                                    if (stack.isEmpty()) {
                                        cout << "Stack is empty." << endl;
                                    } else {
                                        cout << "Stack is not empty." << endl;
                                        stack.display();
                                    }
                                    break;
                                }
                                case 5: {
                                    int top = stack.topElement();
                                    if (top != -1) {
                                        cout << "Top element: " << top << endl;
                                    }
                                    break;
                                }
                                case 6: {
                                    system("cls");
                                    goto StackMenu;
                                    break;
                                }
                                default: {
                                    cout << "Invalid choice. Try again." << endl;
                                    break;
                                }
                            }
                        } while (choice != 6);
                        break;
                    }
                    case 3: {
                        system("cls");
                        goto MainMenu;
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Try again." << endl;
                        break;
                    }
                }
                if (choice != 3) {
                    goto StackMenu;
                }
                break;
            }
            case 2: {
                QueueMenu:
                cout << "\nQueue Menu:" << endl;
                cout << "1. Using Array" << endl;
                cout << "2. Using Linked List" << endl;
                cout << "3. Go back" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                system("cls");

                switch (choice) {
                    case 1: {
                        int arr[] = {77, 6, 9, 5, 49, 74, 4, 0};
                        int sz = 8;

                        // Push elements from arr into the queue
                        for (int i = 0; i < sz; i++) {
                            arrayQueue.qinsert(arr[i]);
                        }
                        arrayQueue.display();
                        int subChoice;
                        do {
                            cout << "\nArray Queue Menu:" << endl;
                            cout << "1. qinsert" << endl;
                            cout << "2. qdelete" << endl;
                            cout << "3. isfull" << endl;
                            cout << "4. isempty" << endl;
                            cout << "5. Go back" << endl;
                            cout << "Enter your choice: ";
                            cin >> subChoice;

                            switch (subChoice) {
                                case 1: {
                                    int item;
                                    cout << "Enter the item to insert: ";
                                    cin >> item;
                                    arrayQueue.qinsert(item);
                                    arrayQueue.display();
                                    break;
                                }
                                case 2: {
                                    arrayQueue.qdelete();
                                    arrayQueue.display();
                                    break;
                                }
                                case 3: {
                                    if (arrayQueue.isFull()) {
                                        cout << "Queue is full." << endl;
                                    } else {
                                        cout << "Queue is not full." << endl;
                                    }
                                    break;
                                }
                                case 4: {
                                    if (arrayQueue.isEmpty()) {
                                        cout << "Queue is empty." << endl;
                                    } else {
                                        cout << "Queue is not empty." << endl;
									    arrayQueue.display();
                                    }
                                    break;
                                }
                                case 5: {
                                    system("cls");
                                    goto QueueMenu;
                                    break;
                                }
                                default: {
                                    cout << "Invalid choice. Try again." << endl;
                                    break;
                                }
                            }
                        } while (subChoice != 5);
                        break;
                    }
                    case 2: {
                        LinkedListQueue queue;

                        queue.qinsert(16);
                        queue.qinsert(30);
                        queue.qinsert(4);
                        queue.qinsert(27);
                        queue.qinsert(51);
                        queue.qinsert(5);
                        queue.qinsert(48);
                        queue.qinsert(7);

                        queue.displaylist();
                        do {
                            LinkedListQueueMenu:
                            cout << "\nLinked List Queue Menu:" << endl;
                            cout << "1. qinsert" << endl;
                            cout << "2. qdelete" << endl;
                            cout << "3. isfull" << endl;
                            cout << "4. isempty" << endl;
                            cout << "5. Go back" << endl;
                            cout << "Enter your choice: ";
                            cin >> choice;

                            switch (choice) {
                                case 1: {
                                    int item;
                                    cout << "Enter the item to insert: ";
                                    cin >> item;
                                    queue.qinsert(item);
                                    queue.displaylist();
                                    break;
                                }
                                case 2: {
                                    queue.qdelete();
                                    queue.displaylist();
                                    break;
                                }
                                case 3: {
                                    cout << "Linked list-based queues cannot be full." << endl;
                                    break;
                                }
                                case 4: {
                                    if (queue.isEmpty()) {
                                        cout << "Queue is empty." << endl;
                                    } else {
                                        cout << "Queue is not empty." << endl;
                                        queue.displaylist();
                                    }
                                    break;
                                }
                                case 5: {
                                    system("cls");
                                    goto QueueMenu;
                                    break;
                                }
                                default: {
                                    cout << "Invalid choice. Try again." << endl;
                                    break;
                                }
                            }
                        } while (choice != 5);
                        break;
                    }
                    case 3: {
                        system("cls");
                        goto MainMenu;
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Try again." << endl;
                        break;
                    }
                }
                if (choice != 3) {
                    goto QueueMenu;
                }
                break;
            }
            case 3: {
                cout << "\nExiting the program. THANK YOU!" << endl;
                break;
            }
            default: {
               cout << "Invalid choice. Try again." << endl;
                break;
            }
        }
    } while (choice != 3);

    return 0;
}
