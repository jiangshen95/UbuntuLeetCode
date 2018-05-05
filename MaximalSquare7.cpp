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
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    int d = 1;
                    bool flag = true;
                    while(i + d < m && j + d < n && flag){
                        for(int k=j;k<=j+d;k++){
                            if(matrix[i+d][k] == '0'){
                                flag = false;
                                break;
                            }
                        }
                        for(int k=i;k<i+d;k++){
                            if(matrix[k][j+d] == '0'){
                                flag = false;
                                break;
                            }
                        }
                        if(flag){
                            d ++;
                        }
                    }
                    result = max(result, d * d);
                }
            }
        }
        
        return result;
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
