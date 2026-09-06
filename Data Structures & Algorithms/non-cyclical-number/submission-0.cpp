class Solution {
public:
    bool isHappy(int n) {
        vector<int> visited(1001, 0);
        while(n){
            if(n == 1) return true;
            if(visited[n]) break;
            visited[n] = true;
            int temp = 0;
            while(n){
                int res = n % 10;
                temp += res * res;
                n /= 10;
            }
            n = temp;
        }
        return false;
    }
};
