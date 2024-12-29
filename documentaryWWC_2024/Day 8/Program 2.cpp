/*
que-2:-.Find the town judge.
  */

Code :

#include <iostream>
#include <vector>
using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {
    // Arrays to keep track of trust and being trusted counts
    vector<int> trusts(N + 1, 0);  // trusts[i] = number of people person i trusts
    vector<int> trustedBy(N + 1, 0);  // trustedBy[i] = number of people who trust person i

    // Process each trust relationship
    for (const auto& t : trust) {
        int a = t[0], b = t[1];
        trusts[a]++;  // Person a trusts someone
        trustedBy[b]++;  // Person b is trusted by someone
    }

    // Find the judge: person i should be trusted by N-1 people and trust no one
    for (int i = 1; i <= N; i++) {
        if (trusts[i] == 0 && trustedBy[i] == N - 1) {
            return i;  // Person i is the judge
        }
    }

    return -1;  // No judge exists
}

int main() {
    int N, M;
    cout << "Enter the number of people (N): ";
    cin >> N;
    cout << "Enter the number of trust relations (M): ";
    cin >> M;
    
    vector<vector<int>> trust(M, vector<int>(2));
    cout << "Enter the trust pairs (a b) where a trusts b:\n";
    for (int i = 0; i < M; i++) {
        cin >> trust[i][0] >> trust[i][1];
    }

    int judge = findJudge(N, trust);
    if (judge != -1) {
        cout << "The town judge is person: " << judge << endl;
    } else {
        cout << "There is no town judge.\n";
    }

    return 0;
}
/*
OUTPUT
Enter the number of people (N): 3
Enter the number of trust relations (M): 2
Enter the trust pairs (a b) where a trusts b:
1 2
2 3
The town judge is person: 2
  */
