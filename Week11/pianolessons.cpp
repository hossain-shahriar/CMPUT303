/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://www.geeksforgeeks.org/maximum-bipartite-matching/ (copied bpm and maxBPM function from this website)
  https://eclass.srv.ualberta.ca/pluginfile.php/10032879/mod_resource/content/7/10-matchings-flows.pdf

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

#define M 1000
#define N 1000

bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[]) {
    for (int v = 0; v < N; v++) {
        if (bpGraph[u][v] && !seen[v]) {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(bool bpGraph[M][N], int n) {
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));

    int result = 0;
    for (int u = 0; u < n; u++) {
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}
int main() {
    int n, m, t, s;
    cin >> n >> m;
    bool bpGraph[M][N] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> t;
        while (t--) {
            cin >> s;
            bpGraph[i][s - 1] = true;
        }
    }
    cout << maxBPM(bpGraph, n) << endl;
    return 0;
}