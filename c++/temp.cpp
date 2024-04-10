#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// Selection Sort Algorithm
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

// Heapify the subtree rooted at index 'i'
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heap Sort Algorithm
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    // Timing Selection Sort
    auto start_selection = std::chrono::steady_clock::now();
    selectionSort(arr);
    auto end_selection = std::chrono::steady_clock::now();
    std::chrono::duration<double> selection_time = end_selection - start_selection;
    std::cout << "Time taken by Selection Sort: " << selection_time.count() << " seconds" << std::endl;

    // Reset array
    arr = {12, 11, 13, 5, 6, 7};

    // Timing Heap Sort
    auto start_heap = std::chrono::steady_clock::now();
    heapSort(arr);
    auto end_heap = std::chrono::steady_clock::now();
    std::chrono::duration<double> heap_time = end_heap - start_heap;
    std::cout << "Time taken by Heap Sort: " << heap_time.count() << " seconds" << std::endl;

    return 0;
}
