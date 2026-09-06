class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        vector<int> arr(m + n, 0);        
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                int idx = (m - 1 - i) + (n - 1 - j);
                arr[idx] += (n1 * n2);               
            }
        }
        
        for(int i = 0; i < m + n - 1; i++){
            if(arr[i] >= 10){
                arr[i + 1] += arr[i] / 10;
                arr[i] %= 10;
            }
        }
        

        string ans;
        bool find_first = true;
        for(int i = m + n - 1; i >= 0; i--){
            if(find_first && arr[i] == 0){
                continue;
            }else{
                find_first = false;
                ans.push_back(arr[i] + '0');
            }
        }       

        return ans;    
    }
};
