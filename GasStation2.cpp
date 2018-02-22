#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0, total=0, rest=0;
        for(int i=0;i<gas.size();i++){
            rest = rest+gas[i]-cost[i];
            if(rest<0){
                start=i+1;
                total+=rest;
                rest=0;
            }
        }
        return total+rest<0?-1:start;
        
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
