/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources. Solved the problem by using stacks to manage nested resistor arrangements in the circuit and calculated the total resistance directly in the main function, handling both series and parallel connections

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
    int n, pos=0, ind;
    double total, invTotal, result;
    string circuit;
    char c;
    stack<vector<double>> series;
    stack<bool> parallel;
    vector<double> currResist;
    bool isPara = false;
    cin >> n;
    vector<double> resValue(n);
    for (int i = 0; i < n; ++i) {
        cin >> resValue[i];
    }
    cin >> circuit;
    while (pos < circuit.length()) {
        c = circuit[pos];
        pos++;
        if (c == '(') {
            series.push(currResist);
            parallel.push(isPara);
            currResist.clear();
            isPara = false;
        } else if (c == ')') {
            if (isPara) {
                invTotal = 0;
                for (double r : currResist) {
                    invTotal += 1 / r;
                }
                total = 1 / invTotal;
            } else {
                total = accumulate(currResist.begin(), currResist.end(), 0.0);
            }
            currResist = series.top();
            isPara = parallel.top();
            series.pop();
            parallel.pop();
            currResist.push_back(total);
        } else if (c == '|') {
            isPara = true;
        } else if (c == 'R') {
            ind = circuit[pos] - '1';
            pos++;
            currResist.push_back(resValue[ind]);
        }
    }
    if (isPara) {
        double invTotal = 0;
        for (double r : currResist) {
            invTotal += 1 / r;
        }
        result = 1 / invTotal;
    } else {
        result = accumulate(currResist.begin(), currResist.end(), 0.0);
    }
    cout.precision(5);
    cout << fixed << result << endl;
    return 0;
}