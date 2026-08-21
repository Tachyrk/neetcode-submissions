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

        int ans = 1;
        int limit = 0; 
        for(int i = 1; i < n; i++){    
            long long spend1 = (long long)(sorted_array[i].second * (target - sorted_array[limit].first));
            long long spend2 = (long long)((target - sorted_array[i].first) * sorted_array[limit].second);
            if(spend1 < spend2){
                limit = i;
                ans++;
            }
        }
   
        return ans;
    }
};
