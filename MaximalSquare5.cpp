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
        vector<int> dp(n, 0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j == 0 || i == 0){
                    pre = dp[j];
                    dp[j] = matrix[i][j] - '0';
                }
                else{
                    int t = dp[j];
                    if(matrix[i][j] == '0') dp[j] = 0;
                    else{
                        dp[j] = min(pre, min(dp[j], dp[j-1])) + 1;
                    }
                    pre = t;
                }
                result = max(result, dp[j]);
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
