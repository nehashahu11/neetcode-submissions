class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen =0;
        int startIdx = 0;

        // centre based approach

        //odd len pall
        for(int i = 0 ; i < n ; i++) {
            int l = i, r = i;

            while(l >=0 && r <n && s[l]==s[r]){
                if(r-l+1 > maxLen){
                    startIdx = l;
                    maxLen = max(maxLen, r-l+1);
                }
                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    startIdx = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }

        }

        return s.substr(startIdx, maxLen);
    }
};