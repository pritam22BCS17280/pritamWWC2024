/*
QUE.3:-- Find the Kth smallest sum of matrix with sorted row on (leet code).
*/
Code:


#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

struct Element {
    int sum;
    vector<int> indices; // Indices of elements contributing to the sum
    
    Element(int sum, vector<int> indices) : sum(sum), indices(indices) {}
    
    bool operator>(const Element& other) const {
        return sum > other.sum; // Min-heap based on sum
    }
};

int kthSmallestSum(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    
    // Min-heap to store the sum and indices of the elements contributing to that sum
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Initialize the heap with the sum of the first element in each row
    vector<int> indices(m, 0); // Indices pointing to the first element in each row
    int initialSum = 0;
    for (int i = 0; i < m; ++i) {
        initialSum += matrix[i][0];
    }
    
    minHeap.push(Element(initialSum, indices));
    
    // Pop k times to find the kth smallest sum
    for (int count = 0; count < k; ++count) {
        Element current = minHeap.top();
        minHeap.pop();
        
        // If we have already popped k sums, return the current sum
        if (count == k - 1) {
            return current.sum;
        }
        
        // Generate next sums by incrementing indices in each row
        for (int i = 0; i < m; ++i) {
            if (current.indices[i] + 1 < n) {
                vector<int> newIndices = current.indices;
                newIndices[i]++;
                int newSum = current.sum - matrix[i][current.indices[i]] + matrix[i][newIndices[i]];
                minHeap.push(Element(newSum, newIndices));
            }
        }
    }
    
    return -1; // If Kth smallest sum doesn't exist (shouldn't happen in valid cases)
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 11}, {2, 4, 6}, {1, 2, 3}};
    int k = 5;

    cout << "The " << k << "th smallest sum is: " << kthSmallestSum(matrix, k) << endl;

    return 0;
}
/*
OUTPUT

The 5th smallest sum is: 6

*/
