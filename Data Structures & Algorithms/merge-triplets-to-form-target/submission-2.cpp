class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool findA = false, findB= false, findC = false;
        for(auto &triplet : triplets){
            if(triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]){
                continue;
            }
            if(triplet[0] == target[0]){
                findA = true;
            }
            if(triplet[1] == target[1]){
                findB = true;
            }
            if(triplet[2] == target[2]){
                findC = true;
            }
            if(findA && findB && findC) return true;
        }

        return false;
    }
};
