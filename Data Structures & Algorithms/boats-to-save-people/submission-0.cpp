class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), [](const int a, const int b){
            return a > b;
        });

        int ans = 0;
        int n = people.size();
        int l = 0, r = n - 1;
        while(l <= r){
            if(people[l] + people[r] <= limit){
                l++;
                r--;
            }else{
                l++;
            }
            ans++;
        }

        return ans;
    }
};