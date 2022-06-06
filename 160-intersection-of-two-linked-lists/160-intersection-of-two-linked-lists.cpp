class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        auto a = headA, b = headB;
        while (a or b)
        {
            if (!a)
                a = headB;
            if (!b)
                b = headA;
            if (a == b)
                return a;
            a = a->next;
            b = b->next;
        }
        return NULL;
    }
};