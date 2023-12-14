/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources. Sorted the keys in descending order. For each key, computed the number of combinations where it's the largest among K selected keys. Sum the product of each key's value and its combinations, and return the result modulo 1000000007

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
    ll n, k, comb, mod = 1000000007, den, required = 0;
    cin >> n >> k;
    vector<ll> keys(n);
    for (ll i = 0; i < n; ++i) {
        cin >> keys[i];
    }
    sort(keys.begin(), keys.end());
    reverse(keys.begin(), keys.end());
    for (ll i = 0; i <= n - k; ++i) {
        comb = 1;
        for (ll j = 0; j < k - 1; ++j) {
            comb = (comb*(n-i-1-j)) % mod;
            den = j + 1;
            for (ll x = mod - 2; x; x >>= 1) {
                if (x & 1) {
                    comb = (comb*den) % mod;
                }
                den = (den*den) % mod;
            }
        }
        required = (required + keys[i]*comb) % mod;
    }
    cout << required << endl;
    return 0;
}
