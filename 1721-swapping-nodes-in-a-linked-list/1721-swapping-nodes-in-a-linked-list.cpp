class Solution
{
    int last = 0, first = 0;
    ListNode *start = nullptr, *end = nullptr;
    void recursion(ListNode *node, int k)
    {
        if (!node)
            return;
        if (++first == k)
            start = node;
        recursion(node->next, k);
        if (++last == k)
            end = node;
    }

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        recursion(head, k);
        swap(start->val, end->val);
        cout << last;
        return head;
    }
};