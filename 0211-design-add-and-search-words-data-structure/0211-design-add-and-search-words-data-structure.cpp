#include <string>
#include <algorithm>
using namespace std;

class Node {
public:
    Node* child[26];
    bool is_end = false;
    Node() {
        fill(begin(child), end(child), nullptr);
    }
};

class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            int t = word[i] - 'a';
            if (node->child[t] == nullptr) {
                node->child[t] = new Node();
            }
            node = node->child[t];
        }
        node->is_end = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

private:
    bool searchHelper(const string& word, int index, Node* node) {
        if (index == word.size()) {
            return node->is_end;
        }
        
        char currentChar = word[index];
        if (currentChar == '.') {
            for (Node* childNode : node->child) {
                if (childNode && searchHelper(word, index + 1, childNode)) {
                    return true;
                }
            }
            return false;
        } else {
            int t = currentChar - 'a';
            if (node->child[t] == nullptr) {
                return false;
            }
            return searchHelper(word, index + 1, node->child[t]);
        }
    }
};
