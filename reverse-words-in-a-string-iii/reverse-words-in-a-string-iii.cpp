class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0; i < s.size(); i++)
        {
            int k = i;
            while(s[k] != ' ' && k < s.size())
                k++;
            cout << i << " " <<k << endl;
            reverse(s.begin()+i, s.begin()+k);
            i = k;
        }
        return s;
    }
};