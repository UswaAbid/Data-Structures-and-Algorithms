#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

const int ARRAY_SIZE = 50;



//INSERTION OF ARRAY ELEMENTS
void INSERT_AT_START(int arr[], int &sz, int var)
 {
    if(sz >= ARRAY_SIZE)
	 {
         
        cout << "THE ARRAY HAS REACHED IT'S LIMIT, CAN'T ADD MORE ELEMENTS!" << endl;
        return;
     }

    for(int i = sz; i > 0; i--)
	 {
        arr[i] = arr[i - 1];
     }
    arr[0] = var;
    sz++;
}

void INSERT_AT_END(int arr[], int &sz, int var)
 {

       if(sz>= ARRAY_SIZE)
       {
	  
		cout<<"THE ARRAY HAS REACHED IT'S LIMIT, CAN'T ADD MORE ELEMENTS!"<<endl;
       }
	arr[sz]= var;
	sz++;
}

void INSERT_AT_ANY_POSITION(int arr[], int &sz, int var, int pos)
{
	if(sz>= ARRAY_SIZE)
	{
		cout<<"THE ARRAY HAS REACHED IT'S LIMIT, CAN'T ADD MORE ELEMENTS!"<<endl;
	}
	if(pos<0 || pos>sz)
	{
		cout<<"UNACCEPTABLE POSITION!"<<endl;
	}
	
	for(int i=sz; i>=pos ;i--)
	{
		arr[i]=arr[i-1];
	}
	
	arr[pos-1]= var;
	sz++;
}


//DELETION OF ARRAY ELEMENTS
void DEL_AT_START(int arr[], int &sz)
 {
    if(sz <= 0)
	 {
        cout << "THERE IS NO ELEMENT IN ARRAY SO DELETION IS NOT POSSIBLE!" <<endl;
        return;
     }
    
    for(int i = 0; i < sz-1; i++)
	 {
        arr[i] = arr[i + 1];
     }
    sz--;
}

void DEL_AT_END(int arr[], int &sz)
{
	if(sz<=0)
	{
		cout<<"THERE IS NO ELEMENT IN ARRAY SO DELETION IS NOT POSSIBLE!" <<endl;
		
	}
	sz--;
}

void DEL_AT_ANY_POSITION(int arr[],int &sz, int pos)
{
	if(sz<=0 || pos-1<0 )
	{
		cout<<"UNACCEPTABLE POSITION!"<<endl;
	}
	for(int i=pos-1; i<sz ;i++)
	{
		arr[i]=arr[i+1];
		
	}
	sz-=1;
}


//SORTING IN ARRAYS
void SELECTION_SORT(int arr[], int sz)
{
	cout << "Enter the total number of elements: ";
	cin >> sz;
	cout << "Enter the array elements: ";
	
	for (int i=0; i< sz; i++)
	{
		cin>> arr[i];
	}
	
		for(int i=0; i<sz-1; i++)
	{
		int min_idx = i;
		for(int j=i+1; j<sz; j++)
		{
			if(arr[j] < arr[min_idx])
			{
				min_idx=j;
			}
		}
		if(min_idx!=i)
		{
			swap(arr[i],arr[min_idx]);
			
		}
	}
	
	cout << "THE ARRAY AFTER SELECTION SORTING IS ";
	for (int i=0; i< sz; i++)
	{
		cout << arr[i] << "  ";
	}
} 

void BUBBLE_SORT(int arr[],int sz)
{
	
	cout << "Enter the total number of elements: ";
	cin >> sz;
	cout << "Enter the array elements: ";
	
	for (int i=0; i< sz; i++)
	{
		cin>> arr[i];
	}
	for(int i=0; i<sz-1; i++)
	{
		for(int j=0; j<sz-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				
			}
		}
	}
	
	cout << "THE ARRAY AFTER BUBBLE SORTING IS ";
	for (int i=0; i< sz; i++)
	{
		cout << arr[i] << "  ";
	}
}

void INSERTION_SORT(int arr[],int sz)
{
	cout << "Enter the total number of elements: ";
	cin >> sz;
	cout << "Enter the array elements: ";
	
	for (int i=0; i< sz; i++)
	{
		cin>> arr[i];
	}
	int j,key;
	for(int i=1; i<sz; i++)
	{
		 key=arr[i];
		
		for( j=i-1; j>=0 && arr[j]>key; j-- )

     {

	cout << "\nEnter the total number of elements: ";
	cin >> sz;
	cout << "Enter the array elements: ";
	
	for (int i=0; i< sz; i++)
	{
		cin>> arr[i];
	}
		{
				arr[j+1]=arr[j];
		}
	
	arr[j+1]=key;
    }               
    
    cout << "THE ARRAY AFTER INSERTION SORTING IS ";
    for (int i=0; i<sz; i++)
	{
		cout << arr[i] << "  ";
	}
}
}   


//SEARCHING OF AN ELEMENT IN ARRAY
	void Searching(int arr[], int sz)
	{
	 
	for (int i=0; i< sz; i++)
	{
		cout << arr[i] << "  ";
	}
	int var;
	cout << "\nEnter the element to search: " << endl;
	cin >> var;
	
	bool found = false;
	int index = -1;
	
	for(int i=0 ; i<sz ; i++) 
	{
		if (arr[i] == var)
		{
			found = true;
			index = i;
			break;
		    
		}
	}
	if (found)
	{
			cout << "SEARCH SUCCESSFULL :)" << endl;
			cout << var << " is found at index " << index << " at position " << index+1 << endl;
    }
    else
    {
	        cout << "ELEMENT NOT FOUND IN ARRAY!"<< endl;
            cout << "SEARCH UNSUCCESSFULL :(" ;	
    }
}


