class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n-1;
        int maxarea=0;
        int area= 0 ;
        while(i<j){
            int height = min(heights[i],heights[j]);
            int width = j-i;
            area = height*width;
            maxarea= max(area,maxarea);
            if(heights[i]<=heights[j]) i++;
            else j--;
        }
    return maxarea;    
    }
};
