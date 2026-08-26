class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[hand[i]]++;            
        }

        for(auto [key, value] : freq){
            if(value > 0){
                for(int j = key + 1; j < key + groupSize; j++){
                    freq[j] -= value;
                    if(freq[j] < 0){
                        return false;
                    }
                }          
            }     
        }
        return true;
    }
};
