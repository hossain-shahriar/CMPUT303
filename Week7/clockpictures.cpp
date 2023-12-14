/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
  https://www.youtube.com/watch?v=V5-7GzOfADQ
  https://eclass.srv.ualberta.ca/pluginfile.php/10032848/mod_resource/content/7/07-strings.pdf

  Sorted the angles of the clock hands for both images and then calculated their consecutive differences. Used KMP to preprocess the differences of one image and then checked if these differences could be found within the cyclically duplicated differences of the other image

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
    int n;
    cin >> n;
    vector<int> h1(n);
    vector<int> h2(n);
    vector<int> dif1(2*n);
    vector<int> dif2(n);
    vector<int> p(n, 0);
    for (int &x : h1) {
        cin >> x;
    }
    for (int &x : h2) {
        cin >> x;
    }
    sort(h1.begin(), h1.end());
    sort(h2.begin(), h2.end());
    for (int i = 0; i < n; i++) {
        dif1[i] = dif1[i+n] = (h1[(i + 1) % n] - h1[i] + 360000) % 360000;
        dif2[i] = (h2[(i + 1) % n] - h2[i] + 360000) % 360000;
    }
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && dif2[i] != dif2[j]) j = p[j-1];
        if (dif2[i] == dif2[j]) j++;
        p[i] = j;
    }
    for (int i = 0, j = 0; i < 2*n; i++) {
        while (j > 0 && dif1[i] != dif2[j]) j = p[j-1];
        if (dif1[i] == dif2[j]) j++;
        if (j == n) {
            cout << "possible" << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
    return 0;
}
