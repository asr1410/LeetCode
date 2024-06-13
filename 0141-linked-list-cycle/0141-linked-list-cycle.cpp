class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
