#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        unordered_map<int, int> map;
        map[n] = 1;
        
        while(n != 1){
            
            int m = 0;
            for(;n>0;n/=10)  m += (n % 10) * (n %10);
            n = m;
            if(map[n]++) return false;
            
        }
        
        return true;
        
    }
};

int main(){
    
    int n;
    cin>>n;
    
    Solution *solution = new Solution();
    solution->isHappy(n) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
