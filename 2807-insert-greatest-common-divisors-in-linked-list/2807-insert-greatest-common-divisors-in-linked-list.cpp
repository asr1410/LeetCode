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
    int gcd(int a, int b) {
        if(a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto curr = head, next = head->next;
        while(next) {
            auto node = new ListNode(gcd(curr->val, next->val));
            curr->next = node;
            node->next = next;
            curr = curr->next->next;
            next = next->next;
        }
        return head;
    }
};