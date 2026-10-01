class Solution {
public:
    int countSubstrings(string s) {
        int length = s.size();
        vector<vector<bool>> t(length,vector<bool>(length,false));
        int count =0;
        for(int L = 1; L<=length; L++){
            for(int i =0 ; i+L-1<length; i++){
                int j = i+L-1;
                if(L == 1){
                    t[i][j]=true;
                }else if(L==2){
                    t[i][j] = (s[i]==s[j]);
                }
                else {
                    t[i][j]= (s[i]==s[j] && t[i+1][j-1]==true);
                }
                if(t[i][j]==true) count++;
            }
        }
        return count;
    }
};
