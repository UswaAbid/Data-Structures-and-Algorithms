

// The time compexity of binary search algorithm in arrays is O(n)
#include <iostream>
using namespace std;

int linearsearch(int arr[], int n , int key)
{
	for(int i =0; i<n ; i++)
	{
	   if	(arr[i]== key)
	   return i;
	}
	
return -1;	
}

int main()
{
	
	int n ;
	cout<<"enter size of array"<<endl;
	cin>> n;
	
    int arr[n];
    	cout<<"enter elements of array"<<endl;
	for (int i =0; i<n ; i++)
	{
	
		cin>>arr[i];
	}
	
	int key;
	cout<<"enter the element to search"<<endl;
	cin>>key;
	
	cout<<linearsearch(arr,n,key);
	return 0;
}
