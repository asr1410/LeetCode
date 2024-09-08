class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        int nodes = 0;
        ListNode* curr = head;

        while (curr) {
            curr = curr->next;
            nodes++;
        }

        int limit = nodes / k;
        int extra = nodes % k;

        curr = head;
        for (int i = 0; i < k; ++i) {
            auto shead = curr;
            int climit = limit + (extra > 0 ? 1 : 0);

            for (int j = 1; j < climit && curr; ++j) {
                curr = curr->next;
            }

            if (curr) {
                auto temp = curr->next;
                curr->next = nullptr;
                curr = temp;
            }

            ans[i] = shead;

            if (extra > 0) {
                --extra;
            }
        }

        return ans;
    }
};
