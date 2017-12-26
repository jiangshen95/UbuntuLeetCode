#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> line;
        
        qsort(0, nums.size()-1, nums);
        
        subsetsWithDup(result, line, nums, 0);
        
        return result;
    }
    
    void qsort(int l, int r, vector<int>& nums){
        if(l<r){
            int i=l;
            int j=r;
            int v=nums[i];
            while(i<j){
                while(i<j&&nums[j]>=v) j--;
                nums[i]=nums[j];
                while(i<j&&nums[i]<=v) i++;
                nums[j]=nums[i];
            }
            nums[i]=v;
            qsort(l, i, nums);
            qsort(i+1, r, nums);
        }
    }
    
    void subsetsWithDup(vector<vector<int> >& result, vector<int>& line, vector<int>& nums, int cur){
        
        result.push_back(line);
        for(int i=cur;i<nums.size();i++){
            if(i==cur||i>cur&&nums[i]!=nums[i-1]){
                line.push_back(nums[i]);
                subsetsWithDup(result, line, nums, i+1);
                line.pop_back();
            }
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
    
    Solution *solution=new Solution();
    vector<vector<int> > result=solution->subsetsWithDup(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
