class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> countMap;

        auto processSentence = [&](const string& sentence) {
            istringstream iss(sentence);
            string word;
            while (iss >> word) {
                countMap[word]++;
            }
        };

        processSentence(s1);
        processSentence(s2);

        vector<string> result;

        for (const auto& entry : countMap) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};