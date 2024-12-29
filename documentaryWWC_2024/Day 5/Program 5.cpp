/*
Que 5:-

Searching element from roateted Array on leet code .
*/
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the mid element is the target
        if (nums[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (nums[left] <= nums[mid]) {
            // Target lies in the sorted left half
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else { // Target is in the unsorted right half
                left = mid + 1;
            }
        } 
        // Otherwise, the right half is sorted
        else {
            // Target lies in the sorted right half
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else { // Target is in the unsorted left half
                right = mid - 1;
            }
        }
    }

    // If the element is not found
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = search(nums, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
/*
OUTPUT

Element found at index: 4

*/
