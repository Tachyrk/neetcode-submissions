class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_cost = 0;
        int total_gas = 0;
        int accumulate = 0;
        int idx = -1;
        for(int i = 0; i < n; i++){
            total_gas += gas[i];
            total_cost += cost[i];
            accumulate += gas[i];
            accumulate -= cost[i];
            if(accumulate < 0){
                accumulate = 0;
                idx = -1;
            }else{
                if(idx == -1){
                    idx = i;
                }
            }
        }

        return total_gas >= total_cost ? idx : -1;
    }
};
