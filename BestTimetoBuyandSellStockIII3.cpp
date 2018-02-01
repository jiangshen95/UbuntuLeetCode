#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1=-100000, hold2=-100000;
        int release1=0, release2=0;
        for(int i=0;i<prices.size();i++){
            release2 = max(release2, hold2+prices[i]);
            hold2 = max(hold2, release1-prices[i]);
            release1 = max(release1, hold1+prices[i]);
            hold1 = max(hold1, -prices[i]);
        }
        return release2;
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
