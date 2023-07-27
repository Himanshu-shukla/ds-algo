#include <iostream>
#include <vector>

// Function to find the maximum element in the array
int findMax(std::vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to perform counting sort based on a specific digit
void countingSortByDigit(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    // Count the occurrences of each digit at the specified position
    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calculate the cumulative count
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array in a stable manner
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Radix Sort implementation
void radixSort(std::vector<int>& arr) {
    int maxVal = findMax(arr);

    // Perform counting sort for every digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {170,55, 89, 9800, 654, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
