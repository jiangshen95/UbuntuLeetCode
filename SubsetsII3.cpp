#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result(1);
        
        qsort(0, nums.size()-1, nums);
        
        int size=0;
        
        for(int i=0;i<nums.size();){
            int count=0;
            while(count+i<nums.size()&&nums[count+i]==nums[i]) count++;
            size=result.size();
            for(int j=0;j<size;j++){
                vector<int> temp=result[j];
                for(int k=0;k<count;k++){
                    temp.push_back(nums[i]);
                    result.push_back(temp);
                }
            }
            i+=count;
        }
        
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
