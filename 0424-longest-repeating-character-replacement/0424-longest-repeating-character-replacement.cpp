class Solution {
public:
int characterReplacement(string s, int k) {
    int ans = 0, n = s.size();
    for(char c = 'A'; c <= 'Z'; c++) { // Loop through each possible character 'A' to 'Z'
        int i = 0, t = k;
        for(int j = 0; j < n; j++) {
            t -= s[j] != c; // If s[j] is not equal to c, decrement t (number of replacements left)
            t += t < 0 and s[i++] != c; // If t becomes negative, increment i (move i to the right)
        }
        ans = max(ans, n - i); // Update ans to be the maximum length found
    }
    return ans;
}
};