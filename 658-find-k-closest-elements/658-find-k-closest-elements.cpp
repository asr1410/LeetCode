class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		// arr is already sorted, k closest integers to x
		map<int, vector<int>> m;
    	for (int i = 0; i < arr.size(); ++i)
    	{	
    		m[abs(x-arr[i])].push_back(arr[i]);	
    	}
    	vector<int> ans;
    	for(auto x: m){
    		for(auto vx:x.second){
    			if(ans.size()<k){
    				ans.push_back(vx);
    			}
    		}
    	}
    	sort(ans.begin(), ans.end());
    	return ans;
    }
};
