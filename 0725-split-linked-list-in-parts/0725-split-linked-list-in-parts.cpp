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

        int partSize = nodes / k;
        int extraNodes = nodes % k;

        curr = head;
        for (int i = 0; i < k; ++i) {
            ListNode* partHead = curr;
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);

            for (int j = 1; j < currentPartSize && curr; ++j) {
                curr = curr->next;
            }

            if (curr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }

            ans[i] = partHead;

            if (extraNodes > 0) {
                --extraNodes;
            }
        }

        return ans;
    }
};
