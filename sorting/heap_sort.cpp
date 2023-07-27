#include <iostream>
#include <vector>

// Function to perform the heapify operation on a subtree rooted at index 'root'
void heapify(std::vector<int>& arr, int n, int root) {
    int largest = root; // Initialize the largest element as the root
    int left = 2 * root + 1; // Index of the left child
    int right = 2 * root + 2; // Index of the right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root, swap the root and the largest element
    if (largest != root) {
        std::swap(arr[root], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort implementation
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build a max-heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Extract elements one by one from the max-heap
    for (int i = n - 1; i >= 0; --i) {
        // Move the current root to the end
        std::swap(arr[0], arr[i]);

        // Reduce the heap size and heapify the root element
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 55, 780, 124, 13, 5, 6, 7};
    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
