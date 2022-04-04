class Solution
{
    int size = 0, count = 0;
    ListNode *first = NULL;
    ListNode *second = NULL;
    void recursion(ListNode *node, int k)
    {
        if (!node)
            return;
        count++;
        if (count == k)
            first = node;
        recursion(node->next, k);
        size++;
        if (size == k)
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