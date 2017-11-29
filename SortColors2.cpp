#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int l=0, r=nums.size()-1;
        for(int i=l;i<=r;i++){
            if(nums[i]==0){
                swap(nums[i], nums[l]);
                l++;
            }else if(nums[i]==2){
                swap(nums[i], nums[r]);
                r--;
                i--;
            }
        }
    }
    
    void swap(int& a, int& b){
        int v=a;
        a=b;
        b=v;
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
    solution->sortColors(nums);
    
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";
    
    return 0;
}

