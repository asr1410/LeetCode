class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxf = 0;
        vector<int> freq(26);
        for(auto &task:tasks) {
            maxf = max(maxf, ++freq[task - 'A']);
        }
        int time = (maxf - 1) * (n + 1);
        for(auto f:freq) {
            time += maxf == f;
        }
        return max((int)tasks.size(), time);
    }
};