#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Step 1: Create a set from the dictionary
        unordered_map<string, bool> prefixSet;
        for (const string& word : dictionary) {
            prefixSet[word] = true;
        }

        // Step 2: Split the sentence into words
        stringstream ss(sentence);
        string word;
        string result;
        
        while (ss >> word) {
            // Step 3: Find the shortest prefix for the current word
            string prefix;
            bool found = false;
            for (int i = 1; i <= word.size(); ++i) {
                prefix = word.substr(0, i);
                if (prefixSet.find(prefix) != prefixSet.end()) {
                    result += prefix;
                    found = true;
                    break;
                }
            }
            if (!found) {
                result += word;
            }
            result += " ";
        }
        
        // Remove the trailing space
        if (!result.empty()) {
            result.pop_back();
        }
        
        return result;
    }
};
