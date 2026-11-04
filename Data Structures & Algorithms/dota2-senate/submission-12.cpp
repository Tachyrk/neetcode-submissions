class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> qr, qd;
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R') qr.push(i);
            else qd.push(i);
        }

        while(qr.size() && qd.size()){
            int R = qr.front(); qr.pop();
            int D = qd.front(); qd.pop();

            if(R > D) qd.push(D + n);
            else qr.push(R + n);
        }

        return (qr.size()) ? "Radiant" : "Dire";
    }
};