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
        if(head == nullptr) {
            return head;
        }
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        while(head) {
            pq.push({head->val, head});
            head = head->next;
        }
        head = pq.top().second;
        pq.pop();
        auto curr = head;
        while(pq.size()) {
            curr->next = pq.top().second;
            pq.pop();
            curr = curr->next;
        }
        curr->next = nullptr;
        return head;
    }
};