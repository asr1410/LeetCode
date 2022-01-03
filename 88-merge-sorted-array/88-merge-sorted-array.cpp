class Solution {
public:
    void merge(vector<int>& arr, int m, vector<int>& num, int n) {

        for(int i = 0; i < arr.size(); i++)
        {
            if(n != 0 and arr[i] == 0)
                arr[i] = num[--n];
        }
        sort(arr.begin(), arr.end());
    }
};