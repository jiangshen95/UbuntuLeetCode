/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        
        for(int i=0;i<n;i++){
            
            int rest=0, j;
            for(j=0;j<n;j++){
                int k=(i+j)%n;
                rest = rest+gas[k]-cost[k];
                if(rest<0) break;
            }
            if(j==n) return i;
            
            /*int rest=0;
            int j=i;
            while(rest>=0){
                rest = rest+gas[j]-cost[j];
                j = (j+1)%n;
                if(j==i&&rest>=0){
                    return i;
                }
            }*/
            
        }
        
        return -1;
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
