class Solution {
public:
    int getSum(int a, int b) {
        /*bitset<32> bits_a(a);
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
        return (int) bits_result.to_ulong();*/

        // 當還有進位存在時，持續將進位加回
        while (b != 0) {
            // 在 C++ 中，負數進行左移可能觸發未定義行為 (UB)
            // 轉成 unsigned int 運算可保證二進位位移是良定義的
            unsigned int carry = (unsigned int)(a & b) << 1;
            
            a = a ^ b;      // 不考慮進位的加法結果
            b = carry;      // 將進位作為新的加數
        }
        return a;
    }
};
