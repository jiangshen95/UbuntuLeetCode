#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        int slow, fast;
        slow = fast =n;
        while(slow != 1 && fast != 1){
            slow = getSquareSum(slow);
            fast = getSquareSum(fast);
            fast = getSquareSum(fast);
            if(slow == fast && slow !=1) return false;
        }
        return true;
        
    }
    
    int getSquareSum(int n){
        int m = 0;
        for(;n>0;n/=10)  m += (n % 10) * (n %10);
        return m;
    }
};

int main(){
    
    int n;
    cin>>n;
    
    Solution *solution = new Solution();
    solution->isHappy(n) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
