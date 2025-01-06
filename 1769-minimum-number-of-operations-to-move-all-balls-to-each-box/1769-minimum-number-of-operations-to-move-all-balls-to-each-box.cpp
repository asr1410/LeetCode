class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> pre(n), pos(n);
        for(int i = 1, cnt = boxes[0] - '0'; i < n; i++) {
            pre[i] = cnt;
            cnt += boxes[i] == '1';
        }
        for(int i = n - 2, cnt = boxes[n - 1] - '0'; i >= 0; i--) {
            pos[i] = cnt;
            cnt += boxes[i] == '1';
        }
        for(int i = 1; i < n; i++) {
            pre[i] += pre[i - 1];
        }
        for(int i = n - 2; i >= 0; i--) {
            pos[i] += pos[i + 1];
        }
        for(int i = 0; i < n; i++) {
            pre[i] += pos[i];
        }
        return pre;
    }
};