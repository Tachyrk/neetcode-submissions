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
            if(p_max < 0) return false; //用來算
            p_min = max(p_min, 0); //防止 * 當 ) 用時 配對到更後面的 (
        }
        return p_min == 0; //選擇剛好把 ( 配完的世界線，沒用到的當空
    }
};
