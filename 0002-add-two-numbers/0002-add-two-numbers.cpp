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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto ans = new ListNode();
        auto curr1 = l1, curr2 = l2, temp = ans;
        int carry = 0;
        while(curr1 and curr2) {
            int sum = curr1->val + curr2->val + carry;
            carry = sum / 10;
            auto newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1) {
            int sum = curr1->val + carry;
            carry = sum / 10;
            auto newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
            curr1 = curr1->next;
        }
        while(curr2) {
            int sum = curr2->val + carry;
            carry = sum / 10;
            auto newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
            curr2 = curr2->next;
        }
        if(carry) {
            auto newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return ans->next;
    }
};