class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (char c : s1) {
            mp1[c]++;
        }
        for (int i = 0; i < n1; i++) {
            mp2[s2[i]]++;
        }
        int l = 0;
        int m = n1 - 1;
        while (m < n2) {
            if (mp1 == mp2)
                return true;
            else {
                mp2[s2[l]]--;
                if (mp2[s2[l]] == 0) mp2.erase(s2[l]);
                l++;
                m++;
                mp2[s2[m]]++;
            }
        }
    return false;    
    }
};
