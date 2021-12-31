class Solution {
public:
    vector<int> minOperations(string box) {
        vector<int> ans;
        int len = box.length();
        for(int i = 0; i < len; i++)
        {
            int count = 0;
            for(int j = 0; j < len; j++)
            {
                if(box[j] == '1')
                    count += abs(i - j);
            }
            ans.push_back(count);
        }
        return ans;
    }
};