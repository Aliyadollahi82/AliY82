#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)    
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

// Selection Sort 
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Binary Search
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Linear Search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main() {
    // Sample input array
    int arr[] = {5, 2, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort
    cout << "Bubble Sort: ";
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Selection Sort
    int selectionArr[] = {5, 2, 8, 1, 9};
    cout << "Selection Sort: ";
    selectionSort(selectionArr, n);
    for (int i = 0; i < n; i++)
        cout << selectionArr[i] << " ";
    cout << endl;

    // Insertion Sort
    int insertionArr[] = {5, 2, 8, 1, 9};
    cout << "Insertion Sort: ";
    insertionSort(insertionArr, n);
    for (int i = 0; i < n; i++)
        cout << insertionArr[i] << " ";
    cout << endl;

    // Binary Search
    int binaryArr[] = {1, 2, 5, 8, 9};
    int target = 5;
    int index = binarySearch(binaryArr, 0, n - 1, target);
    cout << "Binary Search: Element " << target << " found at index " << index << endl;

    // Linear Search
    int linearArr[] = {5, 2, 8, 1, 9};
    target = 8;
    index = linearSearch(linearArr, n, target);
    cout << "Linear Search: Element " << target << " found at index " << index << endl;

    return 0;
}