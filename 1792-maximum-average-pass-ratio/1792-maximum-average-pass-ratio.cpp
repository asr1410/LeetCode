class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double total = 0;
        priority_queue<pair<double, array<int, 2>>> pq;

        for (auto &c : classes) {
            double pass = c[0], totalStudents = c[1];
            total += pass / totalStudents;
            double profit = (pass + 1) / (totalStudents + 1) - pass / totalStudents;
            pq.push({profit, {c[0], c[1]}});
        }

        while (extraStudents--) {
            auto topElement = pq.top();
            pq.pop();

            double addedProfit = topElement.first;
            int pass = topElement.second[0];
            int totalStudents = topElement.second[1];

            total += addedProfit;
            double newProfit = ((double)pass + 2) / (totalStudents + 2) - ((double)pass + 1) / (totalStudents + 1);
            pq.push({newProfit, {pass + 1, totalStudents + 1}});
        }

        return total / classes.size();
    }
};