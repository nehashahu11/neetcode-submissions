class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l= 0; int r =1;
        int profit=0;int maxp=0;
        while(r<n){
            if(prices[l]<prices[r]){
                profit= prices[r]-prices[l];
                maxp=max(profit,maxp);

            }
            else l =r;
            r++;
        }
    return maxp;    
    }
};
