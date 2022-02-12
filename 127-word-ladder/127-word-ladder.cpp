class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> store;
        bool present = false;
        for (auto &&word : wordList)
        {
            if (!endWord.compare(word))
                present = true;
            store.insert(word);
        }
        if (!present)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while (!q.empty())
        {
            depth += 1;
            int lsize = q.size();
            while (lsize--)
            {
                string curr = q.front();
                q.pop();
                for (int i = 0; i < curr.length(); i++)
                {
                    string temp = curr;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        if (!curr.compare(temp))
                            continue;
                        if (!temp.compare(endWord))
                            return depth + 1;
                        if (store.find(temp) != store.end())
                            q.push(temp), store.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};