#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=gas.size()-1;
        int end=0;
        int rest = gas[start]-cost[start];
        while(start>end){
            if(rest>=0){
                rest += gas[end]-cost[end];
                end++;
            }else{
                start--;
                rest += gas[start]-cost[start];
            }
        }
        return rest>=0?start:-1;
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
