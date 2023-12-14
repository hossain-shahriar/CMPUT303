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

unordered_map<ll, ll> saved;
ll calculateEndings(int page, vector<vector<int>>& option, vector<int>& ending) {
    if(saved.count(page)) {
        return saved[page];
    }
    if(ending[page] != 0) {
        if (ending[page] == 1)
        {
            return 1;
        }
        else {
            return 0;
        }
    }
    ll endingSum = 0;
    for(int i = 0; i < 3; i++) {
        endingSum += calculateEndings(option[page][i], option, ending);
    }
    saved[page] = endingSum;
    return endingSum;
}

int main() {
    int t, s;
    ll distinct;
    cin >> t;
    while(t--) {
        cin >> s;
        vector<vector<int>> option((400+1), vector<int>(3, 0));
        vector<int> ending((400+1), 0);
        saved.clear();
        for(int i = 0; i < s; i++) {
            int page;
            cin >> page;
            string next;
            cin >> next;
            if(next == "favourably") {
                ending[page] = 1;
            } else if(next == "catastrophically") {
                ending[page] = -1;
            } else {
                option[page][0] = stoi(next);
                cin >> option[page][1] >> option[page][2];
            }
        }
        distinct = calculateEndings(1, option, ending);
        cout << distinct << endl;
    }
    return 0;
}