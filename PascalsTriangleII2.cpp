#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 0);
        row[0]=1;
        
        for(int i=1;i<=rowIndex;i++){
            for(int j=i;j>=1;j--){
                row[j]+=row[j-1];
            }
        }
        
        return row;
    }
};

int main(){
    int rowIndex;
    cin>>rowIndex;
    
    Solution *solution=new Solution();
    vector<int> result=solution->getRow(rowIndex);
    
    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
    
    return 0;
}
