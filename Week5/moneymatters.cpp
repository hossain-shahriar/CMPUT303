/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources. used DFS to traverse the graph and calculate the total debt for each connected component

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

vector<vector<int>> friendlist;
vector<int> amount;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    int total = amount[node];
    for (int i = 0; i < friendlist[node].size(); i++) {
    int neighbor = friendlist[node][i];
        if (!visited[neighbor]) {
            total += dfs(neighbor);
        }
    }
    return total;
}
int main() {
    int n, m;
    cin >> n >> m;
    friendlist.resize(n);
    amount.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        cin >> amount[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friendlist[x].push_back(y);
        friendlist[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i) != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
    return 0;
}
