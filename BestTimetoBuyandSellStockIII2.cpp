#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int len=prices.size();
        vector<int> local(3, 0), global(3, 0);
        for(int i=1;i<len;i++){
            for(int j=2;j>=1;j--){
                local[j]=max(global[j-1]+max(0, prices[i]-prices[i-1]), local[j]+prices[i]-prices[i-1]);
                global[j]=max(global[j], local[j]);
            }
        }
        
        return global[2];
    }
    
    int max(int a, int b){
        return a>b?a:b;
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<int> prices;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        prices.push_back(num);
    }
    
    Solution *solution=new Solution();
    cout<<solution->maxProfit(prices);
    
    return 0;
}
