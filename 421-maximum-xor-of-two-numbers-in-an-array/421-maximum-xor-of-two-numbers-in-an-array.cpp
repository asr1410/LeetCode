struct Node
{
    Node* left;
    Node* right;
    Node() : left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int maxXOR = 0;
        Node* root = new Node();
        for(auto num: nums){
            Node* cur = root; // for building the trie
			Node* q = root; // for calculating current XOR
            int curXOR = 0;
            for(int h=31; h>=0; h--){ // inserting trie node from MSB for each num
                if((num & (1<<h))==0){
                    cur = cur->left ? cur->left : cur->left = new Node(); // inserting new node if not exists
                    curXOR |= q->right ? 1<<h : 0; // updating current XOR value
                    q = q->right ? q->right : q->left; 
                }
                else{
                    cur = cur->right ? cur->right : cur->right = new Node();
                    curXOR |= q->left ? 1<<h : 0;
                    q = q->left ? q->left : q->right;
                }
            }
            maxXOR = max(maxXOR,curXOR);
        }
        return maxXOR;
    }
};