#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        
        int result = 0;
        int pre = 0;
        vector<int> dp(m + 1, 0);
        
        for(int j=0;j<n;j++){
            for(int i=1;i<=m;i++){
                int t = dp[i];
                if(matrix[i-1][j] == '0') dp[i] = 0;
                else{
                    dp[i] = min(pre, min(dp[i], dp[i-1])) + 1;
                }
                pre = t;
                result = max(result, dp[i]);
            }
        }
        
        return result * result;
    }
};

int main(){
    
    int m, n;
    cin>>m>>n;
    
    vector<vector<char> > matrix;
    for(int i=0;i<m;i++){
        vector<char> raw;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            raw.push_back(ch);
        }
        matrix.push_back(raw);
    }
    
    Solution *solution = new Solution();
    cout<<solution->maximalSquare(matrix);
    
    return 0;
}
