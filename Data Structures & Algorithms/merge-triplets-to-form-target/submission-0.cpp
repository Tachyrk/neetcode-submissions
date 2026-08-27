class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool findA = false, findB= false, findC = false;
        for(auto &triplet : triplets){
            if(triplet[0] == target[0] && !(triplet[1] > target[1] || triplet[2] > target[2])){
                findA = true;
            }
            if(triplet[1] == target[1] && !(triplet[0] > target[0] || triplet[2] > target[2])){
                findB = true;
            }
            if(triplet[2] == target[2] && !(triplet[0] > target[0] || triplet[1] > target[1])){
                findC = true;
            }
        }

        return findA && findB && findC;
    }
};
