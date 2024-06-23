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
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        vector<int> temp;
        auto *curr = head;
        while(curr)
        {
            temp.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        sort(temp.begin(), temp.end());
        int i = 0;
        while(curr)
        {
            curr->val = temp[i++];
            curr = curr->next;
        }
        return head;
    }
};