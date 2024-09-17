#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int count;
    
    TrieNode() : count(0) {
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
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->count++;
    }
    
    void collectUncommonWords(TrieNode* node, const string& prefix, vector<string>& result) {
        if (node == nullptr) return;
        if (node->count == 1) {
            result.push_back(prefix);
        }
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) {
                collectUncommonWords(node->children[i], prefix + char(i + 'a'), result);
            }
        }
    }
};

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        Trie trie;
        
        auto insertWords = [&](const string& sentence) {
            istringstream iss(sentence);
            string word;
            while (iss >> word) {
                trie.insert(word);
            }
        };
        
        insertWords(s1);
        insertWords(s2);
        
        vector<string> result;
        trie.collectUncommonWords(trie.root, "", result);
        return result;
    }
};
