class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long l = 0, r = 1e14;
        while (l <= r)
        {
            long long m = (l + r) / 2, trips = 0;
            for (int t : time)
                trips += m / t;
            if (trips < totalTrips)
                l = m + 1;
            else
                r = m - 1;
            // cout << "left = " << l << " mid = " << m << " right = " << r << " trips = " << trips << endl;
        }
        return l;
    }
};