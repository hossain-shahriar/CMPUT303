/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://favtutor.com/blogs/bfs-breadth-first-search-cpp#:~:text=To%20perform%20a%20BFS%20traversal,node%200%20to%20the%20queue
  https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/#:~:text=BFS%20is%20a%20traversing%20algorithm,level%20neighbour%20nodes
  https://www.programiz.com/dsa/graph-bfs#:~:text=Breadth%20First%20Traversal%20or%20Breadth,as%20visited%20while%20avoiding%20cycles
  https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/


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

struct Node {
    short x, y;
    int clMax;
    bool operator>(const Node& other) const {
        return clMax > other.clMax;
    }
};
int bfs(vector<vector<int>>& vault, int m, int n) {
    vector<vector<int>> height(m, vector<int>(n, INT_MAX));
    priority_queue<Node, vector<Node>, greater<Node>> p;
    p.push({0, 0, 0});
    height[0][0] = 0;
    int moveX[] = {-1, 1, 0, 0};
    int moveY[] = {0, 0, 1, -1};
    while (!p.empty()) {
        Node current = p.top();
        p.pop();
        if (current.x == m-1 && current.y == n-1) {
            return current.clMax;
        }
        for (int i = 0; i < 4; i++) {
            short nextX = current.x + moveX[i];
            short nextY = current.y + moveY[i];
            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                int climb = max(0, vault[nextX][nextY]-vault[current.x][current.y]);
                int newClMax = max(current.clMax, climb);
                if (newClMax < height[nextX][nextY]) {
                    height[nextX][nextY] = newClMax;
                    p.push({nextX, nextY, newClMax});
                }
            }
        }
    }
    return -1;
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> vault(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vault[i][j];
        }
    }
    cout << bfs(vault, m, n) << endl;
    return 0;
}