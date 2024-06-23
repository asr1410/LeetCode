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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        auto curr = head;
        while(curr) {
            curr = curr->next;
            len++;
        }
        n = len - n;
        if(n == 0) {
            return head->next;
        }
        curr = head;
        while(--n) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};