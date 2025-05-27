#include <iostream>
using namespace std;

const int MAX_SIZE = 100;  // Maximum size of array

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

// Merge Function
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[MAX_SIZE], R[MAX_SIZE];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Binary Search (Array must be sorted)
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Not found
}

// Display Array
void displayArray(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;  // Size of array
    int choice;

    while (true) {
        cout << "\n=== Menu ===\n";
        cout << "1. Input Array\n";
        cout << "2. Display Array\n";
        cout << "3. Selection Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Linear Search\n";
        cout << "6. Binary Search\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter number of elements (max " << MAX_SIZE << "): ";
            cin >> n;
            if (n <= 0 || n > MAX_SIZE) {
                cout << "Invalid size. Try again.\n";
                n = 0;
                continue;
            }
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
        } else if (choice == 2) {
            if (n == 0) {
                cout << "Array is empty.\n";
            } else {
                displayArray(arr, n);
            }
        } else if (choice == 3) {
            if (n == 0) {
                cout << "Array is empty. Please input the array first.\n";
            } else {
                selectionSort(arr, n);
                cout << "Array sorted using Selection Sort.\n";
            }
        } else if (choice == 4) {
            if (n == 0) {
                cout << "Array is empty. Please input the array first.\n";
            } else {
                mergeSort(arr, 0, n - 1);
                cout << "Array sorted using Merge Sort.\n";
            }
        } else if (choice == 5) {
            if (n == 0) {
                cout << "Array is empty. Please input the array first.\n";
            } else {
                int key;
                cout << "Enter element to search (Linear Search): ";
                cin >> key;
                int pos = linearSearch(arr, n, key);
                if (pos != -1)
                    cout << "Element found at position: " << pos + 1 << endl;
                else
                    cout << "Element not found.\n";
            }
        } else if (choice == 6) {
            if (n == 0) {
                cout << "Array is empty. Please input the array first.\n";
            } else {
                int key;
                cout << "Enter element to search (Binary Search): ";
                cin >> key;
                // IMPORTANT: Binary search requires sorted array
                // You may warn user to sort first
                int pos = binarySearch(arr, n, key);
                if (pos != -1)
                    cout << "Element found at position: " << pos + 1 << endl;
                else
                    cout << "Element not found.\n";
            }
        } else if (choice == 7) {
            cout << "Exiting program. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
