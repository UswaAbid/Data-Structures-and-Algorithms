
 
 #include <iostream>
 using namespace std;

void max_heapify(int *a, int m, int n) {
    int j, t;
    t = a[m];
    j = 2 * m;
    while (j <= n) {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (t > a[j])
            break;
        else if (t <= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = t;
}

void build_maxheap(int *a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        max_heapify(a, k, n);
    }
}

void min_heapify(int *a, int m, int n) {
    int j, t;
    t = a[m];
    j = 2 * m;
    while (j <= n) {
        if (j < n && a[j + 1] < a[j])
            j = j + 1;
        if (t < a[j])
            break;
        else if (t >= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = t;
}

void build_minheap(int *a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        min_heapify(a, k, n);
    }
}

int main() {
    int n, i;
    cout << "Enter the number of elements of the array: ";
    cin >> n;
    int a[30];
    for (i = 1; i <= n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> a[i];
    }

    build_maxheap(a, n);
    cout << "Max Heap\n";
    for (i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }

    build_minheap(a, n);
    cout << "Min Heap\n";
    for (i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
 
