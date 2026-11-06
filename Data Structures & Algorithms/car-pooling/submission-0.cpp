class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        for(auto &trip : trips){
            int num = trip[0];
            int from = trip[1];
            int end = trip[2];
            diff[from] += num;
            diff[end] -= num;
        }

        int load = 0;
        for(int i = 0; i <= 1000; i++){
            load += diff[i];
            if(load > capacity) return false;
        }
        return true;
    }
};