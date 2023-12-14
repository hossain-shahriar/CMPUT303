/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  used a graph to represent the trading partnerships between countries and implemented a BFS to traverse and determine if the home country will leave or stay.

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

int main() {
    ll c, p, x, l;
    cin >> c >> p >> x >> l;

    vector<vector<ll>> partner(c+1);
    vector<ll> leave(c+1, 0), total(c+1, 0), leaving(c+1, 0);

    for(ll i = 0; i < p; ++i) {
        ll a, b;
        cin >> a >> b;
        partner[a].push_back(b);
        partner[b].push_back(a);
        total[a]++;
        total[b]++;
    }

    queue<ll> q;
    q.push(l);
    leave[l] = 1;

    while(!q.empty()) {
        ll country = q.front();
        q.pop();

        for(ll i : partner[country]) {
            if(!leave[i]) {
                leaving[i]++;
                if(2*leaving[i] >= total[i]) {
                    leave[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    if(leave[x]) {
        cout << "leave" << endl;
    } else {
        cout << "stay" << endl;
    }

    return 0;
}
