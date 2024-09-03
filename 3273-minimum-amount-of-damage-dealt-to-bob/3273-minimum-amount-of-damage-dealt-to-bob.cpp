class Solution {
public:
        long long minDamage(int power, vector<int>& D, vector<int>& H) {
        vector<int> A(D.size());
        for (int i = 0; i < D.size(); ++i) {
            H[i] = (H[i] + power - 1) / power;
            A[i] = i;
        }
        sort(A.begin(), A.end(), [&](int i, int j) { 
            return H[i] * D[j] < H[j] * D[i];
        });

        long long res = 0, t = 0;
        for (int i : A) {
            res += D[i] * (t += H[i]);
        }
        return res;
    }
};