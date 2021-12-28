class Solution {
public:
    vector<string> letterCasePermutation(string s1) {
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        vector<string> output;
        output.push_back(s1);
        int count = 1;
        for(int i = 0; i < s1.length(); i++)
        {
            if(isalpha(s1[i]))
            {
                add(toupper(s1[i]), i, count, output);
            }
        }
        return output;
    }
    void add(char n, int pos, int &count, vector<string>& output)
    {
        int i = 0;
        while(i<count)
        {
            string x = output[i];
            x[pos] = n;
            output.push_back(x);
            i++;
        }
        count += count;
    }
};