class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1, s2;
        stringstream ss1(sentence1);
        string s;
        while(getline(ss1, s, ' '))
            s1.push_back(s);
        stringstream ss2(sentence2);
        while(getline(ss2, s, ' '))
            s2.push_back(s);
        int l1 = 0, r1 = s1.size() - 1, l2 = 0, r2 = s2.size() - 1;
        while(l1 <= r1 and l2 <= r2 and s1[l1] == s2[l2]) {
            l1++;
            l2++;
        }
        while(l1 <= r1 and l2 <= r2 and s1[r1] == s2[r2]) {
            r1--;
            r2--;
        }
        // cout << l1 << " " << r1 << endl;
        // cout << l2 << " " << r2 << endl;
        if(l1 > r1 or l2 > r2) {
            return true;
        }
        return false;
    }
};