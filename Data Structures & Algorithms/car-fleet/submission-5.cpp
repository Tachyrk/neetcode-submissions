class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> sorted_array(n);
        for(int i = 0; i < n; i++){
            sorted_array[i] = {position[i], speed[i]};
        }
        sort(sorted_array.begin(), sorted_array.end(), [](const auto a, const auto b){
            return a.first > b.first;
        });

        int ans = 0;
        double limit = 0.0;
        for(int i = 0; i < n; i++){
            double travel_time = (double)(target - sorted_array[i].first) / sorted_array[i].second;
            if(travel_time > limit){
                limit = travel_time;
                ans++;
            }
        }
   
        return ans;
    }
};
