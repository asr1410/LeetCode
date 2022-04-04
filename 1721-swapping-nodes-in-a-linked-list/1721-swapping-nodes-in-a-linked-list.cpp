class Solution
{
    int last = 0, first = 0;
    ListNode *start = nullptr, *end = nullptr;
    void recursion(ListNode *node, int k)
    {
        if (!node or last == k)
            return;
        if (++first == k)
            start = node;
        recursion(node->next, k);
        if (++last == k)
            swap(start->val, node->val);
    }

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        recursion(head, k);
        cout << last;
        return head;
    }
};