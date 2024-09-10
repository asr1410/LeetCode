class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr->next) {
            int g = gcd(curr->val, curr->next->val);
            ListNode* node = new ListNode(g);
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }
        
        return head;
    }
};
