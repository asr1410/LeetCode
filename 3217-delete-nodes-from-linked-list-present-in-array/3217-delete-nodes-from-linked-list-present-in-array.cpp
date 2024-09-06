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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> uset;
        for(int num : nums) uset.insert(num);
        while(head != nullptr and uset.find(head->val) != uset.end()) {
            auto temp = head;
            head = head->next;
            delete(temp);
        }
        if(head == nullptr or head->next == nullptr) return head;
        
        auto curr = head->next, prev = head;
        while(curr) {
            while(curr != nullptr and uset.find(curr->val) != uset.end()) {
                curr = curr->next;
            }
            prev->next = curr;
            prev = curr;
            if(curr != nullptr) {
                curr = curr->next;
            }
        }
        return head;
    }
};