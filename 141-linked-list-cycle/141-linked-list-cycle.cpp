class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        auto walker = head;
        auto runner = head;
        while (runner && runner->next)
        {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner)
                return true;
        }
        return false;
    }
};