/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources. used greedy algorithm.started from first island, tried to conquer as many islands as possible by choosing the island with the smallest army. used priority queue to select next island to conquer

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
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> bridge(n+1);
    vector<int> army(n+1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        bridge[a].push_back(b);
        bridge[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        cin >> army[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<bool> conquered(n+1, false);
    int total = army[1];
    conquered[1] = true;
    for(int neighbor : bridge[1]) {
        pq.push({army[neighbor], neighbor});
    }
    while(!pq.empty()) {
        int current = pq.top().second;
        pq.pop();
        if(conquered[current] || army[current] >= total) continue;
        conquered[current] = true;
        total += army[current];
        for(int neighbor : bridge[current]) {
            if(!conquered[neighbor]) {
                pq.push({army[neighbor], neighbor});
            }
        }
    }

    cout << total << endl;
    return 0;
}
