class Solution {
public:
    string reverseWords(string s) {
        int j;
        int n = s.length() - 1;
        for(int i = 0; i < n; i++)
        {
            j = i;
            while(j < n && s[j] != ' ')
            {
                j++;
            }
            int left = i;
            int right;
            if(j == n)
                right = j;
            else
                right = j - 1;
            while(left <  right)
                swap(s[left++], s[right--]);
            i = j;
        }
        return s;
    }
};