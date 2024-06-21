class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unrealized = 0;
        for (int i = 0; i < minutes; i++) {
            unrealized += customers[i] * grumpy[i];
        }
        int maxUnrealized = unrealized;
        for (int i = minutes; i < n; i++) {
            unrealized += customers[i] * grumpy[i];
            unrealized -= customers[i - minutes] * grumpy[i - minutes];
            maxUnrealized = max(maxUnrealized, unrealized);
        }
        int totalCustomers = maxUnrealized;
        for (int i = 0; i < n; i++) {
            totalCustomers += customers[i] * (1 - grumpy[i]);
        }
        return totalCustomers;
    }
};