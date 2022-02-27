class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long left = 0, right = LONG_LONG_MAX / time.size();
        while (left < right)
        {
            long long mid = (left + right) / 2;
            long long mn = 0;
            for (int m : time)
                mn += mid / m;
            if (mn < totalTrips)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};