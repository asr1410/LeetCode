class FT {
public:
    vector<int> bit;
    FT(int n) {
        bit.resize(n + 1, 0);
    }
    void update(int i, int val) {
        while(i < bit.size()) {
            bit[i] += val;
            i += i & -i;
        }
    }
    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> snums = nums;
        sort(snums.begin(), snums.end());
        unordered_map<int, int> ntoi;
        unordered_map<int, int> iton;
        int idx = 1;
        for(int i = 0; i < snums.size(); i++) {
            if(ntoi.find(snums[i]) == ntoi.end()) {
                ntoi[snums[i]] = idx;
                // cout << snums[i] << " " << idx << endl;
                iton[idx] = snums[i];
                idx++;
            }
        }
        idx--;
        vector<int> inums;
        for(int i = 0; i < nums.size(); i++) {
            inums.push_back(ntoi[nums[i]]);
        }
        FT ft1(idx), ft2(idx);
        vector<int> arr1, arr2;
        arr1.push_back(inums[0]);
        ft1.update(inums[0], 1);
        arr2.push_back(inums[1]);
        ft2.update(inums[1], 1);
        for(int i = 2; i < inums.size(); i++) {
            int r1 = arr1.size() - ft1.query(inums[i]);
            int r2 = arr2.size() - ft2.query(inums[i]);
            if(r1 > r2) {
                arr1.push_back(inums[i]);
                ft1.update(inums[i], 1);
            } else if(r1 < r2) {
                arr2.push_back(inums[i]);
                ft2.update(inums[i], 1);
            } else if(arr1.size() < arr2.size()) {
                arr1.push_back(inums[i]);
                ft1.update(inums[i], 1);
            } else if(arr1.size() > arr2.size()) {
                arr2.push_back(inums[i]);
                ft2.update(inums[i], 1);
            } else {
                arr1.push_back(inums[i]);
                ft1.update(inums[i], 1);
            }
        }
        vector<int> res;
        for(int i = 0; i < arr1.size(); i++) {
            res.push_back(iton[arr1[i]]);
        }
        for(int i = 0; i < arr2.size(); i++) {
            res.push_back(iton[arr2[i]]);
        }
        return res;
    }
};