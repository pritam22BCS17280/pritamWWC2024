/*
Que 3..
Find target indeces after sorting on leetcode.


You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

 

Example 1:

Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.
Example 2:

Input: nums = [1,2,5,2,3], target = 3
Output: [3]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.
Example 3:

Input: nums = [1,2,5,2,3], target = 5
Output: [4]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i], target <= 100
*/

Code:---

#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
    // Step 1: Sort the array in non-decreasing order
    sort(nums.begin(), nums.end());
    
    vector<int> result;
    // Step 2: Collect indices of elements equal to the target
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            result.push_back(i); // Append the index
        }
    }
    return result;
}

int main() {
    // Example 1
    vector<int> nums1 = {1, 2, 5, 2, 3};
    int target1 = 2;
    vector<int> result1 = targetIndices(nums1, target1);
    for (int idx : result1) cout << idx << " "; // Output: 1 2
    cout << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 5, 2, 3};
    int target2 = 3;
    vector<int> result2 = targetIndices(nums2, target2);
    for (int idx : result2) cout << idx << " "; // Output: 3
    cout << endl;

    // Example 3
    vector<int> nums3 = {1, 2, 5, 2, 3};
    int target3 = 5;
    vector<int> result3 = targetIndices(nums3, target3);
    for (int idx : result3) cout << idx << " "; // Output: 4
    cout << endl;

    return 0;
}
/*
OUTPUT:-
  
1 2 
3 
4 
*/
