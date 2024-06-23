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
// 1 3 5
// 2 4 nullptr
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr or head->next == nullptr) {
            return head;
        }
        auto odd = head;
        auto even = head->next;
        auto next = even;
        while(even and even->next) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = next;
        return head;
    }
};