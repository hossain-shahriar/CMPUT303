/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources

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

bool isPrime(ll n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n%2 == 0 || n%3 == 0) {
        return false;
    }
    for (ll i = 5; i*i <= n; i += 6) {
        if (n%i == 0 || n%(i+2) == 0) return false;
    }
    return true;
}

ll nextPrime(ll n) {
    while (isPrime(n) == false) {
        n++;
    }
    return n;
}

int main() {
    ll n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        bool prime = isPrime(n);
        ll next = nextPrime(2*n);
        cout << next;
        if (prime == false) {
            cout << " (" << n << " is not prime)";
        }
        cout << endl;
    }
    return 0;
}
