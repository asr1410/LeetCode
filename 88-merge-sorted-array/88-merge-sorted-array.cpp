class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0, j = 0;
        while (i < m and j < n)
        {
            if (nums1[i] > nums2[j])
            {
                swap(nums1[i++], nums2[0]);
            }
            else
            {
                i++;
            }
            sort(nums2.begin(), nums2.end());
        }
        for (int i = 0; i < n; i++)
        {
            nums1[m++] = nums2[i];
        }
    }
};
