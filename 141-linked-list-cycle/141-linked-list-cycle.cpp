/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *curr = head;
        ListNode *after = head;
        while(after->next && after->next->next)
        {
            curr = curr->next;
            after = after->next->next;
            if(curr == after)
                return true;
        }
        return false;
    }
};