class Solution {
public:
    bool isPalindrome(int x) {
        int check = x;
        if(x < 0 ) return false;

        long long num = 0;

        while(x){
            long long lastdigit = x % 10;
            num = num * 10 + lastdigit;
            x = x/10;
        }

        return num == check;
    }
};