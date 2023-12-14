/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  It was a tough one. I did not know what peg solitaire is, and when I understood, I tried DFS first and could not solve it. So I tried BFS and it worked. Links that I used for help:
  https://en.wikipedia.org/wiki/Peg_solitaire
  https://www.youtube.com/watch?v=S-_7xNcARuQ&themeRefresh=1
  https://ece.uwaterloo.ca/~dwharder/aads/Algorithms/Backtracking/Peg_solitaire/

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

bool valid(vector<string>& board, int x, int y, int dx, int dy) {
    int nx = x+2*dx, ny = y+2*dy;
    bool inbound = nx >= 0 && nx < 5 && ny >= 0 && ny < 9;
    if(!inbound) {
        return false;
    }
    bool haspeg = board[x][y] == 'o';
    bool joverpeg = board[x+dx][y+dy] == 'o';
    bool empty = board[nx][ny] == '.';
    return haspeg && joverpeg && empty;
}
void apply(vector<string>& board, int x, int y, int dx, int dy) {
    board[x][y] = '.';
    board[x+dx][y+dy] = '.';
    board[x+2*dx][y+2*dy] = 'o';
}
void undo(vector<string>& board, int x, int y, int dx, int dy) {
    board[x][y] = 'o';
    board[x+dx][y+dy] = 'o';
    board[x+2*dx][y+2*dy] = '.';
}
int countp(vector<string>& board) {
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        count += std::count(board[i].begin(), board[i].end(), 'o');
    }
    return count;
}
pair<int, int> bfs(vector<string> board) {
    vector<pair<int, int>> direction{{0,1},{1,0},{0,-1},{-1,0}};
    queue<pair<vector<string>, int>> q;
    unordered_set<string> visited;
    string stringb;
    for (auto& row : board) stringb += row;
    q.push({board, 0});
    visited.insert(stringb);
    int minpeg = countp(board);
    int minmove = 0;

    while (!q.empty()) {
        pair<vector<string>, int> front = q.front();
        vector<string> currentb = front.first;
        int move = front.second;
        q.pop();
        int peg = countp(currentb);
        if (peg < minpeg || (peg == minpeg && move < minmove)) {
            minpeg = peg;
            minmove = move;
        }
        for (int x = 0; x < 5; ++x) {
            for (int y = 0; y < 9; ++y) {
                for (pair<int, int>& dir : direction) {
                    int dx = dir.first;
                    int dy = dir.second;

                    if (valid(currentb, x, y, dx, dy)) {
                        apply(currentb, x, y, dx, dy);
                        string stringst;
                        for (auto& row : currentb) stringst += row;

                        if (visited.find(stringst) == visited.end()) {
                            visited.insert(stringst);
                            q.push({currentb, move+1});
                        }

                        undo(currentb, x, y, dx, dy);
                    }
                }
            }
        }
    }
    return make_pair(minpeg, minmove);
}
int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        vector<string> board(5);
        for (int j = 0; j < 5; ++j) {
            cin >> board[j];
        }

        pair<int, int> result = bfs(board);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
