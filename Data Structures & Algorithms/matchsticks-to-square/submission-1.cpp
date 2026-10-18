class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if(n < 4) return false;
        
        int total_length = 0;
        int max_stick = INT_MIN;
        for(int i = 0; i < n; i++){
            total_length += matchsticks[i];
            max_stick = max(max_stick, matchsticks[i]);
        }

        if(total_length % 4 != 0) return false;
        int target = total_length >> 2;
        if(target < max_stick) return false;

        sort(matchsticks.begin(), matchsticks.end());
        vector<bool> used(n, false);

        auto backtrack = [&](auto &self, int cnt, int current)->bool{
            if(cnt == 4) return true;
            for(int i = 0; i < n; i++){
                if(used[i] == false){
                    used[i] = true;
                    if(current + matchsticks[i] == target){
                        if(self(self, cnt + 1, 0)){
                            return true;
                        }
                    }else if(current + matchsticks[i] < target){
                        if(self(self, cnt , current + matchsticks[i])){
                            return true;
                        }
                    }
                    used[i] = false;
                    if(current + matchsticks[i] > target) break;
                }
            }
            return false;
        };

        return backtrack(backtrack, 0, 0);
    }
};