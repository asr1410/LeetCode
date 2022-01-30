class Solution {
public:
    void rotate(vector<int>& vec2, int k) {
        
        std::rotate(vec2.begin(), vec2.begin()+vec2.size()-(k%vec2.size()), vec2.end());
    }
};