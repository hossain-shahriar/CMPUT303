/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://www.geeksforgeeks.org/minimum-cost-path-left-right-bottom-moves-allowed/
  https://www.codingninjas.com/studio/library/minimum-cost-path-with-left-right-bottom-and-up-moves-allowed
  
  Solved the problem by using hash maps to count points with the same X or Y coordinates and then calculated the number of right triangles for each point based on these counts

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
using ll = long long;

struct Node {
    ll x, y, used;
    Node(ll x, ll y, ll used)
        : x(x)
        , y(y)
        , used(used) 
    {
    }
};
bool operator<(const Node& a, const Node& b) {
    return (a.y > b.y);
}
vector<pair<ll, ll>> graph[50000];
ll shortest(ll n, ll start, ll end) {
    vector<vector<ll>> dist(n, vector<ll>(2, LLONG_MAX));
    priority_queue<Node> pq;
    pq.push(Node(start, 0, 0));
    dist[start][0] = 0;
    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        if (curr.x == end) {
            return dist[end][curr.used];
        }
        for (auto& e : graph[curr.x]) {
            ll cityNext = e.first;
            ll costNext = curr.y + e.second;
            ll usedNext = curr.used;
            if (e.second == 0 && curr.used == 1) {
                continue;
            }
            if (e.second == 0) {
                usedNext = 1;
            }
            if (costNext < dist[cityNext][usedNext]) {
                dist[cityNext][usedNext] = costNext;
                pq.push(Node(cityNext, costNext, usedNext));
            }
        }
    }
    return min(dist[end][0], dist[end][1]);
}
int main() {
    ll n, m, f, s, t, from, to, cost;
    cin >> n >> m >> f >> s >> t;
    for (ll k = 0; k < m; ++k) {
        cin >> from >> to >> cost;
        graph[from].emplace_back(to, cost);
        graph[to].emplace_back(from, cost);
    }
    for (ll k = 0; k < f; ++k) {
        cin >> from >> to;
        graph[from].emplace_back(to, 0);
    }
    cout << shortest(n, s, t) << endl;
    return 0;
}