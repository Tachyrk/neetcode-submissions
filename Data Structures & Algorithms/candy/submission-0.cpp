class Solution {
public:
    int candy(vector<int>& ratings) {
        int peak = 1;
        int downcnt = 0;
        int risecnt = 1;
        int ans = 1;
        int n = ratings.size();
        for(int i = 1; i < n; i++){
            if(ratings[i] == ratings[i - 1]){
                downcnt  = 0;
                peak = 1;
                risecnt = 1;
                ans += 1;
            }else if(ratings[i] > ratings[i - 1]){
                risecnt++;
                downcnt = 0;
                peak = risecnt;
                ans += risecnt;
            }else{
                risecnt = 1;
                downcnt++;
                ans += downcnt;
                if(downcnt >= peak) ans+= 1;
            }
        }

        return ans;
    }
};