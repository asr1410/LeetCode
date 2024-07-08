class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mnh;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                mnh.push({ lists[i]->val, i });
            }
        }
        while (!mnh.empty()) {
            auto minNodeIdx = mnh.top().second;
            mnh.pop();
            if (head == nullptr) {
                head = lists[minNodeIdx];
                tail = head;
            } else {
                tail->next = lists[minNodeIdx];
                tail = tail->next;
            }
            lists[minNodeIdx] = lists[minNodeIdx]->next;
            if (lists[minNodeIdx]) {
                mnh.push({ lists[minNodeIdx]->val, minNodeIdx });
            }
        }
        return head;
    }
};
