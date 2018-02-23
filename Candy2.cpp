#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int result=0;
        vector<int> left2right(ratings.size(), 1);
        vector<int> right2left(ratings.size(), 1);
        
        for(int i=0;i<ratings.size()-1;i++){
            if(ratings[i+1]>ratings[i]) left2right[i+1]=left2right[i]+1;
        }
        for(int i=ratings.size()-1;i>0;i--){
            if(ratings[i-1]>ratings[i]) right2left[i-1]=right2left[i]+1;
        }
        
        for(int i=0;i<ratings.size();i++) result+=max(left2right[i], right2left[i]);
        
        
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
