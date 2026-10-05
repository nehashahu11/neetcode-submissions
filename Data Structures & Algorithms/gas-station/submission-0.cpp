class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumgas =0, sumcost =0;
        int currgas =0;
        int start =0;
        int n = gas.size();
        for(int i : gas){
            sumgas+= i;
        }
        for(int j : cost){
            sumcost+= j;
        }
        if(sumgas < sumcost){
            return -1;
        }
        for( int i =0; i< n; i++){
            currgas = currgas + gas[i] - cost[i];
            if(currgas < 0){
                start = i+1;
                currgas =0;
            }

        }
        return start;
    }
};
