class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using T = tuple<long long, long long, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        for (int time : workerTimes) {
            minHeap.emplace(time, time, 1);
        }

        while (mountainHeight > 1) {
            auto [currentTime, workerTime, multiplier] = minHeap.top();
            minHeap.pop();
            long long newTime = currentTime + workerTime * (multiplier + 1);
            minHeap.emplace(newTime, workerTime, multiplier + 1);
            mountainHeight--;
        }

        return get<0>(minHeap.top());
    }
};
