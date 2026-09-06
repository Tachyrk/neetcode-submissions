class Solution {
public:
    double myPow(double x, int n) {
        //注意符號轉換溢位問題
        long long N = n; // 用 long long 避開 INT_MIN 溢位
        int sign = (N < 0);
        double res = 1.0;
        if(sign) N *= -1;
        while(N){
            if(N & 1) res *= x;
            x *= x;
            N >>= 1;
        }
        return sign ? (double)1 / res : res;
    }
};
