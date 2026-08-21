class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> sorted_array(n);
        for(int i = 0; i < n; i++){
            sorted_array[i] = {position[i], speed[i]};
        }
        sort(sorted_array.begin(), sorted_array.end());
        vector<double> st(n);
        int index = 0;
        for(int i = 0; i < n; i++){
            double travel_time = (double)(target - sorted_array[i].first) / sorted_array[i].second;
            while(index > 0 && st[index - 1] <= travel_time){
                index--;
            }
            st[index++] = travel_time;
        }
        return index;
    }
};
