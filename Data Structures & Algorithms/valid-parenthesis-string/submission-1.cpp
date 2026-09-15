class Solution {
public:
    bool checkValidString(string s) {
        int quota_cnt = 0;
        int left_parenthesis_cnt = 0;
        int valid_quota_cnt = 0;
        for(char c : s){
            if(c == '('){
                left_parenthesis_cnt++;
            }else if (c == ')'){
                if(left_parenthesis_cnt){
                    left_parenthesis_cnt--;
                }else if(quota_cnt){
                    quota_cnt--;
                }else{
                    return false;
                }
            }else{
                quota_cnt++;
                valid_quota_cnt++;
                if(valid_quota_cnt > left_parenthesis_cnt){
                    valid_quota_cnt = left_parenthesis_cnt;
                }
            }
        }

        return valid_quota_cnt >= left_parenthesis_cnt;
    }
};
