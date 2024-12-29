/*
QU.2:--  Search in 2d Matrix on (Leet code ).
*/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / n][mid % n]; // Convert 1D index to 2D index

        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    if (searchMatrix(matrix, target)) {
        cout << "Target found in the matrix!" << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
/*
OUTPUT

Target found in the matrix!

*/
