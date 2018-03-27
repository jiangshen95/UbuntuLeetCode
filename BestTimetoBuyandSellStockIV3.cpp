#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int result = 0, p = 0, v;
        /*
         * priority_queue  优先队列，顶部为最大的数，也就是优先级最高的
         */
        priority_queue<int> profits;
        stack<pair<int, int> > vp_pairs;
        while(p < prices.size()){
            
            for(v=p;v<prices.size()-1 && prices[v]>=prices[v+1];v++);
            for(p=v+1;p<prices.size() && prices[p]>=prices[p-1];p++);
            
            while(!vp_pairs.empty() && prices[v]<prices[vp_pairs.top().first]){
                profits.push(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
                vp_pairs.pop();
            }
            
            while(!vp_pairs.empty() && prices[p-1] >= prices[vp_pairs.top().second - 1]){
                profits.push(prices[vp_pairs.top().second - 1] - prices[v]);
                v = vp_pairs.top().first;
                vp_pairs.pop();
            }
            
            vp_pairs.push(pair<int, int>(v, p));
            
        }
        
        while(!vp_pairs.empty()){
            profits.push(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
            vp_pairs.pop();
        }
        
        for(int i=0;i<k && !profits.empty();i++){
            result += profits.top();
            profits.pop();
        }
        
        return result;
        
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
