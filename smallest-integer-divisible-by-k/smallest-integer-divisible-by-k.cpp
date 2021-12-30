class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%10==0 or k%10==2 or k%10==4 or k%10==5 or k%10==6 or k%10==8)
            return -1;
        int num = 1;
        int len = 1;
        while(num % k != 0)
        {
            num = (num * 10 + 1)%k;
            len++;
        }
        return len;
    }
};