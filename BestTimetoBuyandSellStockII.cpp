#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*int sum=0;
        int cur=0;
        
        for(int i=0;i<prices.size();i++){
            if(i==0) cur=prices[i];
            else{
                if(prices[i]>cur){
                    sum+=prices[i]-cur;
                }
                cur=prices[i];
            }
        }
        
        return sum;*/
        int i=0;
        int valley=prices[0];
        int peak=prices[0];
        int maxprofit=0;
        while(i<prices.size()-1){
            while(i<prices.size()-1&&prices[i]>=prices[i+1]) i++;
            valley = prices[i];
            while(i<prices.size()-1&&prices[i]<=prices[i+1]) i++;
            peak = prices[i];
            maxprofit += peak-valley;
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
