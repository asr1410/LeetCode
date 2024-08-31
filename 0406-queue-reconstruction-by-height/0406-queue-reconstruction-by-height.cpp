#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

struct segmentTree {
    std::vector<int> tree;
    int N;
    int length;

    segmentTree(std::vector<int>& v) {
        N = v.size();
        length = 4 * N;
        tree.resize(length, 0);  // Initialize with 0 since we're dealing with counts or sums
        build(v, 0, 0, N - 1);
    }

    void build(std::vector<int>& v, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = v[left];
            return;
        }
        int mid = (left + right) / 2;
        build(v, 2 * idx + 1, left, mid);
        build(v, 2 * idx + 2, mid + 1, right);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void update(int idx, int left, int right, int position, int value) {
        if (left == right) {
            tree[idx] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (position <= mid) {
            update(2 * idx + 1, left, mid, position, value);
        } else {
            update(2 * idx + 2, mid + 1, right, position, value);
        }
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    int find(int idx, int left, int right, int k) {
        if (left == right) {
            return left;
        }

        int mid = (left + right) / 2;
        if (k <= tree[2 * idx + 1]) {
            return find(2 * idx + 1, left, mid, k);
        } else {
            return find(2 * idx + 2, mid + 1, right, k - tree[2 * idx + 1]);
        }
    }
};

class Solution {
public:
    static bool myCompare(std::vector<int>& u, std::vector<int>& v) {
        if (u[0] < v[0]) return true;
        if (u[0] > v[0]) return false;

        return u[1] > v[1];
    }

    void printQ(std::vector<std::vector<int>>& q) {
        for (int i = 0; i < q.size(); i++)
            std::cout << "(" << q[i][0] << "," << q[i][1] << "), ";
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        int n = people.size();
        std::sort(people.begin(), people.end(), myCompare);
        std::vector<std::vector<int>> result(n, std::vector<int>{0, 0});

        std::vector<int> v(n, 1);
        segmentTree sgTree(v); 
        int index;

        for (int i = 0; i < n; i++) {
            index = sgTree.find(0, 0, n - 1, people[i][1] + 1);
            result[index][0] = people[i][0];
            result[index][1] = people[i][1];
            // Update segment tree
            sgTree.update(0, 0, n - 1, index, 0);
        }

        return result;
    }
};
