class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    int size;
    KthLargest(int k, vector<int> nums)
    {
        size = k;
        for (auto num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > size)
            pq.pop();
        return pq.top();
    }
};