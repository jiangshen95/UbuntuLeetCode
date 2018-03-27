#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        
        if(k > prices.size()) return maxProfit(prices);
        
        vector<int> global(k+1, 0), local(k+1, 0);
        
        for(int i=1;i<prices.size();i++){
            for(int j=k;j>=1;j--){
                local[j] = max(global[j-1] + max(0, prices[i] - prices[i-1]), local[j] + prices[i] - prices[i-1]);
                global[j] = max(global[j], local[j]);
            }
        }
        
        return global[k];
    }
    
    int maxProfit(vector<int>& prices){
        
        int maxprofit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i] > prices[i-1]) maxprofit += prices[i] - prices[i-1];
        }
        
        return maxprofit;
        
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<int> prices;
    for(int i=0;i<n;i++){
        int price;
        cin>>price;
        prices.push_back(price);
    }
    
    int k;
    cin>>k;
    
    Solution *solution = new Solution();
    cout<<solution->maxProfit(k, prices);
    
    return 0;
}
