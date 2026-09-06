class Solution {
public:
    int getSum(int a, int b) {
        bitset<32> bits_a(a);
        bitset<32> bits_b(b);
        bitset<32> bits_result;
        int carry = 0;
        for(int i = 0; i < 32; i++){
            bits_result[i] = bits_a[i] ^ bits_b[i];
            bits_result[i] = bits_result[i] ^ carry;
            if((bits_a[i] || bits_b[i]) && carry){
                carry = 1;
            }else if (bits_a[i] && bits_b[i]){
                carry = 1;
            }else{
                carry = 0;
            }       
        }
        return (int) bits_result.to_ulong();
    }
};
