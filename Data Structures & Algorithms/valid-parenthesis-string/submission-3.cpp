class Solution {
public:
    bool checkValidString(string s) {
        int p_max = 0, p_min = 0;
        for(char c : s){
            if(c == '('){
                p_max++;
                p_min++;
            }
            else if (c == ')'){
                p_max--;
                p_min--;
            }
            else{
                p_max++;
                p_min--;
            }
            if(p_max < 0) return false;
            p_min = max(p_min, 0);
        }
        return p_min == 0;
    }
};
