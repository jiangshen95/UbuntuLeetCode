#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int len=prices.size();
        vector<vector<int> > local(len, vector<int>(3, 0)), global(len, vector<int>(3, 0));
        /*int local[len][3], global[len][3];
        for(int i=0;i<len;i++){
            local[i][0]=0;
            global[i][0]=0;
        }
        for(int i=0;i<3;i++){
            local[0][i]=0;
            global[0][i]=0;
        }*/
        for(int i=1;i<len;i++){
            for(int j=1;j<3;j++){
                local[i][j]=max(global[i-1][j-1]+max(0, prices[i]-prices[i-1]), local[i-1][j]+prices[i]-prices[i-1]);
                global[i][j]=max(global[i-1][j], local[i][j]);
            }
        }
        
        return global[len-1][2];
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
