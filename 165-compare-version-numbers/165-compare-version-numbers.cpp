class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0, len1 = version1.size(), len2 = version2.size(), num1 = 0, num2 = 0;
        while (i < len1 or j < len2)
        {
            while (i < len1 and version1[i] != '.')
            {
                num1 = 10 * num1 + (version1[i] - '0');
                i++;
            }
            while (j < len2 and version2[j] != '.')
            {
                num2 = 10 * num2 + (version2[j] - '0');
                j++;
            }
            if (num1 < num2)
                return -1;
            if (num1 > num2)
                return 1;
            num1 = 0;
            num2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};