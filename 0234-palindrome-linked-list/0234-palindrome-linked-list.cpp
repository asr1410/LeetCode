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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = NULL;
        while(head)
        {
            ListNode *p = head->next;
            head->next = curr;
            curr = head;
            head = p;
        }
        return curr;
    }
    bool isPalindrome(ListNode* head) {
        auto slow = head;
        auto fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != nullptr) slow = slow->next;
        slow = reverse(slow);
        while(slow) {
            if(slow->val != head->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};