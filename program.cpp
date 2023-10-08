#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <splashkit.h>

using namespace std;

// Function to print the elements of an array
void print_array(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

// Insertion Sort
void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(nullptr));
    vector<int> data;
    int n = 10; // Change this value to adjust the number of elements in the array

    // Generate a random dataset
    for (int i = 0; i < n; i++) {
        data.push_back(rand() % 100);
    }

    write_line("Original Array: ");
    print_array(data);

    // Bubble Sort
    vector<int> bubble_sorted = data;
    bubble_sort(bubble_sorted);
    write_line("Bubble Sort: ");
    print_array(bubble_sorted);

    // Selection Sort
    vector<int> selection_sorted = data;
    selection_sort(selection_sorted);
    write_line("Selection Sort: ");
    print_array(selection_sorted);

    // Insertion Sort
    vector<int> insertion_sorted = data;
    insertion_sort(insertion_sorted);
    write_line("Insertion Sort: ");
    print_array(insertion_sorted);

    // Merge Sort
    vector<int> merge_sorted = data;
    merge_sort(merge_sorted, 0, merge_sorted.size() - 1);
    write_line("Merge Sort: ");
    print_array(merge_sorted);

    // Quick Sort
    vector<int> quick_sorted = data;
    quick_sort(quick_sorted, 0, quick_sorted.size() - 1);
    write_line("Quick Sort: ");
    print_array(quick_sorted);

    // Heap Sort
    vector<int> heap_sorted = data;
    heap_sort(heap_sorted);
    write_line("Heap Sort: ");
    print_array(heap_sorted);

    return 0;
}
