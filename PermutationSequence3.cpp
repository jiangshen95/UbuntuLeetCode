#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        
        string result="";
        string nums="";
        
        for(int i=1;i<=n;i++) nums+=i+'0';
        
        int non=1;
        for(int i=1;i<n;i++) non*=i;
        
        int m=n-1;
        
        while(m>0){
            int i=(k-1)/non;
            
            result+=nums[i];
            nums.erase(i,1);
            
            cout<<"nums: "<<nums<<endl;
            
            k-=i*non;
            
            non/=m;
            m--;
        }
        
        result.append(nums);
        
        return result;
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    
    string result;
    Solution *solution=new Solution();
    result=solution->getPermutation(n, k);
    cout<<result;
    
    return 0;
}
