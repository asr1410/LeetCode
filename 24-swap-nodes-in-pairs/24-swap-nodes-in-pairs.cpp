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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        ListNode* curr = head;
        ListNode* nex = head->next;
        while(nex and nex->next)
        {
            int temp = curr->val;
            curr->val = nex->val;
            nex->val = temp;
            curr = curr->next->next;
            nex = nex->next->next;
        }
        if(curr and nex)
        {
            int temp = curr->val;
            curr->val = nex->val;
            nex->val = temp;
        }
        return head;
    }
};