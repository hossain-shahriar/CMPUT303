/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources, used prim's algorithm to find the MST. Calculated the energy required to activate the channels in the MST and to send the program to all the stations.

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
using stationPair = pair<ll, ll>;

ll mstPrims(ll n, vector<stationPair> adj[], vector<ll>& initial, ll total) {
    vector<ll> key(n + 1, numeric_limits<ll>::max());
    vector<bool> inMst(n + 1, false);
    priority_queue<stationPair, vector<stationPair>, greater<stationPair>> pq;
    for (ll station : initial) {
        key[station] = 0;
        pq.push({0, station});
    }
    while (!pq.empty()) {
        ll a = pq.top().second;
        pq.pop();
        inMst[a] = true;
        for (stationPair edge : adj[a]) {
            ll b = edge.first;
            ll weight = edge.second;

            if (!inMst[b] && weight < key[b]) {
                key[b] = weight;
                pq.push({key[b], b});
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        total += key[i];
    }
    return total;
}

int main() {
    ll data, total=0, n, m, l, s, i, j, e;
    cin >> data;
    while (data--) {
        cin >> n >> m >> l >> s;
        vector<ll> initial(s);
        for (ll i = 0; i < s; i++) {
            cin >> initial[i];
        }
        vector<stationPair> adj[n + 1];
        for (ll k = 0; k < m; k++) {
            cin >> i >> j >> e;
            adj[i].push_back({j, e});
            adj[j].push_back({i, e});
        }
        ll energy = mstPrims(n, adj, initial, total);
        ll program = l*(n - s);
        cout << energy + program << endl;
    }
    return 0;
}
