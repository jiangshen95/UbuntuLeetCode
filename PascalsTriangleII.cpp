#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);
        
        for(int i=1;i<=rowIndex;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i;j++){
                temp.push_back(row[j]+row[j-1]);
            }
            temp.push_back(1);
            row=temp;
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
