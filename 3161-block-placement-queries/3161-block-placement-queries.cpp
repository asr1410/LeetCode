constexpr int MaxX = 50001; // Maximum x-coordinate value

class SegTree
{
public:
    // Constructor initializes the segment tree with a given size
    SegTree(int _n)
    {
        n = _n;
        tree.resize(n * 4, 0); // Allocate memory for the segment tree (4 times the size of n for a complete binary tree)
    }

    // Get the maximum value in the range [0, x]
    int GetMax(int x) const
    {
        return GetRangeValueInternal(0, x, 1, 0, n - 1);
    }

    // Update the value at a specific index
    void UpdateValue(int index, int newValue)
    {
        UpdateValueInternal(index, newValue, 1, 0, n - 1);
    }

private:
    // Recursive function to get the maximum value in the range [left, right]
    int GetRangeValueInternal(int left, int right, int nodeIndex, int nodeRangeLeftIndex, int nodeRangeRightIndex) const
    {
        // No overlap
        if (left > right)
            return 0;

        // Total overlap
        if (left == nodeRangeLeftIndex && right == nodeRangeRightIndex)
            return tree[nodeIndex];

        // Partial overlap: divide the range into two halves and query both
        int rangeMid = (nodeRangeLeftIndex + nodeRangeRightIndex) / 2;
        int leftV = GetRangeValueInternal(left, min(right, rangeMid), nodeIndex * 2, nodeRangeLeftIndex, rangeMid);
        int rightV = GetRangeValueInternal(max(left, rangeMid + 1), right, nodeIndex * 2 + 1, rangeMid + 1, nodeRangeRightIndex);
        return max(leftV, rightV);
    }

    // Recursive function to update the value at a specific index
    void UpdateValueInternal(int index, int newValue, int nodeIndex, int nodeRangeLeftIndex, int nodeRangeRightIndex)
    {
        // Leaf node (single element range)
        if (nodeRangeLeftIndex == nodeRangeRightIndex)
        {
            tree[nodeIndex] = newValue;
            return;
        }

        // Non-leaf node: update the relevant child
        int mid = (nodeRangeLeftIndex + nodeRangeRightIndex) / 2;
        int leftChild = nodeIndex * 2;
        int rightChild = leftChild + 1;
        if (index <= mid)
        {
            UpdateValueInternal(index, newValue, leftChild, nodeRangeLeftIndex, mid);
        }
        else
        {
            UpdateValueInternal(index, newValue, rightChild, mid + 1, nodeRangeRightIndex);
        }
        // Update the current node based on its children
        tree[nodeIndex] = max(tree[leftChild], tree[rightChild]);
    }

    int n; // Size of the segment tree
    vector<int> tree; // Segment tree array
};

class Solution
{
public:
    // Function to process queries and return results
    vector<bool> getResults(vector<vector<int>>& queries)
    {
        SegTree seg(MaxX); // Initialize the segment tree
        set<int> obs;
        // Consider the maximum x-coordinate and 0 as existing obstacles
        obs.insert(0);
        obs.insert(MaxX);

        vector<bool> ans; // To store results of each query
        for (auto& q : queries)
        {
            int x = q[1];
            if (q[0] == 1)
            {
                // Query type 1: Insert an obstacle at x
                auto itr = obs.upper_bound(x); // Find the first obstacle greater than x
                int r = *itr; // Right boundary of the gap
                int l = *(--itr); // Left boundary of the gap
                obs.insert(x); // Insert x into the set of obstacles
                // Update the segment tree with new gaps created
                seg.UpdateValue(x, x - l);
                seg.UpdateValue(r, r - x);
            }
            else
            {
                int sz = q[2];
                // Query type 2: Check if there's a gap of size sz before x
                bool isValid = seg.GetMax(x) >= sz;
                // If no such gap is found, check the gap which x falls into
                if (!isValid)
                {
                    auto itr = obs.lower_bound(x);
                    if (*itr != x) // Ensure x is not already an obstacle
                    {
                        int l = *(--itr); // Find the left boundary of the gap containing x
                        isValid = (x - l) >= sz; // Check if the gap [l, x] is large enough
                    }
                }
                ans.push_back(isValid); // Store the result of this query
            }
        }

        return ans; // Return all results
    }
};
