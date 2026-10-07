class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx1 = 0, idx2 = 0;
        int n1 = word1.size(), n2 = word2.size();
        string ans;
        ans.reserve(n1 + n2);

        while(idx1 < n1 || idx2 < n2){
            if(idx1 < n1){
                ans.push_back(word1[idx1++]);
            }   
            if(idx2 < n2){
                ans.push_back(word2[idx2++]);
            }   
        }

        return ans;
    }
};