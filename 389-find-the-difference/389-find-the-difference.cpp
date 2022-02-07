class Solution {
public:
    char findTheDifference(string s, string t) {
        int x1=0,x2=0;
        for(int i=0;i<t.size();i++)
        {
            x1+=s[i]; x2+=t[i];
        }
        return char(x2-x1);
    }
};