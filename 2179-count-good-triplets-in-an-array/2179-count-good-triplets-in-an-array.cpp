class Fenwick {
public:
    vector<long long> tree;
    Fenwick(int n) {
        tree.assign(n + 1, 0);
    }
    
    void update(int k, int x) {
        while(k < tree.size()) {
            tree[k] += x;
            k += k & -k;
        }
    }
    
    long long query(int k) {
        long long total = 0;
        k++;
        while(k > 0) {
            total += tree[k];
            k -= k & -k;
        }
        return total;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size(), total = 0;
        vector<int> mpp(n, 0);
        for(int i = 0; i < n; i++) mpp[nums1[i]] = i;
        
        Fenwick fw(n);
        
        for(int i : nums2) {
            int idx = mpp[i];
            long long left = fw.query(idx);
            long long sum = fw.query(n - 1);
            long long right = (n - (idx + 1)) - (sum - left);
            total += left * right;
            fw.update(idx + 1, 1);
        }
        return total;
    }
};