class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;  
        long long temp = n - 1;     
        for(int i = 0; i < 32; i++){
            if((temp >> i) & 1){               
                int zero_cnt = 0;
                for(int j = 0; j < 64; j++){
                    if(((long long)x >> j) & 1){
                        continue;
                    }else{
                        if(zero_cnt == i){
                            ans |= (1LL << j);
                            break;
                        }
                        zero_cnt++;
                    }
                }
            }
        }
        return ans;
    }
};