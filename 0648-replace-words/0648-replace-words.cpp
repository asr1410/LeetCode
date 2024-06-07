#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    
    TrieNode() : isEnd(false) {}
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
            if(node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    string getShortestPrefix(const string& word) {
        TrieNode* node = root;
        string prefix;
        for(char c : word) {
            if(node->children.find(c) == node->children.end()) {
                return word; // No prefix found, return the original word
            }
            node = node->children[c];
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
