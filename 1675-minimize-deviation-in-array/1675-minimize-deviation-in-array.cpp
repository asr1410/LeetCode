class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        int mn = INT_MAX;
        int diff = INT_MAX;
        priority_queue<int> pq;
        for (auto num : nums)
        {
            if (num % 2)
                num *= 2;
            mn = min(mn, num);
            pq.push(num);
        }
        while (pq.top() % 2 == 0)
        {
            int mx = pq.top();
            pq.pop();
            diff = min(diff, mx - mn);
            mn = min(mx / 2, mn);
            pq.push(mx / 2);
        }
        return min(diff, pq.top() - mn);
    }
};