/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  googled how to write short hand if else. Source: https://www.w3schools.com/cpp/cpp_conditions_shorthand.asp

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
	ll l, h, v, a, b;
    cin >> l >> h >> v;
    a = (h > l-h) ? h : l-h;
    b = (v > l-v) ? v : l-v;
    cout << a*b*4;
    return 0;
}