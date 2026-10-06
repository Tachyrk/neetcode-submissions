class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            if(square > x){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return right;
    }
};