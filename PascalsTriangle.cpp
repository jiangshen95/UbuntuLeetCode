#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if(numRows<=0) return result;
        result.push_back(vector<int>(1,1));
        for(int i=1;i<numRows;i++){
            vector<int> row;
            row.push_back(1);
            for(int j=1;j<i;j++){
                row.push_back(result[i-1][j]+result[i-1][j-1]);
            }
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};

int main(){
    int numRows;
    cin>>numRows;
    
    Solution *solution=new Solution();
    vector<vector<int> > result=solution->generate(numRows);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
