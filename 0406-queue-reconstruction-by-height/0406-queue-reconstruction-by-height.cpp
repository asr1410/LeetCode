struct segmentTree{
    std::vector<int> tree;
    int N;
    int length;
    
    segmentTree(std::vector<int>& v){
        N = v.size();
        length = 4*N;
        tree.resize(length, INT_MIN);
        build(v, 1, 0, N-1);
    }
    
    void build(std::vector<int>& v, int x, int left, int right){
        if (left==right){
            tree[x] = v[left];
            return;
        }
        int mid = (left+right)/2;
        build(v, 2*x, left, mid);
        build(v, 2*x+1, mid+1, right);
        tree[x] = tree[2*x] + tree[2*x+1];
        return;
    }
    
    //update tree if v[index]=value
    void update(int x, int left, int right, int index, int value){
        if (left==right){
            tree[x] = value;
            return;
        }
        int mid = (left+right)/2;
        if (index>mid){
            update(2*x+1, mid+1, right, index, value);
        }else{
            update(2*x, left, mid, index, value);
        }
        tree[x] = tree[2*x] + tree[2*x+1];
        return;
    }
    
    //find the k-th available leaf node
    int find(int x, int left, int right, int k){
        if (left==right){
            return left;
        }
        
        int mid = (left+right)/2;
        if (k<=tree[2*x]){
            return find(2*x, left, mid, k);
        }else{
            return find(2*x+1, mid+1, right, k-tree[2*x]);
        }
    }    
};

class Solution {
public:
    static bool myCompare(std::vector<int>& u, std::vector<int>& v){
        if (u[0]<v[0]) return true;
        if (u[0]>v[0]) return false;
        
        if (u[1]>v[1]) return true;
        return false;
    }
    
    void printQ(std::vector<std::vector<int>>& q){
        for (int i=0; i<q.size(); i++)
            std::cout<<"("<<q[i][0]<<","<<q[i][1]<<"), ";
        std::cout<<std::endl;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        std::sort(people.begin(), people.end(), myCompare);
        std::vector<std::vector<int>> result(n, std::vector<int>{0,0});

        std::vector<int> v(n, 1);
        segmentTree sgTree = segmentTree(v); 
        int index;
        
        for (int i=0; i<n; i++){
            index = sgTree.find(1, 0, n-1, people[i][1]+1);    
            result[index][0] = people[i][0];
            result[index][1] = people[i][1];
            //update sgTree
            sgTree.update(1, 0, n-1, index, 0);
        }
        
        return result;
    }
};