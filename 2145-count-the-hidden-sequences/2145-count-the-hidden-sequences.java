class Solution {
    public int findLeft(int l, int h, int min, int max){
        int res = 1000000;
        int lower = l;
        int upper = h;
        while(l <= h){
            int mid = l + (h-l)/2;
            if( mid + min >= lower && mid + max <= upper){
                res = mid;
                h = mid-1;
            }
            else if( mid+min < lower){
                l = mid+1;
            }
            else
                h = mid-1;
        }

        return res;
    }

    public int findRight(int l, int h, int min, int max){
        int res = 1000000;
        int lower = l;
        int upper = h;
        while(l <= h){
            int mid = l + (h-l)/2;
            if( mid + min >= lower && mid + max <= upper){
                res = mid;
                l = mid+1;
            }
            else if( mid+min < lower){
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }

    public int numberOfArrays(int[] differences, int lower, int upper) {
        int n = differences.length;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        int sum = 0;

        for(int i : differences){
            sum += i;
            min = Math.min(min, sum);
            max = Math.max(max, sum);
        }

        int left = findLeft(lower, upper, min, max);
        int right = findRight(lower, upper, min, max);

        if( left == 1000000 || right == 1000000)
            return 0;

        return right-left+1;
    }
}