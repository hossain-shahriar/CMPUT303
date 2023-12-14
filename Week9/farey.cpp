/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  https://cp-algorithms.com/algebra/phi-function.html
  https://en.wikipedia.org/wiki/Euler%27s_totient_function
  https://www.geeksforgeeks.org/sieve-of-eratosthenes/

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

vector<int> phiCompute(int n) {
    vector<int> phi(n + 1);
    iota(phi.begin(), phi.end(), 0);

    for (int p = 2; p <= n; p++) {
        if (phi[p] == p) {
            phi[p] = p-1;
            for (int i = 2*p; i <= n; i += p) {
                phi[i] = (phi[i]/p)*(p-1);
            }
        }
    }
    return phi;
}
int fsLength(int n) {
    vector<int> value = phiCompute(n);
    int len = 1;
    for (int i = 1; i <= n; i++) {
        len += value[i];
    }
    return len;
}
int main() {
    int p, k, n, fsl;
    cin >> p;
    while (p) {
        cin >> k >> n;
        fsl = fsLength(n);
        cout << k << " " << fsl << endl;
        p--;
    }
    return 0;
}