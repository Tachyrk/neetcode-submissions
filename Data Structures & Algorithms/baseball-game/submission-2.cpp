class Solution {
public:
    int calPoints(const vector<string>& operations) {
        vector<int> scores;
        scores.reserve(operations.size()); // 預先劃位，消除動態擴容開銷
        int total = 0;

        for (const auto& op : operations) {
            if (op == "+") {
                int n = scores.size();
                int new_score = scores[n - 1] + scores[n - 2];
                scores.push_back(new_score);
                total += new_score;
            } else if (op == "D") {
                int new_score = scores.back() * 2;
                scores.push_back(new_score);
                total += new_score;
            } else if (op == "C") {
                total -= scores.back();
                scores.pop_back();
            } else {
                int new_score = std::stoi(op);
                scores.push_back(new_score);
                total += new_score;
            }
        }

        return total; // 直接回傳即時累積的總和
    }
};