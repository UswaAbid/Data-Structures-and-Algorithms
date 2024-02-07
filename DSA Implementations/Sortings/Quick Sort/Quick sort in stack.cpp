#include <iostream>

using namespace std;

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to implement QuickSort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        if (pivot_index - 1 > low) {
            quicksort(arr, low, pivot_index - 1);
        }

        if (pivot_index + 1 < high) {
            quicksort(arr, pivot_index + 1, high);
        }
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int array[size];

    cout << "Enter elements into array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << "The Array: | ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " | ";
    }

    quicksort(array, 0, size - 1);

    cout << "\n\nArray after sorting: | ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " | ";
    }

    return 0;
}

