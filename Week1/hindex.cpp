/*
  BEGIN-HEADER

  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Did not know what H index is, had to google and learn about it before implementing. source: https://en.wikipedia.org/wiki/H-index

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

int main()
{
    ll n, c, count = 0;
    cin >> n;
    vector<ll> li;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        li.push_back(c);
    }
    sort(li.begin(), li.end());

    for (int i = 0; i < n; i++)
    {
        if (li[i] >= n-i)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}