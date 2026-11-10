class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while(r - l >= k){
            int r_dis = abs(arr[r] - x);
            int l_dis = abs(arr[l] - x);
            if(r_dis < l_dis){
                l++;
            }else{
                r--;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};