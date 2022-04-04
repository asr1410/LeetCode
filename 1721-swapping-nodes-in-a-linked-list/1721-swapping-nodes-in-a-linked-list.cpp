class Solution
{
    int last = 0, first = 0;
    ListNode *start = nullptr;
    ListNode *end = nullptr;
    void recursion(ListNode *node, int k)
    {
        if (!node)
            return;
        if (++first == k)
            start = node;
        recursion(node->next, k);
        if (++last == k){
            end = node;
            exit;
        }
    }

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        recursion(head, k);
        swap(start->val, end->val);
        return head;
    }
};