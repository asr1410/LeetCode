#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool check(int i, const int& num, const string& s, vector<string>& temp) {
        if (i == s.size()) {
            int sum = 0;
            for (const auto& t : temp) {
                sum += stoi(t);
            }
            return sum == num;
        }
        string t;
        for (int j = i; j < s.size(); j++) {
            t += s[j];
            temp.push_back(t);
            if (check(j + 1, num, s, temp)) {
                return true;
            }
            temp.pop_back();
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            vector<string> temp;
            if (check(0, i, to_string(sq), temp)) {
                ans += sq;
            }
        }
        return ans;
    }
};
