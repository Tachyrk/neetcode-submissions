class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> st(n, 0);
        vector<int> ans;
        ans.reserve(n);

        int idx = 0;
        for(int asteroid : asteroids){
            if(asteroid > 0){
                st[idx++] = asteroid;
            }else{                
                while(idx > 0 && st[idx - 1] < -asteroid){
                    idx--;
                }
                if(idx > 0 && st[idx - 1] == -asteroid){
                    idx--;
                    continue;
                }else if(idx > 0 && st[idx - 1] > -asteroid){
                    continue;
                }else{
                    ans.push_back(asteroid);
                }
            }
        }

        for(int i = 0; i < idx; i++){
            ans.push_back(st[i]);
        }
        return ans;
    }
};