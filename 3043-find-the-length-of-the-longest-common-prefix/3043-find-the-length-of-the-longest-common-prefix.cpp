struct Node {
    Node* child[10] = {nullptr};
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node* node = root;
        for (char c : s) {
            int i = c - '0';
            if (node->child[i] == nullptr) {
                node->child[i] = new Node();
            }
            node = node->child[i];
        }
    }

    int query(string s) {
        Node* node = root;
        int ans = 0;
        for (char c : s) {
            int i = c - '0';
            if (node->child[i] == nullptr) {
                return ans;
            }
            ans++;
            node = node->child[i];
        }
        return ans;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for (int a : arr1) {
            t.insert(to_string(a));
        }
        int ans = 0;
        for (int a : arr2) {
            ans = max(ans, t.query(to_string(a)));
        }
        return ans;
    }
};
