#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> pcount(26);
        for(auto task : tasks) {
            pcount[task - 'A']++;
        }
        
        vector<pair<int, int>> temp;
        for(int i = 0; i < 26; i++) {
            if(pcount[i] > 0) {
                temp.push_back({pcount[i], i});
            }
        }
        sort(temp.begin(), temp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; // Sort by frequency descending
        });
        
        priority_queue<pair<int, int>> pq;
        for(auto& t : temp) {
            pq.push(t);
        }
        
        int time = 0;
        while(!pq.empty()) {
            vector<pair<int, int>> current;
            int k = n + 1;
            
            for(int i = 0; i < k; i++) {
                if(!pq.empty()) {
                    auto task = pq.top();
                    pq.pop();
                    if(task.first > 1) {
                        current.push_back({task.first - 1, task.second});
                    }
                }
                time++;
                if(pq.empty() && current.empty()) {
                    break;
                }
            }
            
            for(auto& task : current) {
                pq.push(task);
            }
        }
        
        return time;
    }
};