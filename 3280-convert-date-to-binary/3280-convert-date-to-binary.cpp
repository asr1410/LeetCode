class Solution {
public:
    string convertDateToBinary(string date) {
        stringstream ss(date);
        string temp;
        string ans;
        while(getline(ss, temp, '-')) {
            int num = stoi(temp);
            string sub;
            while(num) {
                sub += num & 1 ? '1' : '0';
                num >>= 1;
            }
            reverse(sub.begin(), sub.end());
            ans += sub;
            ans.push_back('-');
        }
        ans.pop_back();
        return ans;
    }
};