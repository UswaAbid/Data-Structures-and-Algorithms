
 #include <iostream>

using namespace std;

int getMax(int arr[], int n) {
    int maxNum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }
    return maxNum;
}

void countingSort(int arr[], int n, int exp) {
    const int RADIX = 10;
    int output[100];
    int count[RADIX] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % RADIX]++;
    }

    for (int i = 1; i < RADIX; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
        count[(arr[i] / exp) % RADIX]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int maxNum = getMax(arr, n);

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;
    cout << "\n Enter the number of elements: ";
    cin >> n;

    int arr[100];
    cout << "\n Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cout << " ";
    }

    radixSort(arr, n);

    cout << "\n Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


