class Solution
{
    int count = 0;
    ListNode *start = nullptr;
    void recursion(ListNode *node, int k)
    {
        if (!node)
        {
            count = 0;
            return;
        }
        if (++count == k)
            start = node;
        recursion(node->next, k);
        if (++count == k)
            swap(node->val, start->val);
    }

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        recursion(head, k);
        return head;
    }
};