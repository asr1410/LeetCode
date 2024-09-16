const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];

    TrieNode() {
        fill(begin(children), end(children), nullptr);
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }
};

class Solution {
public:
    int n;
    string target;
    vector<int> dp;

    int solve(int i, TrieNode* root) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        TrieNode* node = root;
        int res = 1e5;

        for (int j = i; j < n; ++j) {
            char c = target[j];
            int idx = c - 'a';
            if (node->children[idx] == nullptr) break;
            node = node->children[idx];
            int t = solve(j + 1, root);
            res = min(res, t + 1);
        }
        return dp[i] = res;
    }

    int minValidStrings(const vector<string>& words, const string& target) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }
        n = target.size();
        this->target = target;
        dp.resize(n, -1);

        int res = solve(0, trie.root);
        return res == 1e5 ? -1 : res;
    }
};
