/*
que.1: Find centre of star graph.
  */

Code:

#include <iostream>
#include <vector>

using namespace std;

int findCenter(int n, vector<vector<int>>& adj) {
    // The center of the star graph is the node with the highest degree
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == n - 1) {
            return i;  // The node with degree n-1 is the center
        }
    }
    return -1;  // Return -1 if no center is found (not expected in a star graph)
}

int main() {
    int n;
    cout << "Enter the number of nodes in the star graph: ";
    cin >> n;
    
    // Create adjacency list for the graph
    vector<vector<int>> adj(n);

    // Input the edges
    cout << "Enter the edges (pairs of nodes):\n";
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Find the center of the star graph
    int center = findCenter(n, adj);

    cout << "The center of the star graph is node: " << center << endl;

    return 0;
}
/*
OUTPUT
Enter the number of nodes in the star graph: 5
Enter the edges (pairs of nodes):
0 1
0 2
0 3
0 4
The center of the star graph is node: 0
  */
