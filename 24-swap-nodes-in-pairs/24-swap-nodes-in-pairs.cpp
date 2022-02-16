class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
            return head;
        ListNode *curr = head, *next = head->next;
        while (next and next->next)
        {
            int temp = curr->val;
            curr->val = next->val;
            next->val = temp;
            curr = curr->next->next;
            next = next->next->next;
        }
        if (curr and next)
        {
            int temp = curr->val;
            curr->val = next->val;
            next->val = temp;
        }
        return head;
    }
};