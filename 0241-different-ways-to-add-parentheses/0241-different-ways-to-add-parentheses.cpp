class Solution {
public:
    int perform(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }

    int helper(string exp) {
        for(int i = 0; i < exp.length(); i++) {
            if(!isdigit(exp[i])) {
                int left = helper(exp.substr(0, i));
                int right = helper(exp.substr(i + 1));
                return perform(left, right, exp[i]);
            }
        }
        return stoi(exp);
    }
    
    vector<int> diffWaysToCompute(string exp) {
        vector<int> results;
        bool isNumber = true;
        for(int i = 0; i < exp.length(); i++) {
            if(!isdigit(exp[i])) {
                isNumber = false;
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));
                for(int l : left) {
                    for(int r : right) {
                        results.push_back(perform(l, r, exp[i]));
                    }
                }
            }
        }
        
        if(isNumber) results.push_back(stoi(exp));
        return results;
    }
};