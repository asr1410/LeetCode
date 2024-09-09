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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int rs = 0, re = m - 1, cs = 0, ce = n - 1;
        while(head != nullptr and rs <= re and cs <= ce) {
            int t = cs;
            while(head != nullptr and t <= ce) {
                mat[rs][t] = head->val;
                head = head->next;
                t++;
            }
            rs++;
            t = rs;
            while(head != nullptr and t <= re) {
                mat[t][ce] = head->val;
                head = head->next;
                t++;
            }
            ce--;
            t = ce;
            while(head != nullptr and t >= cs) {
                mat[re][t] = head->val;
                head = head->next;
                t--;
            }
            re--;
            t = re;
            while(head != nullptr and t >= rs) {
                mat[t][cs] = head->val;
                head = head->next;
                t--;
            }
            cs++;
        }
        return mat;
    }
};