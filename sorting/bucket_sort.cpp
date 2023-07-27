#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform insertion sort on a bucket
void insertionSort(std::vector<int>& bucket) {
    int n = bucket.size();
    for (int i = 1; i < n; ++i) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Bucket Sort implementation
void bucketSort(std::vector<int>& arr) {
    int n = arr.size();
    const int numBuckets = 10; // Number of buckets

    // Create buckets as vectors of integers
    std::vector<std::vector<int>> buckets(numBuckets);

    // Place elements in the appropriate buckets
    for (int i = 0; i < n; ++i) {
        int bucketIndex = arr[i] / numBuckets;
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < numBuckets; ++i) {
        insertionSort(buckets[i]);
    }

    // Concatenate sorted buckets to obtain the final sorted array
    int index = 0;
    for (int i = 0; i < numBuckets; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    std::vector<int> arr = {19, 22, 45, 11, 67, 55, 1, 5, 99, 12, 42};
    bucketSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
