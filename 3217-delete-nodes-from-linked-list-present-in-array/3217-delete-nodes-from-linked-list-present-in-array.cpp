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
        for(auto &num:nums) {
            uset.insert(num);
        }
        while(head != nullptr and uset.find(head->val) != uset.end()) {
            head = head->next;
        }
        if(head == nullptr) {
            return head;
        }
        auto prev = head;
        auto next = head->next;
        while(next) {
            if(uset.find(next->val) != uset.end()) {
                prev->next = next->next;
            } else {
                prev = prev->next;
            }
            next = next->next;
        }
        return head;
    }
};