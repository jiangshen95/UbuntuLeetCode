#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int maxshell;
        
        for(int i=prices.size()-1;i>=0;i--){
            if(i==prices.size()-1){
                maxshell=prices[i];
            }else{
                if(maxshell<prices[i]) maxshell=prices[i];
                if(maxshell-prices[i]>maxprofit) maxprofit=maxshell-prices[i];
            }
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
