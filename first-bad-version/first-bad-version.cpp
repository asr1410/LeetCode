// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 0;
        while( lo <= n )
        {
            int mid = lo + (n - lo)/2;
            if(isBadVersion(mid))
                n = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;
    }
};