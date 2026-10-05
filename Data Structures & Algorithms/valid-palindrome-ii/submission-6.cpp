class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int left_bound = 0;
        int right_bound = n - 1;
        while(left_bound < right_bound){
            if(s[left_bound] != s[right_bound]) break;    
            left_bound++;
            right_bound--;
        }
        if(left_bound >= right_bound) return true;
                
        //skip left
        int left = left_bound + 1, right = right_bound;
        while(left < right){
            if(s[left] != s[right]) break;   
            left++;
            right--;        
        }
        if(left >= right) return true;

        //skip right
        left = left_bound, right = right_bound - 1;
        while(left < right){
            if(s[left] != s[right]) break;   
            left++;
            right--;            
        }
        if(left >= right) return true;

        return false;
    }
};