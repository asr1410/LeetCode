#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Node {
public:
    Node* child[26];
    Node() {
        fill(begin(child), end(child), nullptr);
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(const string& s) {
        auto node = root;
        for(char c : s) {
            int i = c - 'a';
            if(node->child[i] == nullptr) {
                node->child[i] = new Node();
            }
            node = node->child[i];
        }
    }
};

class Solution {
public:
    int helper(int i, int n, Node* root, const string& s, vector<int>& dp) {
        if(i == n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        
        auto node = root;
        int ans = INT_MAX;
        
        for(int j = i; j < n; j++) {
            int t = s[j] - 'a';
            if(node->child[t] == nullptr) {
                break;
            }
            node = node->child[t];
            int result = helper(j + 1, n, root, s, dp);
            if(result != INT_MAX) {
                ans = min(ans, 1 + result);
            }
        }
        dp[i] = ans;
        return dp[i];
    }

    int minValidStrings(const vector<string>& words, const string& target) {
        int n = target.size();
        Trie trie;
        for(const auto& word : words) {
            trie.insert(word);
        }
        vector<int> dp(n, -1);
        int ans = helper(0, n, trie.root, target, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
