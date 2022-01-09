/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        if(!head->next)
            return head;
        ListNode* curr = head;
        ListNode* prev;
        while(curr)
        {
            while(curr->next && curr->val == curr->next->val)
                curr->next = curr->next->next;
                curr = curr->next;
        }
        return head;
    }
};