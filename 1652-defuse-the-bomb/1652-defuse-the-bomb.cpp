class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ncode;
        int n = code.size();
        vector<int> ans;
        for(int i = 0; i < 3; i++) {
            for(int c : code) {
                ncode.push_back(c);
            }
        }
        
        for(int i = code.size(); i < 2 * code.size(); i++) {
            int temp = 0;
            if(k < 0) {
                for(int j = i + k; j < i; j++) {
                    temp += ncode[j];
                }
                ans.push_back(temp);
            } else if(k > 0) {
                for(int j = i + 1; j <= i + k; j++) {
                    temp += ncode[j];
                }
                ans.push_back(temp);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};