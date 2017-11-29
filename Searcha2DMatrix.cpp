#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix[0].size();
        if(n==0) return false;
        
        int mid, middle;
        int l=0, r=m-1;
        while(l<=r){
            mid=(l+r)/2;
            if(matrix[mid].front()>target){
                r=mid-1;
            }else if(matrix[mid].back()<target){
                l=mid+1;
            }else{
                break;
            }
            cout<<"l: "<<l<<"---"<<"r: "<<r<<"---"<<"mid: "<<mid<<endl;
        }
        
        if(matrix[mid].front()>target || matrix[mid].back()<target){
            return false;
        }
        
        l=0;
        r=n-1;
        while(l<=r){
            middle=(l+r)/2;
            cout<<"l: "<<l<<"---"<<"r: "<<r<<"---"<<"middle: "<<middle<<endl;
            if(matrix[mid][middle]<target){
                l=middle+1;
            }else if(matrix[mid][middle]>target){
                r=middle-1;
            }else{
                break;
            }
        }
        
        return matrix[mid][middle]==target;
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    
    vector<vector<int> > matrix;
    for(int i=0;i<m;i++){
        vector<int> row;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            row.push_back(num);
        }
        matrix.push_back(row);
    }
    
    int target;
    cin>>target;
    
    Solution *solution=new Solution();
    if(solution->searchMatrix(matrix, target)){
        cout<<"True";
    }else cout<<"False";
    
    return 0;
}
