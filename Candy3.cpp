#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int result=0;
        
        vector<int> candies(ratings.size(), 1);
        
        for(int i=0;i<ratings.size()-1;i++){
            if(ratings[i+1]>ratings[i]) candies[i+1]=candies[i]+1;
        }
        
        result+=candies.back();
        
        for(int i=ratings.size()-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                candies[i-1]=max(candies[i]+1, candies[i-1]);
            }
            result+=candies[i-1];
        }
        
        return result;
    }
};

int main(){
    
    int n;
    cin>>n;
    
    vector<int> ratings;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        ratings.push_back(num);
    }
    
    Solution solution=Solution();
    cout<<solution.candy(ratings);
    
    return 0;
    
}
