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

int main() {
    int q, n, d;
    cin >> q >> n >> d;

    vector<vector<ll>> points(n+1, vector<ll>(2*n+1, 0));
    string f1, f2;
    cin >> f1 >> f2;

for (int i = 0; i < q; ++i) {
    int count = 0;
    if (i == f1[0]-'0') {
        count++;
    }
    if (i == f2[0]-'0') {
        count++;
    }
    points[1][count] += 1;
}
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 2*n; ++j) {
            if (f1[i-1] == f2[i-1]) {
                if (j >= 2) {
                    points[i][j] += points[i-1][j-2];
                }
                points[i][j] += (q-1)*(points[i-1][j]);
            } else {
                if (j >= 1) {
                    points[i][j] += 2*points[i-1][j-1];
                }
                points[i][j] += (q-2)*(points[i-1][j]);
            }
        }
    }
    cout << points[n][2*n-d] << endl;
    return 0;
}