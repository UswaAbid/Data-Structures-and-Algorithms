#include <iostream>

using namespace std;

// Function to heapify a subtree rooted at index i in the array
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compare with left child
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Compare with right child
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and recursively heapify the affected subtree
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to insert a new element into the heap
void insert(int arr[], int& n, int key) {
    n++;
    int i = n - 1;
    arr[i] = key;

    // Fix the max heap property if it is violated
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the root (maximum element) from the heap
void deleteRoot(int arr[], int& n) {
    if (n <= 0) {
        cout << "\n Heap is empty. Cannot delete." << endl;
        return;
    }

    // Replace the root with the last element
    int root = arr[0];
    arr[0] = arr[n - 1];
    n--;

    // Heapify the root to maintain the max heap property
    heapify(arr, n, 0);

    cout << "\n Deleted element: " << root << endl;
}

// Function to print the elements of the heap
void printHeap(int arr[], int n) {
    cout << "\n Heap: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int MAX_SIZE = 100;
    int heap[MAX_SIZE];
    int heapSize = 0;

    // Insert elements into the heap
    insert(heap, heapSize, 12);
    insert(heap, heapSize, 7);
    insert(heap, heapSize, 6);
    insert(heap, heapSize, 10);
    insert(heap, heapSize, 8);

    printHeap(heap, heapSize);

    // Delete the root (max element) from the heap
    deleteRoot(heap, heapSize);

    printHeap(heap, heapSize);

    return 0;
}

