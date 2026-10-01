class Solution {
public:
    int tribonacci(int n) {
        long long T0 = 0, T1 = 1, T2 = 1;
        if(n < 3) return (n == 0) ? 0 : 1;
        for(int i = 3; i <= n; i++){
            long long temp = T0 + T1 + T2;
            T0 = T1;
            T1 = T2;
            T2 = temp;
        }
        return T2;
    }
};