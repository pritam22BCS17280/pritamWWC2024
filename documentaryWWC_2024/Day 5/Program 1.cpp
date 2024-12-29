/*
Que.1 - Searching a Number 

Given an integer k and array arr. Your task is to return the position of the first occurrence of k in the given array and if element k is not present in the array then return -1.

Note: 1-based indexing is followed here.

Examples:

Input: k = 16 , arr = [9, 7, 16, 16, 4]
Output: 3
Explanation: The value 16 is found in the given array at positions 3 and 4, with position 3 being the first occurrence.
Input: k=98 , arr = [1, 22, 57, 47, 34, 18, 66]
Output: -1
Explanation: k = 98 isn't found in the given array.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size <= 106
1 <= arr[i] <= 109
1 <= k <= 106
  */

Code:--


#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(int k, const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == k) {
            return i + 1; // Return 1-based index
        }
    }
    return -1; // Return -1 if k is not found
}

int main() {
    // Example 1
    int k1 = 16;
    vector<int> arr1 = {9, 7, 16, 16, 4};
    cout << findFirstOccurrence(k1, arr1) << endl; // Output: 3

    // Example 2
    int k2 = 98;
    vector<int> arr2 = {1, 22, 57, 47, 34, 18, 66};
    cout << findFirstOccurrence(k2, arr2) << endl; // Output: -1

    return 0;
}
