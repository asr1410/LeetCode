

class Solution
{
    unordered_map<Node *, Node *> mp;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        if (mp.find(node) == mp.end())
        {
            mp[node] = new Node(node->val);
            for (auto &&adj : node->neighbors)
            {
                mp[node]->neighbors.push_back(cloneGraph(adj));
            }
        }
        return mp[node];
    }
};