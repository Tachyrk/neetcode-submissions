class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int billleft[3] = {0};
        for(int bill : bills){
            if(bill == 5){
                billleft[0]++;
            }
            else if(bill == 10){
                if(!billleft[0]) return false;
                billleft[0]--;
                billleft[1]++;
            }else{
                if(billleft[1]){
                    billleft[1]--;
                    bill -= 10;
                }
                int fivebillneed = (bill / 5) - 1;
                if(billleft[0] >= fivebillneed){                    
                    billleft[0] -= fivebillneed;
                }else return false;
                billleft[2]++; //Never can be used;
            }
        }

        return true;
    }
};