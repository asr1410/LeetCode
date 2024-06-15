class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int, int>> p;
        
        int n = profits.size();
        
        for(int i = 0 ; i < n ; i++)    
            if(profits[i] > 0)
                p.push_back({capital[i],profits[i]}); // get all useful projects
            
            
        sort(p.begin() , p.end());
        
        priority_queue<int> pq;
            
        int ret = w;
        
        int cap = w;
        
        int j = 0;
            
        for(int i = 0 ; i < k ; i++){
            
            while(j < p.size() && p[j].first <= cap){ // get all profits possible with the avbl capital
                
                pq.push(p[j].second); //push the profit
                j++;
            }
             
            if(pq.size()){ 
                cap += pq.top(); // chooose best profit avbl
                pq.pop();
            }

         ret = max(ret, cap);
     
        }

        return ret;

    }
};