class Solution {
  public: int takeCharacters(string s, int k) {
    int ca = 0, cb = 0, cc = 0;
    int n = s.size();
    int ans = n;
    for (int i = 0; i < n; i++) {
        ca += s[i] == 'a';
        cb += s[i] == 'b';
        cc += s[i] == 'c';
    }
    if (ca < k || cb < k || cc < k) return -1;
    int i = n - 1, j = n - 1;
    while (i >= 0) {
        ca -= s[i] == 'a';
        cb -= s[i] == 'b';
        cc -= s[i] == 'c';
      while (ca < k || cb < k || cc < k) {
        ca += s[j] == 'a';
        cb += s[j] == 'b';
        cc += s[j] == 'c';
        j--;
      }
      ans = min(ans, i + n - 1 - j);
      i--;
    }
    return ans;
  }
};