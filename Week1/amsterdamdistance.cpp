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

int main() {
    int n, m, ax, ay, bx, by;
    long double r, result;
    cin >> m >> n >> r;
    cin >> ax >> ay >> bx >> by;
    if (ay >= by)
    {
      result = (abs(ay-by) * r/n) + ((M_PI*r*abs(ax-bx)*by)/(m*n));
    }
    else{
      result = (abs(ay-by) * r/n) + ((M_PI*r*abs(ax-bx)*ay)/(m*n));
    }
    if (result > ((r/n)*(ay+by)))
    {
      result = ((r/n)*(ay+by));
    }
    cout << setprecision(15) << result << endl;
    return 0;
}