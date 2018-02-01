#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-prices[i-1]>0) maxprofit+=prices[i]-prices[i-1];
        }
        return maxprofit;
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
