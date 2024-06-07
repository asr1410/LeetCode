class Node {
    public:
    Node* children[26];
    bool isEnd;
    Node() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
    public:
    Node* root;
    Trie() {
        root = new Node;
    }
    void insert(string& word) {
        Node* node = root;
        for(char c:word) {
            if(node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new Node();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    string find(string& word) {
        Node* node = root;
        string prefix = "";
        for(char c:word) {
            if(node->children[c - 'a'] == nullptr) {
                return word;
            }
            node = node->children[c - 'a'];
            prefix += c;
            if(node->isEnd) {
                return prefix;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(string& word:dictionary) {
            trie.insert(word);
        }
        stringstream ss(sentence);
        string word;
        string result;
        while(ss >> word) {
            if(!result.empty()) {
                result += " ";
            }
            result += trie.find(word);
        }
        return result;
    }
};