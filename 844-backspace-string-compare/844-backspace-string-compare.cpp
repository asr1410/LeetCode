class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        int i = S.length() - 1, j = T.length() - 1, skipS = 0, skipT = 0;
        while (i >= 0 or j >= 0)
        {
            while (i >= 0)
            {
                if (S[i] == '#')
                {
                    skipS++;
                    i--;
                }
                else if (skipS > 0)
                {
                    skipS--;
                    i--;
                }
                else
                    break;
            }
            while (j >= 0)
            {
                if (T[j] == '#')
                {
                    skipT++;
                    j--;
                }
                else if (skipT > 0)
                {
                    skipT--;
                    j--;
                }
                else
                    break;
            }
            if (i >= 0 and j >= 0 and S[i] != T[j])
                return false;
            if ((i >= 0) != (j >= 0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};