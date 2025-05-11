class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> cnt(26, 0);
        for (const char& c : s) {
            cnt[c - 'a']++;
        }

        sort(cnt.begin(), cnt.end());

        int i = 0;
        while (i < 26 && cnt[i] == 0) i++;

        int remaining = 26 - i;
        if (k >= remaining) return 0;

        int toDelete = remaining - k;
        return accumulate(cnt.begin() + i, cnt.begin() + i + toDelete, 0);
    }
};
