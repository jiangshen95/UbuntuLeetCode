#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int rest = 0;
        int subsum = 1000000000;
        
        for(int i=0;i<gas.size();i++){
            rest += gas[i]-cost[i];
            if(rest<subsum){
                subsum = rest;
                start = i+1;
            }
        }
        
        return rest>=0?start%(gas.size()):-1;
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<int> gas;
    vector<int> cost;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        gas.push_back(num);
    }
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        cost.push_back(num);
    }
    
    Solution *solution=new Solution();
    cout<<solution->canCompleteCircuit(gas, cost);
    
    return 0;
}
