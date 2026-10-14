class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        ans.reserve(n);
        
        for(int asteroid : asteroids){
            if(asteroid > 0){
                ans.push_back(asteroid);
            }else{                
                if(ans.size() > 0 && ans.back() > 0){
                    while(ans.size() > 0 && ans.back() > 0 &&ans.back() < -asteroid){
                        ans.pop_back();
                    }
                    if(ans.size() > 0 && ans.back() == -asteroid){
                        ans.pop_back();
                        continue;
                    }else if(ans.size() > 0 && ans.back() > -asteroid){
                        continue;
                    }else{
                        ans.push_back(asteroid);
                    }
                }else{
                    ans.push_back(asteroid);
                }                
            }
        }
        return ans;
    }
};