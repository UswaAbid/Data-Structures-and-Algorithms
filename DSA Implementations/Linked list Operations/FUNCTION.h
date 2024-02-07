
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>	
using namespace std;												
	
												
		int menu_for_linkedlist ()
		{
	    int choice;
	    cout << "\nChoose a linked list type:" << endl;
        cout << "1. Singly Linked List" << endl;
        cout << "2. Doubly Linked List" <<endl;
        cout << "3. Singly Circular Linked List" << endl;
        cout << "4. Doubly Circular Linked List" << endl;
        cout << "5. Exit" << endl;
        cout << "--------------------------------------------------------------------" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        return choice;
		 }										
												
		int menu_for_singlylinkedlist ()   
		{
	    int choice;
	    cout << "\nSingly Linked List Operations:" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Searching" << endl;
        cout << "4. Go back" << endl;
        cout << "--------------------------------------------------------------------" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
		
		 return choice;		
	    }										
												
		int menu_for_insertion_operations ()
		{
		int  insertChoice;	
		cout << "\nInsertion Options:" << endl;
        cout << "1. Insert at Start" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Any Position" << endl;
        cout << "4. Go Back" << endl;
        cout << "--------------------------------------------------------------------" << endl << endl;
        cout << "Enter your choice: ";
        cin >> insertChoice;
		
		return  insertChoice;	
		 }																				
												
		int menu_for_deletion_operations ()
		{
			int deleteChoice;
	    cout << "\nDeletion Options:" << endl;
        cout << "1. Delete at Start" << endl;
        cout << "2. Delete at End" << endl;
        cout << "3. Delete at Any Position" << endl;
        cout << "4. Go Back" << endl;
        cout << "--------------------------------------------------------------------" << endl << endl;
        cout << "Enter your choice: ";
        cin >> deleteChoice;

        return deleteChoice;
	    }											
													
		int menu_for_doublylinkedlist ()
		{
			 int choice;
		cout << "\nDoubly Linked List Operations:" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Searching" << endl;
        cout << "4. Go back" << endl;
        cout << "--------------------------------------------------------------------" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        return choice;
	  } 											
													
		int menu_for_singly_circular_linkedlist ()
		{
		int choice;	
		cout << "\nSingly Circular Linked List Operations:" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Searching" << endl;
        cout << "4. Go back" << endl;
        cout << "--------------------------------------------------------------------" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
		return choice;	
		 }
				
		int menu_for_doubly_circular_linkedlist ()
		{
			int choice;
	    cout << "\nDoubly Circular Linked List Operations:" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Searching" << endl;
        cout << "4. Go back" << endl;
        cout << "--------------------------------------------------------------------" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        return choice;
	  }																						
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////													

													
													  // SINGLY LINKED LIST
 struct Node
{
	int data;
	struct Node *next;
};
                                                 //INSERTION OF NODE IN SINGLY LINKED LIST

 void INSERT_AT_START(struct Node** head, int nodedata)
{
	struct Node *newnode1 = new Node;
	newnode1 ->data = nodedata;
	newnode1 ->next = (*head);
	(*head) = newnode1;
}

 void INSERT_AT_END(struct Node* node, int nodedata)
{
	while( node->next != NULL )
	{
		node = node->next;
	}
	
	Node* newNode1 = new Node;
	newNode1 ->data = nodedata;
	newNode1 ->next = NULL;
	node ->next = newNode1;
}

 void INSERT_AT_ANY_POSITION(struct Node* prevnode, int position, int nodedata)
{
	int loc = 1;
	
	if(prevnode == NULL)
	{
		cout << "Previous node is not given";
		return;
	}
	
	while (prevnode->next) {
		
		loc++;
		if(loc == position) {
			break;
		}
		prevnode = prevnode->next;
	}	
	struct Node *newnode1 = new Node;
	newnode1->data =  nodedata;
	newnode1->next =  prevnode->next;
	prevnode->next = newnode1;	
}

                                                //DELETION OF NODE IN SINGLY LINKED LIST

 struct Node* DEL_AT_START(struct Node* head)
{
	struct Node *ptr;
	if (head == NULL)
	{
		cout << "List is empty";
	}
	else
	    ptr = head;
	    head = ptr->next;
	    delete ptr;
	    return head;
}

 struct Node* DEL_AT_END(struct Node* head)
{
	struct Node *ptr;
	ptr = head;
	if (head == NULL)
	{
		cout << "Empty list";
	}
	else if(ptr->next == NULL)
	{
		head = NULL;
		delete ptr;
		cout << "Only node in the list deleted";
	}
	else 
	{
	   ptr = head;
	   while(ptr->next->next != NULL)
	   {
		ptr= ptr->next;
	   }
	   delete ptr->next;
	   ptr->next = NULL;	
	}
		  return head; 
}

 void DEL_AT_ANY_POSITION(struct Node* node, int nodedata)
 {   
    int i = 0; 
    while(node ->next != NULL)
    {
	if((node->next)-> data == nodedata)
		{
	i++;
	break;
	}
	else
	node = node->next;
	}

    if (i == 0)
    cout << "Data not found"<< endl;
    else
	node->next = node->next->next; 
 }

                                               //DISPLAYS SINGLY LINKED LIST

 void displaylist(struct Node *node)
{
   while(node != NULL)
   {
	 cout << node->data << "-->";
	 node = node->next;
   }	
   cout << "NULL" << endl;
}

                                             //SEARCHING IN SINGLE LINKED LIST

