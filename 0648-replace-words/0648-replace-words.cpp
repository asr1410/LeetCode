#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
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
        for(char c : word) {
            if(node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    string getShortestPrefix(const string& word) {
        TrieNode* node = root;
        string prefix = "";
        for(char c : word) {
            if(node->children[c - 'a'] == nullptr) {
                return word; // No prefix found, return the original word
            }
            node = node->children[c - 'a'];
            prefix += c;
            if(node->isEnd) {
                return prefix; // Return the found prefix
            }
        }
        return word; // No prefix found, return the original word
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(const string& word : dictionary) {
            trie.insert(word);
        }
        
        stringstream ss(sentence);
        string word;
        string result;
        while(ss >> word) {
            if(!result.empty()) {
                result += " ";
            }
            result += trie.getShortestPrefix(word);
        }
        
        return result;
    }
};