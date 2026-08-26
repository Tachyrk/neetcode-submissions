class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        int remaingroups = n / groupSize;

        int maxValue = INT_MIN;
        int minValue = INT_MAX;
        int freq[1001] = {0};
        for(int i = 0; i < n; i++){
            freq[hand[i]]++;
            minValue = min(minValue, hand[i]);
            maxValue = max(maxValue, hand[i]);
        }

        for(int i = minValue; i <= maxValue; i++){
            if(freq[i] < 0){
                return false;
            }
            if(freq[i] > 0){
                for(int j = i + 1; j < i + groupSize; j++){
                    freq[j] -= freq[i];
                    if(freq[j] < 0){
                        return false;
                    }
                }
                freq[i] = 0;
            }
        }
        return true;
    }
};
