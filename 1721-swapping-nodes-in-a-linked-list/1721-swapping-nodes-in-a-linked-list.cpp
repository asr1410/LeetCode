class Solution {
    int count = 0;
    ListNode *temp = nullptr;
    void recursion(ListNode *node, int k) {
        if (!node) {
            count = 0;
            return;
        }
        if (++count == k)
            temp = node;
        recursion(node->next, k);
        if (++count == k)
            swap(node->val, temp->val);
    }

public:
    ListNode *swapNodes(ListNode *head, int k) {
        recursion(head, k);
        return head;
    }
};