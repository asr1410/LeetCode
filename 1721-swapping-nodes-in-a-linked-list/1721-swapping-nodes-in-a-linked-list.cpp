class Solution
{
    int size = 0, count = 0;
    ListNode *first = nullptr;
    ListNode *second = nullptr;
    void recursion(ListNode *node, int k)
    {
        if (!node)
            return;
        if (++count == k)
            first = node;
        recursion(node->next, k);
        if (++size == k)
            second = node;
    }

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        recursion(head, k);
        swap(first->val, second->val);
        return head;
    }
};