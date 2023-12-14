/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources. Solved the problem by using dp to find all path lengths in two directed acyclic graphs, and then checked for each query if a sum of path lengths from both graphs matched the query value

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  I did not discuss this exercise with anyone.

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 303/403.

  END-HEADER
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1, n2, m1, m2, Q;
    cin >> n1 >> n2 >> m1 >> m2;
    vector<int> edge1[1001], edge2[1001];
    bool dp1[1001][1001], dp2[1001][1001];
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        edge1[u].push_back(v);
    }
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        edge2[u].push_back(v);
    }
    memset(dp1, false, sizeof(dp1));
    memset(dp2, false, sizeof(dp2));
    dp1[1][0] = true;
    for (int i = 1; i < n1+1; i++) {
        for (int u : edge1[i]) {
            for (int j = 0; j < n1; j++) {
                if (dp1[i][j]) {
                    dp1[u][j+1] = true;
                }
            }
        }
    }
    dp2[1][0] = true;
    for (int i = 1; i < n2+1; i++) {
        for (int u : edge2[i]) {
            for (int j = 0; j < n2; j++) {
                if (dp2[i][j]) {
                    dp2[u][j+1] = true;
                }
            }
        }
    }
    cin >> Q;
    while (Q) {
        int q;
        cin >> q;
        bool found = false;
        for (int i = 0; i <= q; i++) {
            if (i < n1 && q-i < n2 && dp1[n1][i] && dp2[n2][q-i]) {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        Q--;
    }
    return 0;
}