/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://eclass.srv.ualberta.ca/pluginfile.php/10032871/mod_resource/content/3/phonelist.cpp
  https://eclass.srv.ualberta.ca/pluginfile.php/10488936/mod_resource/content/1/baza.cpp
  https://www.geeksforgeeks.org/trie-insert-and-search/
  https://www.tutorialspoint.com/cplusplus-program-to-implement-trie
  https://www.educba.com/trie-data-structure-c-plus-plus/
  https://www.digitalocean.com/community/tutorials/trie-data-structure-in-c-plus-plus

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

struct TrieNode {
    vector<TrieNode*> children;
    int count;
    TrieNode() : children(26), count(0) {}
};
void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c-'a']) {
            node->children[c-'a'] = new TrieNode();
        }
        node = node->children[c-'a'];
        node->count++;
    }
}
int search(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c - 'a']) {
            return 0;
        }
        node = node->children[c - 'a'];
    }
    return node->count;
}
int main() {
    int n;
    string word;
    cin >> n;
    TrieNode* root = new TrieNode();
    for (int i = 0; i < n; i++) {
        cin >> word;
        cout << search(root, word) << endl;
        insert(root, word);
    }
    return 0;
}