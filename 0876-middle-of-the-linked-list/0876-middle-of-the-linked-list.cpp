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
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr) {
            return head;
        } else if(head->next->next == nullptr) {
            return head->next;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return fast->next == nullptr ? slow : slow->next;
    }
};