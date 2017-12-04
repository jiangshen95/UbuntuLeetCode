#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> one;
        subsets(0, nums, one, result);
        
        return result;
    }
    
    void subsets(int end, vector<int>& nums, vector<int>& one, vector<vector<int> >& result){
        result.push_back(one);
        for(int i=end;i<nums.size();i++){
            one.push_back(nums[i]);
            subsets(i+1, nums, one, result);
            one.pop_back();
        }
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<int> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    
    vector<vector<int> > result;
    Solution *solution=new Solution();
    result=solution->subsets(nums);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