// DISPLAYS ARRAY 
void Array(const int arr[], int sz)
 {
    for(int i = 0; i < sz; i++)
	 {
        cout << arr[i] << " ";
     }
    cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() 
{
	int arr[ARRAY_SIZE]={3,1,9,56,43,78,4,33,40,5};
	int sz=10;
    
    
    cout << " \n\n            _________________:WELCOME TO ARRAY OPERATIONS:_________________" <<endl<<endl;
    cout << "ARRAY FOR INSERTION AND DELETION OPERATION IS: \n";
     for(int i = 0; i < sz; i++)
	 {
       cout << arr[i] << " " ;
     }
    
    while(true) {
        int choice;
        char i;
		
		
		cout << "\n\nWANNA CONTINUE? (Y/N)" <<endl;
		cin >> i;
		system("cls");
		if(i == 'Y')
		
		 {
        
        cout << "\nWHICH OPERATION DO YOU WANT TO PERFORM?" << endl<< endl;
        cout << "  1) Insertion Operation" << endl;
        cout << "  2) Deletion Operation" << endl;
        cout << "  3) Sorting Operation" << endl;
		cout << "  4) Searching Operation" << endl;  
        cout << "  5) Exit" << endl;
        cout << "--------------------------------------------------------------------" << endl << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin  >> choice;
        
        }
        
	else
	cout << "INVALID...!!";
		
		system("cls");
        
        if(choice == 5)
		 {
            cout << "\n\n          EXITING THE PROGRAM -THANKYOU!" << endl;
            break;
         }
        
        system("cls");
        
        switch(choice)
 {
                               //INSERTION
			case 1: 
			{
                cout << "CHOOSE AN INSERTION OPERATION:" << endl <<endl;
                cout << "  1) Insert at beginning" << endl;
                cout << "  2) Insert at end" << endl;
                cout << "  3) Insert at specific position" << endl;
                cout << "  4) Exit" << endl;
                cout << "--------------------------------------------------------------------" << endl << endl;
                cout << "ENTER YOUR CHOICE: ";
                cin  >> choice;
                
                int var, pos;
                
                switch(choice) 
				{
                    case 1:
                        cout << "Enter an element to insert: ";
                        cin  >> var;
                        INSERT_AT_START(arr, sz, var);
                        break;
                        
                    case 2:
					    cout<<"Enter an element to insert:";
					    cin >> var;
					    INSERT_AT_END(arr, sz, var);
					    break;
					    
					case 3:
					    int pos;
				      	cout<<"Enter an element to insert:";
					    cin >> var;
						cout<<"Enter the position to insert at:";
						cin >> pos;
						INSERT_AT_ANY_POSITION(arr, sz, var, pos);
						break;
						
					case 4:
						cout<<"\n\n          EXITING INSERION OPERATIONS -THANKYOU!" << endl;
						break;
						
                   
                    default:
                        cout << "___INVALID choice!___" << endl;
                        break;
                }
                cout << "\nFINAL ARRAY IS: ";
                Array(arr, sz);
                cout<<endl;
                break;
            }
                                //DELETION
			case 2:
			 {
                cout << "CHOOSE A DELETION OPERATION:" << endl <<endl;
                cout << "  1) Delete at beginning" << endl;
                cout << "  2) Delete at end" << endl;
                cout << "  3) Delete at specific position" << endl;
                cout << "  4) Exit" << endl;
                cout << "--------------------------------------------------------------------" << endl << endl;
                cout << "ENTER YOUR CHOICE: ";
                cin >> choice;
                
                int pos;
                
                switch(choice) {
                    case 1:
                        DEL_AT_START(arr, sz);
                        cout<<endl;
                        break;
                        
                    case 2:
				      	DEL_AT_END(arr,sz);
				     	break;
				     	
					case 3:
					    int pos;
					    cout<<"Enter the position to delete an element:";
					    cin >>pos;
						DEL_AT_ANY_POSITION(arr,sz,pos);
						break;
						
					case 4:
						cout<<"\n\n          EXITING DELETION OPERATIONS -THANKYOU!" << endl;
						break;
						
                    default:
                        cout << "___INVALID Choice!___" << endl;
                        break;
                }
                  cout<<endl;
                  cout << "\nFINAL ARRAY IS: ";
                  Array(arr, sz);
                  cout<<endl;
                  break;
            }
                                     //SORTING
			case 3:
				
    {
              cout << "CHOOSE A SORTING OPERATION:" << endl <<endl;
              cout << "  1) Selection Sorting" << endl;
              cout << "  2) Bubble Sorting" << endl;
              cout << "  3) Insertion Sorting" << endl;
              cout << "  4) Exit" << endl;
              cout << "--------------------------------------------------------------------" << endl << endl;
              cout << "ENTER YOUR CHOICE: ";
              cin  >> choice;

        int array_copy [ARRAY_SIZE];
        copy(arr, arr+sz, array_copy);
        switch (choice) 
		{
            case 1:
                SELECTION_SORT(array_copy, sz);
                break;
                
            case 2:
                BUBBLE_SORT(array_copy, sz);
                break;
                
            case 3:
                INSERTION_SORT(array_copy, sz);
                break;
                
           	case 4:
				cout<< "\n\n          EXITING SORTING OPERATIONS -THANKYOU!" << endl;
				break;
                
            default:
                cout << "___INVALID choice!___" << endl;
			  
		 }
                break;
                cout << "\nFINAL ARRAY IS: ";
                Array(array_copy, sz);

}

                                   //SEARCHING
    case 4:
    	
    	cout << "\nSEARCHING:" << endl;
		Searching(arr,sz);
		break;    
            	
     default:
        cout << "___INVALID choice!___" << endl;
        break;
        }
        
    }
    
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

