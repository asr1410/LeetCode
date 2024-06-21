class Solution {
public:
    int maxSatisfied(vector<int>& cus, vector<int>& gru, int min) {
        int left = 0, right = 0, n = cus.size(), zcount = 0, count = 0, msum = 0, temp = 0;
        
        while (right < n) {
            while (right < n && count != min) {
                if (gru[right] == 1) {
                    temp += cus[right];
                }
                zcount += gru[right];
                count++;
                
                if (zcount && temp > msum) {
                    msum = temp;
                }
                right++;
            }
            
            zcount -= gru[left];
            if (gru[left] == 1) {
                temp -= cus[left];
            }
            left++;
            count--;
        }
        
        for (int i = 0; i < n; i++) {
            if (gru[i] == 0) {
                msum += cus[i];
            }
        }
        
        return msum;
    }
};