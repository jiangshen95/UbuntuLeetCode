#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return x;
        int left=1, right=x, result;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mid<=x/mid){
                left=mid+1;
                result=mid;
            }else{
                right=mid-1;
            }
        }
        
        return result;
    }
};

int main(){
    int x;
    cin>>x;
    
    Solution *solution=new Solution();
    cout<<solution->mySqrt(x);
    
    return 0;
}

