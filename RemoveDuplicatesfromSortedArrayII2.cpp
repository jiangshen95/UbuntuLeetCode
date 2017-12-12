#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int curr=0;
        int count=0;
        
        
        for(int i=1;i<nums.size();i++){
            if(nums[curr]==nums[i]){
                count++;
                if(count<=1) curr++;
            }else{
                curr++;
                count=0;
            }
            nums[curr]=nums[i];
            cout<<"curr: "<<curr<<endl;
            cout<<"count: "<<count<<endl;
            cout<<"num: "<<nums[i]<<endl;
        }
        
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        
        
        return curr+1;
        
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
    cout<<solution->removeDuplicates(nums);
    
    return 0;
}
