class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> mpp = new HashMap<Character, Integer>();
        
        int left = 0, len = 0;
        for (int right = 0; right < s.length(); right++)
        {
            if(mpp.containsKey(s.charAt(right)))
                left = Math.max(mpp.get(s.charAt(right)) + 1, left);
                
            mpp.put(s.charAt(right), right);
            len = Math.max(len, right - left + 1);
        }
        return len;
    }
}