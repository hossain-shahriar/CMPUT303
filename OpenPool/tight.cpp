/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources.

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
    vector<vector<double>> dp(100, vector<double>(10, 0));
    int k, n;
    while (cin >> k >> n) {
        for (int i = 0; i <= k; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i-1][j];
                if (j > 0) {
                    dp[i][j] += dp[i-1][j-1];
                }
                if (j < k) {
                    dp[i][j] += dp[i-1][j+1];
                }
            }
        }
        double result = 0;
        for (int i = 0; i <= k; i++) {
            result += dp[n][i];
        }
        result = (result/pow(k + 1, n))*100;
        cout << fixed << setprecision(9) << result << endl;
    }
    return 0;
}