#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxcur=0;
        int maxprofit=0;
        
        for(int i=1;i<prices.size();i++){
            maxcur+=prices[i]-prices[i-1];
            if(maxcur<0) maxcur=0;
            maxprofit = maxcur>maxprofit?maxcur:maxprofit;
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
