/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  googled how to implement LIFO. Learned what stack is and how to implement it from this link: https://www.codecademy.com/resources/docs/cpp/stacks

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
    int n, m=0;
    cin >> n;
    vector<int> sock(2*n);

    for (int i = 0; i < 2*n; i++) {
        cin >> sock[i];
    }

    stack<int> stackSock;
    unordered_map<int, int> count;

    for (int i = 0; i < 2*n; i++) {
        if (stackSock.empty() || (stackSock.top() != sock[i])) {
            stackSock.push(sock[i]);
        }
        else {
            stackSock.pop();
            m += 2;
        }
        count[sock[i]] += count[sock[i]];
    }

    if (stackSock.empty()) {
        cout << m << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}