class Solution {
public:
    bool isAnagram(string s, string t) {
       if (s.size() != t.size()) return false;
       unordered_map<char,int> mps;
       unordered_map<char,int> mpt;
       int i = 0;
       int n = s.size();
       int m = t.size();
       for(i =0; i <n; i++){
        mps[s[i]] = 0;
       } 
       for(i =0; i <n; i++){
        mps[s[i]] = mps[s[i]] +1;
       }
       for(i =0; i <m; i++){
        mpt[t[i]] = 0;
       } 
       for(i =0; i <m; i++){
        mpt[t[i]] = mpt[t[i]] +1;
       }
       if (mps == mpt)
        return true;
       else return false;
    }
};