bool search (Node* head, int target)
 {
    Node* current = head;
    while (current != NULL)
	 {
        if (current->data == target)
		 {
            return true;  // Node found
        }
        current = current->next;
    }
    return false;  // Node not found
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                  // DOUBLY LINKED LIST

	  struct Dnode{
	
	int data;
	struct Dnode *next;
	struct Dnode *prev;
	
}; 
                                         //INSERTION OF NODE IN DOUBLY LINKED LIST

    void INSERT_AT_START_DLL(struct Dnode** head, int nodedata)
    {
	struct Dnode *newnode = new Dnode;
    if(*head == NULL)
    {
	newnode->data = nodedata;
	newnode->next = NULL;
	newnode->prev = NULL;
	(*head) = newnode; 	
	}
	else
	{
		newnode->prev = NULL;
		newnode->next = (*head);
		(*head)->prev = newnode;
		newnode->data = nodedata;
		(*head) = newnode;
		
	}
}

   void INSERT_AT_END_DLL(struct Dnode** head, int nodedata)
    {
    struct Dnode* newNode = new Dnode;
    newNode->data = nodedata;
    newNode->next = NULL;

    if (!head)
    {
        newNode->prev = NULL;
        (*head) = newNode;
    } else 
	    {
         struct Dnode* p = (*head);
         while (p->next)
	    {
            p = p->next;
        }
        newNode->prev = p;
        p->next = newNode;
    }
}

   void INSERT_AT_ANY_POSITION_DLL(struct Dnode* prevnode, int position, int nodedata)
    {
	 int loc = 1;     
    if (prevnode == NULL) 
	{
        cout << "Previous node is not given" << endl;
    }



	while (prevnode->next) {
		
		loc++;
		if(loc == position) {
			break;
		}
		prevnode = prevnode->next;
	}	

    struct Dnode* newnode = new Dnode;
    newnode->data = nodedata;
    newnode->prev = prevnode;
    newnode->next = prevnode->next;

    if (prevnode->next != NULL)
    {
        prevnode->next->prev = newnode;
    }

    prevnode->next = newnode;
}

                                            //DELETION OF NODE IN DOUBLY LINKED LIST

   struct Dnode* DEL_AT_START_DLL(struct Dnode* head)
	  {
    if (head == NULL) 
	{
       cout << "List is empty" << endl;
    }

   struct Dnode* ptr = head;
    head = ptr->next;

    if (head != NULL) 
	{
        head->prev = NULL;
    }

    delete ptr;
    return head;
}

   struct Dnode* DEL_AT_END_DLL(struct Dnode** head) 
   {
    if (head == NULL) 
	{
      cout << "List is empty. Nothing to delete." << endl;
    }

   struct Dnode* lastnode = *head;

    while (lastnode->next != NULL) 
	{
        lastnode = lastnode->next;
    }

    // If there's only one node in the list
    if (*head == lastnode) 
	{
        delete lastnode;
        head = NULL;
    } else 
	{
        lastnode->prev->next = NULL;
        delete lastnode;
    }
    return *head;
}
	
   void DEL_AT_ANY_POSITION_DLL(struct Dnode*& head, int position)
	 {
        if (head == NULL || position <= 0)
		 {
            // List is empty or an invalid position is given
           cout << "List is empty. Nothing to delete." << endl;
        }

    // Special case: Delete the head node
    if (position == 1) {
       struct Dnode* ptr = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete ptr;
        return;
    }

     struct Dnode* ptr = head;
    int currentPosition = 1;

    // Traverse to the specified position
    while (ptr != NULL && currentPosition < position) {
       ptr = ptr->next;
        currentPosition++;
    }

    if (ptr == NULL) {

        cout <<"Position is beyond the end of the list";
    }

    // Update the pointers to skip the node to be deleted
   ptr->prev->next = ptr->next;
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }

    delete ptr; // Delete the node at the specified position
}


                                           //DISPLAYS DOUBLY LINKED LIST

	 void displaylist_DLL(struct Dnode *node)
{
	
	if (node == NULL)
	{
	cout <<"Empty list" <<endl;
	}
   while(node != NULL)
   {
	 cout << node->data << "-->";
	 node = node->next;
   }	
}


	                                        //SEARCHING IN DOUBLY LINKED LIST
	
	
	 int search_DLL( Dnode* head, int target) 
	 {
    Dnode* current = head;
    int position = 1;

    while (current != NULL)
	 {
		
        if (current->data == target)
		 {
            cout << "Element " << target << " found at position " << position << "." << endl;
            return position;
        }
        current = current->next;
        position++;
    }

    cout << "Element " << target << " not found." << endl;
    return 0; 
}

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                                                 

                                              // SINGLY CIRCULAR LINKED LIST    

     struct node
{
	int data;
	struct node *next;
	node(int val) : data(val), next(NULL) {}
};

                                    // INSERTION OF NODE IN SINGLY CIRCULAR LINKED LIST

  struct node* insertAtStart(node* head, int value)
   {
        node* newNode = new node(value);

    if (head == NULL)
	 {
        newNode->next = newNode; // Create a self-loop for the first node
    } 
	else 
	{
        node* tail = head;
        while (tail->next != head)
		 {
            tail = tail->next; // Find the last node
        }
        newNode->next = head; // New node points to the head
        tail->next = newNode; // Last node points to the new node
    }

    return newNode; // Return the new head
}

  struct node* insertAtEnd(node* head, int value)
   {
    struct node* newNode = new node(value);
    if (head == NULL)
	 {
        newNode->next = newNode;     // Create a self-loop for the first node
        return newNode;              // Return the new head
    }
	 else 
	 {
        struct node* p = head;
        while (p->next != head)
		 {
            p = p->next;          // Find the last node
        }
        newNode->next = head;    // New node points to the head
        p->next = newNode;      // Last node points to the new node
        return head;           // Head remains the same
    }
}

  struct node* insertAtPosition(node* head, int value, int position)
   {
    if (position <= 0)
	 {
       cout << "Invalid position. Position should be a positive integer." << endl;
        return head;
    }

    if (position == 1)
	 {
        return insertAtStart(head, value);       // Insert at the beginning
     }

    struct node* newNode = new node(value);
    struct node* p = head;
    int count = 1;

    while (count < position-1  &&  p->next != head)
	 {
        p = p->next;
        count++;
    }

    if (count != position-1) 
	{
        cout << "Position out of range. Insertion not possible." << endl;
        delete newNode;
        return head;
    }

    newNode->next = p->next;
    p->next = newNode;

    return head;
}

                                     // DELETION OF NODE IN SINGLY CIRCULAR LINLED LIST

  struct node* deleteAtStart(node* head)
   {
    if (head == NULL) 
	{
        cout << "The list is empty. Deletion not possible." << endl;
    }

    struct node* temp = head;
    struct node* p = head;

    while (p->next != head)
    {
        p = p->next;                  // Find the last node
    }

    if (head == p)
	 {
                                    // If there's only one node in the list
        delete head;
        cout <<"only node in the list deleted ";  
    }
	 else 
	 {
        p->next = head->next;          // Update the last node's next pointer
        head = head->next;            // Move the head to the next node
        delete temp;                  // Delete the old head
        return head;
    }
} 

  struct node* deleteAtEnd(node* head)
   {
    if (head == NULL) {
        cout << "The list is empty. Deletion not possible." << endl;
    }

    struct node* temp = head;
    struct node* p = NULL;

    while (temp->next != head)
	 {
        p = temp;
        temp = temp->next;
    }

    if (p == NULL)
	 {
        delete head;
        cout <<"only node in the list deleted ";  
    } 
	else {
        p->next = head;            // Update the last node's next pointer
        delete temp;               // Delete the old last node
        return head;
    }
}

   struct node* deleteAtPosition(node* head, int position)
   {
    if (head == NULL) {
        cout << "The list is empty. Deletion not possible." << endl;
        return NULL;
    }

    if (position <= 0) {
        cout << "Invalid position. Position should be a positive integer." << endl;
        return head;
    }

    if (position == 1) {
        node* temp = head;

        if (head->next == head) {
            delete head;
            return NULL; // If there's only one node in the list
        } else {
            node* tail = head;
            while (tail->next != head) {
                tail = tail->next; // Find the last node
            }
            head = head->next; // Move the head to the next node
            tail->next = head; // Update the last node's next pointer
            delete temp; // Delete the old head
            return head;
        }
    }

    node* current = head;
    node* p = NULL;
    int count = 1;

    do {
        p = current;
        current = current->next;
        count++;
    } while (count < position && current != head);

    if (count != position) {
      cout << "Position out of range. Deletion not possible." << endl;
        return head;
    }

    p->next = current->next; // Update the previous node's next pointer
    delete current; // Delete the node at the specified position
    return head;
}

                                    // DISPLAYS SINGLY CIRCULAR LINKED LIST

   void display(node* head) 
   {
	
    if (head == NULL) 
	{
      cout << "The list is empty." << endl;
      return;
    }

    struct node* current = head;
    do {
          cout << current->data << "->";
          current = current->next;

    } while (current != head);
    cout << endl;
}

                                   //SEARCHING IN SINGLY CIRCULAR LINKED LIST

   bool searchNode (node* head, int target)
    {
    if (head == NULL) {
        return false;        // List is empty, target not found
    }

   struct node* current = head;
    do {
        if (current->data == target)
		{
            return true;                  // Node found
        }
        current = current->next;

    } while (current != head);

    return false;                        // Node not found
}                              

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                              // DOUBLY CIRCULAR LINKED LIST  
      struct dnode
	   {
     int data;
     struct dnode* next;
     struct dnode* prev;
     dnode(int val) : data(val), next(NULL), prev(NULL) {}
};

                                         //INSERTION OF NODE IN DOUBLY CIRCULAR LINKED LIST

    struct dnode* insertAtStart_DCLL(dnode* head, int value) 
	{
        struct dnode* newNode = new dnode(value);

     if (head == NULL)
		  {
        newNode->next = newNode;
        newNode->prev = newNode;        // Create a self-loop for the first node
          } 
	else
	  {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
     }

    return newNode;                     // Return the new head
}	
	
	struct dnode* insertAtEnd_DCLL(dnode* head, int value)
	 {
         struct dnode* newNode = new dnode(value);

         if (head == NULL) {
         newNode->next = newNode;
         newNode->prev = newNode;           // Create a self-loop for the first node
         return newNode;                   // Return the new head
    }
	 else 
	 {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        return head;                         // Head remains the same
    }
}
	
	struct dnode* insertAtPosition_DCLL(dnode* head, int value, int position)
	 {
        if (position <= 0) {
        cout << "Invalid position. Position should be a positive integer." <<endl;
        return head;
    }

        struct dnode* newNode = new dnode(value);

        if (head == NULL || position == 1) 
	{
        return insertAtStart_DCLL(head, value);     // Insert at the beginning
        }

     dnode* current = head;
     int count = 1;

    while (count < position - 1) {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;

    return head;
}
	
	                                    //DELETION OF NODE IN DOUBLY CIRCULAR LINKED LIST

    struct dnode* deleteAtStart_DCLL(dnode* head) 
	{
       if (head == NULL)
	 {
        cout << "The list is empty. Deletion not possible." << endl;
        return NULL;
    }

       dnode* temp = head;

       if (head->next == head)
	    {
        delete head;
        return NULL;                   // If there's only one node in the list
        } 
	   else
	 {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;            // Move the head to the next node
        delete temp;                  // Delete the old head
        return head;
    }
}

    struct dnode* deleteAtEnd_DCLL(dnode* head)
	 {
       if (head == NULL) 
	   {
        cout << "The list is empty. Deletion not possible." << endl;
        return NULL;
    }
        struct dnode* temp = head->prev;

        if (head->next == head) 
	   {
        delete head;
        return NULL;            // If there's only one node in the list
       } 
	     else
	   {
        temp->prev->next = head;
        head->prev = temp->prev;
        delete temp;                 // Delete the old last node
        return head;
       }
}

    struct dnode* deleteAtPosition_DCLL(dnode* head, int position) 
	{
       if (head == NULL)
	    {
        cout << "The list is empty. Deletion not possible." << endl;
        return NULL;
       }

    if (position <= 0) 
	  {
        cout << "Invalid position. Position should be a positive integer." << endl;
        return head;
      }

    if (position == 1)
	 {
        return deleteAtStart_DCLL(head);      // Delete at the beginning
     }

        struct dnode* current = head;
        int count = 1;

    do {
        current = current->next;
        count++;

    } while (count < position && current != head);

    if (count != position) 
	{
        cout << "Position out of range. Deletion not possible." << endl;
        return head;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;                         // Delete the node at the specified position
    return head;
}
	
	                                   //DISPLAYS DOUBLY CIRCULAR LINKED LIST
	
   void display_DCLL(struct dnode* head) 
	{
        if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    dnode* current = head;
    do {
        cout << current->data << "->";
        current = current->next;

    } while (current != head);
      cout << endl;
}
	
	                                   //SEARCHING IN DOUBLY CIRCULAR LINKED LIST
	
   bool searchNode_DCLL(dnode* head, int target) 
   {
    if (head == NULL) 
	{
        return false; // List is empty, target not found
    }

       dnode* current = head;
      do
	   {
        if (current->data == target) 
		  {
            return true;                 // Node found
          }
        current = current->next;

    } while (current != head);

    return false;                      // Node not found
}                                
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif

