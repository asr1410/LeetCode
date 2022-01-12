class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size();
        int j = b.size();
        int carry = 0;
        string ans;
        while(i > 0 || j > 0)
        {
            int sum = carry;
            if(i > 0)
                sum += a[--i] - '0';
            if(j > 0)
                sum += b[--j] - '0';
            carry = sum > 1 ? 1 : 0;
            ans += to_string(sum%2);
        }
        if(carry)
            ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};