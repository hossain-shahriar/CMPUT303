/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources. used unordered map to store translations. For each word in the given sentence, I calculated the number of correct and incorrect translations by iterating through the sentence using the dictionary.

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
    int n, m;
    string d, e, c;
    cin >> n;
    vector<string> dutch(n);
    for (int i = 0; i < n; i++) {
        cin >> dutch[i];
    }
    cin >> m;
    unordered_map<string, vector<pair<string, string>>> dict;
    for (int i = 0; i < m; i++) {
        cin >> d >> e >> c;
        dict[d].push_back({e, c});
    }
    ll correct = 1, incorrect = 0;
    for (int i = 0; i < dutch.size(); i++) {
        int ccount = 0, icount = 0;
        string word = dutch[i];
        for (int j = 0; j < dict[word].size(); j++) {
            auto trans = dict[word][j];
            if (trans.second == "correct") {
                ccount++;
            } else {
                icount++;
            }
        }
        incorrect = incorrect * (ccount + icount) + correct * icount;
        correct = correct * ccount;
    }
    if (correct == 1 && incorrect == 0) {
        for (int i = 0; i < dutch.size(); i++) {
            string word = dutch[i];
            cout << dict[word][0].first << " ";
        }
        cout << "\ncorrect\n";
    } else if (correct == 0 && incorrect == 1) {
        for (int i = 0; i < dutch.size(); i++) {
            string word = dutch[i];
            cout << dict[word][0].first << " ";
        }
        cout << "\nincorrect\n";
    } else {
        cout << correct << " correct\n";
        cout << incorrect << " incorrect\n";
    }
    return 0;
}