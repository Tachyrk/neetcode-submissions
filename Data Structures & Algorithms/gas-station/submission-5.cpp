class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_surplus = 0; // 記錄整趟旅程的總盈餘
        int current_gas = 0;   // 相當於你的 accumulate
        int start_idx = 0;     // 預設從第 0 站出發
        
        for(int i = 0; i < n; i++){
            int net_gas = gas[i] - cost[i];
            total_surplus += net_gas;
            current_gas += net_gas;
            
            // 如果走到當前這站破產了
            if(current_gas < 0){
                current_gas = 0;     // 油箱歸零
                start_idx = i + 1;   // 下一個候選起點直接設為 i + 1
            }
        }

        // 只要總盈餘大於等於 0，我們找到的 start_idx 就一定是對的答案
        return total_surplus >= 0 ? start_idx : -1;
    }
};