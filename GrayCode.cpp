#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> code;
        code.push_back(0);
        
        for(int i=0;i<n;i++){
            int len=code.size();
            for(int j=len-1;j>=0;j--){
                code.push_back(code[j]+twopower(i));
            }
        }
        
        return code;
        
    }
    
    int twopower(int n){
        int s=1;
        for(int i=0;i<n;i++) s*=2;
        return s;
    }
};

int main(){
    int n;
    cin>>n;
    
    Solution *solution=new Solution();
    vector<int> result=solution->grayCode(n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}
