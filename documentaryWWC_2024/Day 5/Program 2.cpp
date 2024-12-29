Que2:-- Sorted Array search.

Code:
#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(int k, const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    int result = -1; // Store the index of the first occurrence

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == k) {
            result = mid + 1; // Store the 1-based index
            right = mid - 1;  // Move left to find the first occurrence
        } else if (arr[mid] < k) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return result; // Returns -1 if not found
}

int main() {
    // Example 1
    int k1 = 16;
    vector<int> arr1 = {4, 7, 16, 16, 20, 25};
    cout << findFirstOccurrence(k1, arr1) << endl; // Output: 3

    // Example 2
    int k2 = 98;
    vector<int> arr2 = {1, 22, 57, 57, 66, 99};
    cout << findFirstOccurrence(k2, arr2) << endl; // Output: -1

    return 0;
}
/*
OUTPUT:-
  3
  -1
  */
