#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, j=1;
        int color=0;
        while(i<nums.size()&&j<nums.size()){
            while(nums[i]==color){
                i++;
                j++;
            }
            if(i<nums.size()&&j<nums.size()){
                if(nums[j]<nums[i]){
                    swap(nums[i], nums[j]);
                }else{
                    j++;
                }
            }
            if(j>=nums.size()){
                j=i+1;
                color++;
            }
            print(nums);
            cin.get();
        }
    }
    
    void print(vector<int>& nums){
        for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
        cout<<endl;
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
