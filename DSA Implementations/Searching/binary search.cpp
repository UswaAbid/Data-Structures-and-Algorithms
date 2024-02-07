

// The time compexity of binary search algorithm in arrays is O(log base 2 into n)
#include <iostream>
using namespace std;

int binarysearch(int arr[], int n , int key)
{

int s=0;
int e=n;
while (s<=e)
{
	int mid=(s+e)/2;
	if(arr[mid]==key)
	{
		return mid;
	}
	else if (arr[mid]>key)
	{
		e=mid-1;
	}
	else 
	{
		s=mid+1;
	}
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
	
	cout<<binarysearch(arr,n,key);
	return 0;
}
