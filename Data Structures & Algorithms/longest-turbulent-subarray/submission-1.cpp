class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 0;
        int count = 1;
        int n = arr.size();
        if(n <= 1) return n;

        for(int i = 1; i < n; i++){
            if(i & 1 && arr[i] > arr[i - 1]){
                count++;
            }else if(!(i & 1) && arr[i] < arr[i - 1]){
                count++;
            }else{
                count = 1;
            }            
            ans = max(ans, count);
        }

        count = 1;
        for(int i = 1; i < n; i++){
            if(i & 1 && arr[i] < arr[i - 1]){
                count++;
            }else if(!(i & 1) && arr[i] > arr[i - 1]){
                count++;
            }else{
                count = 1;
            }            
            ans = max(ans, count);
        }

        return ans;
    }
};