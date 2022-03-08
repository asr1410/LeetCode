class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if(!head or !head->next)
            return false;
        if(head == head->next)
            return true;
        auto slow = head;
        auto fast = head->next;
        while (fast->next and fast->next->next)
        {
            if (fast == slow)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};