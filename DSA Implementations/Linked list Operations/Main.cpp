#include <iostream>
#include<stdlib.h>
#include<time.h>
#include "FUNCTION.h"

using namespace std;


int main() {
	
	
	 cout << " \n            _________________:WELCOME TO LINKED LIST OPERATIONS:_________________" <<endl<<endl;


    while (true) {
	MainMenu:
	int choice = menu_for_linkedlist ();

        switch (choice) {
        case 1:                                      // Singly Linked List
	{
		    struct Node* head = NULL;
		    int choice, data, position;
		
		    INSERT_AT_START(&head,25);
		    INSERT_AT_START(&head,30);
		    INSERT_AT_START(&head,40);
		    INSERT_AT_END(head,60);

	        while (true) {
		lastMenu:
		displaylist(head);
	        choice = menu_for_singlylinkedlist ();

	system("cls");
	switch (choice) {
				case 1:                              // Insertion
			        while (true) {                          // Loop to stay in the insertion operations menu
			        int insertChoice;
			        displaylist(head);
			
			        insertChoice = menu_for_insertion_operations ();
			
			        switch (insertChoice) {
			            case 1:
			                cout << "Enter data to insert at the start: ";
			                cin >> data;
			                INSERT_AT_START(&head, data);
			                cout << "Node inserted at the beginning." << endl;
			               // displaylist(head);
			                break;
			
			            case 2:
			                cout << "Enter data to insert at the end: ";
			                cin >> data;
			                INSERT_AT_END(head, data);
			                cout << "Node inserted at the end." << endl;
			               // displaylist(head);
			                break;
			
			            case 3:
			                cout << "Enter data to insert: ";
			                cin >> data;
			                cout << "Enter position to insert at: ";
			                cin >> position;
			                INSERT_AT_ANY_POSITION(head,position, data);
			                //displaylist(head);
			                break;
			
			            case 4:
			                    cout <<"exiting insertion operations"<< endl;
			                    system("cls");
			                    goto lastMenu;
			                    break;
			
			            default:
			                cout << "Invalid choice!" << endl;
			        }
			
			    }
			    cout << "Singly link list after insertion operation." << endl;
			    displaylist(head);
			    break;

		case 2:                   // Deletion
			while (true) {            // Loop to stay in the deletion operations menu
				        int deleteChoice;
				        displaylist(head);
				
				       deleteChoice = menu_for_deletion_operations ();
				
				        switch (deleteChoice) {
				            case 1:
				                cout << "Node deleted from the beginning." << endl;
				                head = DEL_AT_START(head);
				                //displaylist(head);
				                break;
				
				            case 2:
				                cout << "Node deleted from the end." << endl;
				                head = DEL_AT_END(head);
				               // displaylist(head);
				                break;
				
				            case 3:
				                cout << "Enter data to delete: ";
				                cin >> data;
				                DEL_AT_ANY_POSITION(head, data);
				                //  displaylist(head);
				                break;
				
				            case 4:
				                 cout <<"exiting deletion operations"<< endl;
				                 system("cls");
				                    goto lastMenu;
				                    break;
				
				            default:
				                cout << "Invalid choice!" << endl;
				        }
				
				    }
		            cout << "Singly link list after deletion operation." << endl;
		            displaylist(head);
		            break;
				
		
	case 3:
		displaylist(head);             //searching
	
	                int target;
	                cout << "Enter a number to search for in the linked list: ";
	                cin >> target;
	
	            	if (search(head, target))
				   {
	                 cout << target << " found in the linked list." << endl;
	               } 
					else
				    {
	                  cout << target << " not found in the linked list." << endl;
	                }
	
	                break;
	
	            case 4:
	                cout << "Exiting Singly linked list Operations." << endl;
	                system("cls");
	                    goto MainMenu;
	                    break;

	            default:
	                cout << "Invalid choice!" << endl;
	                break;
	}
		}
	} 

	    case 2:                                     // Doubly Linked list
	    {         
		    struct Dnode* head = NULL;
		    int choice, data, position;
		
		    INSERT_AT_START_DLL(&head,12);
		    INSERT_AT_START_DLL(&head,18);
		    INSERT_AT_START_DLL(&head,21);
		    INSERT_AT_END_DLL(&head, 5);
		
		    while (true) {
			lastMenu1:
			displaylist_DLL(head);
			
			choice = menu_for_doublylinkedlist ();
			system("cls");
		        switch (choice) {
			
		        case 1:                     // Insertion
		        while (true) {              // Loop to stay in the insertion operations menu
		        int insertChoice;
		        displaylist_DLL(head);
		
			insertChoice = menu_for_insertion_operations ();
		
		        switch (insertChoice) {
		            case 1:
		                cout << "Enter data to insert at the start: ";
		                cin >> data;
		                cout << "Node inserted at the beginning." << endl;
		                INSERT_AT_START_DLL(&head,data);
		                 //displaylist_DLL(head);
		                break;
		
		            case 2:
		                cout << "Enter data to insert at the end: ";
		                cin >> data;
		                cout << "Node inserted at the end." << endl;
		                INSERT_AT_END_DLL(&head, data);
		                //displaylist_DLL(head);
		                break;
		
		            case 3:
		                 cout << "Enter data to insert: ";
		                cin >> data;
		                cout << "Enter position to insert at: ";
		                cin >> position;
		                INSERT_AT_ANY_POSITION_DLL (head, position, data);
		                 //displaylist_DLL(head);
		                break;
		
		            case 4:
		                    cout <<"exiting insertion operations"<< endl;
		                    system("cls");
		                    goto lastMenu1;
		                    break;
		
		            default:
			              cout << "Invalid choice!" << endl;
		        }
		
			    }
			    cout << "Doubly link list after insertion operation." << endl;
			    displaylist_DLL(head);
			    break;

			    case 2:                     // Deletion
			    while (true) {             // Loop to stay in the deletion operations menu
			    int deleteChoice;
			    displaylist_DLL(head);
			
				deleteChoice = menu_for_deletion_operations ();
			
			        switch (deleteChoice) {
			            case 1:
			                cout << "Node deleted from the beginning." << endl;
			                head = DEL_AT_START_DLL(head);
			                //displaylist_DLL(head);
			                break;
			
			            case 2:
			                cout << "Node deleted from the end." << endl;
			                head = DEL_AT_END_DLL(&head);
			                 //displaylist_DLL(head);
			                break;
			
			            case 3:
			
			                 cout << "\nEnter the position to delete: ";
			                 cin >> position;
			                DEL_AT_ANY_POSITION_DLL (head, position);
				            //displaylist_DLL(head);
			                break;
			
			            case 4:
			
			                 cout <<"exiting deletion operations"<< endl;
			                 system("cls");
			                 goto lastMenu1;
			                 break;
			
			            default:
			                cout << "Invalid choice!" << endl;
			        }
			                        
			
			    }
                cout << "Doubly link list after deletion operation." << endl;
                displaylist_DLL(head);
                break;
			
	            case 3:
		          displaylist_DLL(head);                   //searching
		
		            int target;
	                cout << "\nEnter the element to search for: ";
	                cin >> target;
	                search_DLL(head, target);
	                break;
	
	            case 4:
	                 cout << "Exiting Doubly linked list Operations." << endl;
	                system("cls");
	                goto MainMenu;
	                break;
	
	            default:
	                cout << "Invalid choice!" << endl;
	                break;
	        }
		}	

		} 

		case 3:                                     // Singly Circular Linked Lis
        {
		
		    struct node* head = NULL;
		    int choice, data, position;
		
		    head = insertAtStart(head, 39);
		    head = insertAtStart(head, 26);
		    head = insertAtStart(head, 11);
		
		
		    while (true) {
			lastMenu2:
			display(head);
			
		        choice = menu_for_singly_circular_linkedlist ();
		
		        system("cls");
		        switch (choice) {
		
		        case 1:                         // Insertion
			        while (true) {                  // Loop to stay in the insertion operations menu
			        int insertChoice;
			        display(head);
			
			        insertChoice = menu_for_insertion_operations ();
			
			        switch (insertChoice) {
			            case 1:
			                cout << "Enter data to insert at the start: ";
			                cin >> data;
			                cout << "Node inserted at the beginning." << endl;
			                head=  insertAtStart(head, data);
			                //display(head);
			                break;
			
			            case 2:
			                cout << "Enter data to insert at the end: ";
			                cin >> data;
			                cout << "Node inserted at the end." << endl;
			                head =insertAtEnd(head, data);
			                //display(head);
			                break;
			
			            case 3:
			                cout << "Enter data to insert: ";
			                cin >> data;
			                cout << "Enter position to insert at: ";
			                cin >> position;
			                head = insertAtPosition(head,data, position);
			                //display(head);
			                break;
			
			            case 4:
			                    cout <<"exiting insertion operations"<< endl;
			                    system("cls");
			                    goto lastMenu2;
			                    break;
			
			            default:
			                cout << "Invalid choice!" << endl;
			        }
			
			    }
			    cout << "Singly Circular link list after insertion operations." << endl;
			    display(head);
			    break;
			
			case 2:                        // Deletion
		        while (true) {            // Loop to stay in the deletion operations menu
		        int deleteChoice;
		        display(head);
		
		        deleteChoice = menu_for_deletion_operations ();
		
		        switch (deleteChoice) {
		            case 1:
		                cout << "Node deleted from the beginning." << endl;
		                head = deleteAtStart(head);
		                //display(head);
		                break;
		
		            case 2:
		                cout << "Node deleted from the end." << endl;
		                head = deleteAtEnd(head);
		                //display(head);
		                break;
		
		            case 3:
		               int position;
		                cout << "Enter the position to delete: ";
		                cin >> position;
		                head = deleteAtPosition(head, position);
		                //cout << " Singly Circular Linked List after deletion at position " << position << ": ";
		                //display(head);
		                break;
		
		            case 4:
		                 cout <<"exiting deletion operations"<< endl;
		                 system("cls");
		                 goto lastMenu2;
		                 break;
		
		            default:
		                cout << "Invalid choice!" << endl;
	             	}
	         }
                cout << "Singly Circular link list after deletion operation." << endl;
                display(head);
                break;
	
	            case 3:
	            	display(head);
	
	                int target;
	                cout << "Enter a data to search for in the list: ";
	                cin >> target;
	
	                if (searchNode(head, target)) 
		                {
	                          cout << target << " found in the linked list." << endl;
	                    }
						 else 
						{
	                          cout << target << " not found in the linked list." << endl;
	                    }
	
	                break;
	
	            case 4:
	                cout << "Exiting Singly Circular linked list Operations." << endl;
	                system("cls");
	                goto MainMenu;
	                break;
	
	            default:
	                cout << "Invalid choice!" << endl;
	                break;
		        }  
		    }
		
		}
	

        case 4:                            // Doubly Circular Linked List
		{
		    struct dnode* head = NULL;
		    int choice, data, position;
		
		    // Insert elements at the start
		    head = insertAtStart_DCLL(head, 3);
		    head = insertAtStart_DCLL(head, 5);
		    head = insertAtStart_DCLL(head, 9);
		
		    while (true) {
			lastMenu3:
			display_DCLL(head);
			
			choice = menu_for_doubly_circular_linkedlist ();
		
		        system("cls");
		        switch (choice) {
		
		        case 1:                     // Insertion
			        while (true) {              // Loop to stay in the insertion operations menu
			        int insertChoice;
			        display_DCLL(head);
			
			        insertChoice = menu_for_insertion_operations ();
			
			        switch (insertChoice) {
			            case 1:
			                cout << "Enter data to insert at the start: ";
			                cin >> data;
			                cout << "Node inserted at the beginning." << endl;
			                head = insertAtStart_DCLL(head, data);
			                // display_DCLL(head);
			                break;
			
			            case 2:
			                cout << "Enter data to insert at the end: ";
			                cin >> data;
			                cout << "Node inserted at the end." << endl;
			                head = insertAtEnd_DCLL(head, data);
			                //display_DCLL(head);
			                break;
			
			            case 3:
			                 cout << "Enter data to insert: ";
			                cin >> data;
			                cout << "Enter position to insert at: ";
			                cin >> position;
			                 head = insertAtPosition_DCLL (head, data , position);
			                // display_DCLL(head);
			                break;
			
			            case 4:
			                    cout <<"exiting insertion operations"<< endl;
			                    system("cls");
			                    goto lastMenu3;
			                    break;
			
			            default:
			                cout << "Invalid choice!" << endl;
			        }
			
			    }
			    cout << "Doubly Circular link list after insertion operation." << endl;
			    display_DCLL(head);
			    break;
		
		    case 2:                       // Deletion
			    while (true) {               // Loop to stay in the deletion operations menu
			        int deleteChoice;
			        display_DCLL(head);
			        deleteChoice = menu_for_deletion_operations ();
			
			        switch (deleteChoice) {
			            case 1:
			                cout << "Node deleted from the beginning." << endl;
			                head = deleteAtStart_DCLL(head);
			                //display_DCLL(head);
			                break;
			
			            case 2:
			                cout << "Node deleted from the end." << endl;
			                head = deleteAtEnd_DCLL(head);
			                 //display_DCLL(head);
			                break;
			
			            case 3:
			
			                 cout << "\nEnter the position to delete: ";
			                 cin >> position;
			                 head = deleteAtPosition_DCLL(head, position);
			                //display_DCLL(head);
			                break;
			
			            case 4:
			                 cout <<"exiting deletion operations"<< endl;
			                 system("cls");
			                    goto lastMenu3;
			                    break;
			
			            default:
			                cout << "Invalid choice!" << endl;
			        }
			
			    }
                cout << "Doubly Circular link list after deletion operation." << endl;
                display_DCLL(head);
                break;
			
		     case 3:
		            display_DCLL(head);                       //searching
			
		             int target;
		             cout << "Enter a number to search for in the linked list: ";
		             cin >> target;
		
		              if (searchNode_DCLL(head, target))
					   {
		                 cout << target << " found in the linked list." << endl;
		              } 
		         	else
			          {
		                  cout << target << " not found in the linked list." << endl;
		              }
		                break;
		
		      case 4:
	                cout << "Exiting Doubly Circular linked list Operations." << endl;
	                system("cls");
	                goto MainMenu;
	                break;
		
		            default:
		                cout << "Invalid choice!" << endl;
		                break;
		        }
		    }
		} 
		
        case 5:     // Exit
	        cout << "Exiting the program." << endl;
	        return 0;
	        break;
		
		default:
		    cout << "Invalid choice!" << endl;
		    break;
	}
	}

    return 0;
}


