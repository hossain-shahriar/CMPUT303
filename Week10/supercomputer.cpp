/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://cp-algorithms.com/data_structures/segment_tree.html
  https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/

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

void build(vector<int>& tree, const vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(tree, arr, 2 * node, start, mid);
        build(tree, arr, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
void update(vector<int>& tree, int node, int start, int end, int index) {
    if (start == end) {
        tree[node] = 1 - tree[node];
    } else {
        int mid = (start + end) / 2;
        if (start <= index && index <= mid) {
            update(tree, 2 * node, start, mid, index);
        } else {
            update(tree, 2 * node + 1, mid + 1, end, index);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
int query(const vector<int>& tree, int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(tree, 2 * node, start, mid, l, r);
    int p2 = query(tree, 2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}
int main() {
    int a, b, n, k;
    char t;
    cin >> n >> k;
    vector<int> arr(n, 0), tree(4 * n);
    build(tree, arr, 1, 0, n - 1);
    for (int i = 0; i < k; i++) {
        cin >> t;
        if (t == 'F') {
            cin >> a;
            update(tree, 1, 0, n - 1, a - 1);
        } else if (t == 'C') {
            cin >> a >> b;
            cout << query(tree, 1, 0, n - 1, a - 1, b - 1) << endl;
        }
    }
    return 0;
}