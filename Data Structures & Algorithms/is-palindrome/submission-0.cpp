class Solution {
public:
    bool isPalindrome(string s) {
        string p = "";
        int n = s.size();
        for(int c =0; c<n; c++){
            if(isalnum(s[c])){
                p += tolower((s[c]));
            }
        cout << p;    
        
        }
        int m = p.size();
        int mid =0;
        mid = m/2;
        for(int i =0; i<mid; i++){
            if(p[i]!=p[m-1-i]) return false;
        }
        return true;
    }
};
