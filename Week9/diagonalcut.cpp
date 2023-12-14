/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://en.cppreference.com/w/cpp/numeric/gcd
  https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/

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

ll countDiagonal(ll a, ll b) {
    ll gcd = __gcd(a, b);
    if (gcd > 1) {
        return gcd*countDiagonal(a/gcd, b/gcd);
    }
    return (b%2)*(a%2);
}

int main() {
    ll m, n;
    cin >> m >> n;
    cout << countDiagonal(m, n) << endl;
    return 0;
}