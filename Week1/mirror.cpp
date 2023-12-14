/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  w3school, stackoverflow for common C++ errors and to know how to implement a vector in C++

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
  int test_cases;
  cin >> test_cases;

  for (int test_no = 0; test_no < test_cases; ++test_no) {
    int row, column;
    cin >> row >> column;
    vector<vector<char>> matrix(row, vector<char>(column));

    for (int i = 0; i < row; ++i) {
        string inputRow;
        cin >> inputRow;

        if (inputRow.length() != column) {
            cout << "Error: Input row does not have the correct length." << endl;
            return 1;
        }

        for (int j = 0; j < column; ++j) {
            matrix[i][j] = inputRow[j];
        }
    }
    vector<vector<char>> matrix2 = matrix;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            matrix2[row-i-1][column-j-1] = matrix[i][j];
        }
        cout << endl;
    }
    cout << "Test " << test_no+1 << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cout << matrix2[i][j] << "";
        }
        cout << endl;
    }
  }

  return 0;
}