typedef pair<int, ListNode*> PIL;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<PIL, vector<PIL>, greater<PIL>> minHeap;
        for (auto list : lists) {
            if (list) minHeap.push({list->val, list});
        }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (minHeap.empty() == false) {
            auto smallest = minHeap.top();
            minHeap.pop();
            ListNode* newNode = smallest.second;
            if (!head) {
                head = newNode;
                tail = head;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
            if (newNode->next) {
                minHeap.push({newNode->next->val, newNode->next});
            }
        }
        return head;
    }
};
