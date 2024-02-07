#include <iostream>
using namespace std;

bool binarySearch(int data[], int lb, int ub, int item, int& loc) {
    int beg = lb;
    int end = ub;
    int mid = (beg + end) / 2;

    while (beg <= end) {
        mid = (beg + end) / 2;

        if (data[mid] == item) {
            loc = mid;
            return true;                  // Element found
        } else if (item < data[mid]) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }

    loc = -1;                            // Element not found
    return false;
}
////////////////////////////////////////////////////////////////////////////////
 
int main() {
    int Data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int sz = 10;
    cout << endl;
     for(int i = 0; i < sz; i++)
	 {
       cout <<Data[i] << " " ;
     }
    int choice;

    do {
    
    int loc; // Initialize loc

    int item;
    cout << "\n\nEnter the number to search for: ";
    cin >> item;

    if (binarySearch(Data, 0, 9, item, loc)) {
        cout << "Element found at index " << loc << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

        cout << " 1| Repeat\n 0| Exit \n ";
        cin >> choice;
        
    } while (choice == 1);

    return 0;
}

