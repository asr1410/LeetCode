class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!k or !head)
            return head;
        int size = 0;
        auto curr = head;
        while (curr->next)
        {
            size++;
            curr = curr->next;
        }
        size++;
        k = k % size;
        if (!k)
            return head;
        k = size - k;
        curr->next = head;
        curr = head;
        while (k--)
        {
            if (k == 0)
            {
                head = curr->next;
                curr->next = nullptr;
            }
            curr = curr->next;
        }
        return head;
    }
};