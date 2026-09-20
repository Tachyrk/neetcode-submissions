class Solution {
public:
    int caldistance(string &a, string &b){
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) ans++;
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        unordered_map<string, vector<string>> neighbor;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(caldistance(wordList[i], wordList[j]) == 1){
                    neighbor[wordList[i]].push_back(wordList[j]);
                    neighbor[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        unordered_map<string, int> mp_idx;
        for(int i = 0; i < n; i++){
            mp_idx[wordList[i]] = i;
        }
        vector<int> distance(n, INT_MAX);
        distance[mp_idx[beginWord]] = 1;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push({1, beginWord});

        while(!pq.empty()){
            auto [step, word] = pq.top();
            pq.pop();
            if(distance[mp_idx[word]] < step) continue;
            if(word == endWord) return step;
            for(string & nextword : neighbor[word]){
                int nextidx = mp_idx[nextword];
                if(step + 1 < distance[nextidx]){
                    distance[nextidx] = step + 1;
                    pq.push({step + 1, nextword});
                }
            }
        }
        return 0;
    }
};
