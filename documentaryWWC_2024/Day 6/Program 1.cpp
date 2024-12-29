/*
QUE.1:- Pair sum closet to 0 .
  */

Code :

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

pair<int, int> findClosestPair(vector<int>& nums) {
    // Sort the array
    sort(nums.begin(), nums.end());
    
    int left = 0, right = nums.size() - 1;
    int closestSum = INT_MAX; // Initialize to a large value
    pair<int, int> result;

    while (left < right) {
        int sum = nums[left] + nums[right];

        // Update the closest sum and result pair
        if (abs(sum) < abs(closestSum)) {
            closestSum = sum;
            result = {nums[left], nums[right]};
        }

        // Move the pointers based on the sum
        if (sum < 0) {
            left++; // Increase the sum
        } else {
            right--; // Decrease the sum
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 2, -3, 4, -2};
    pair<int, int> result = findClosestPair(nums);

    cout << "Pair closest to 0: (" << result.first << ", " << result.second << ")" << endl;
    return 0;
}
/*
OUTPUT

Pair closest to 0: (-2, 2)
  */
