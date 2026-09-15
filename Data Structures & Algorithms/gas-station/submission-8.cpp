class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        int current_gas = 0;
        int current_cost = 0;
        int ans = 0;
        int n = gas.size();
        for(int i = 0; i < n; i++){
            total_gas += gas[i];
            total_cost += cost[i];
            current_gas += gas[i];
            current_cost += cost[i];
            if(current_gas < current_cost){
                ans = i + 1;
                current_gas = 0;
                current_cost = 0;
            }
        }

        return (total_gas >= total_cost) ? ans : - 1;
    }
};
