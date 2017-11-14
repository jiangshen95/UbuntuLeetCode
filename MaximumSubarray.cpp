/*
 * DP 动态规划
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*int sum=nums[0];
        int max_item=nums[0];
        int max_sum=sum;
        int where_max=0;
        //int i=0,j=1;
        
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]>max_item){
                max_item=nums[i];
            }
            if(sum>max_sum){
                max_sum=sum;
                where_max=i;
            }
        }
        
        cout<<"where_max: "<<where_max<<endl;
        
        if(where_max==0){
            return max_item;
        }
        
        int min_sum=0;
        sum=0;
        for(int i=0;i<where_max;i++){
            sum+=nums[i];
            if(sum<min_sum) min_sum=sum;
        }
        
        return max_sum-min_sum;*/
        
        
        /*int i=0,j=1;
        int sum=nums[i];
        
        while(j<nums.size()){
            
            if(nums[j]<0){
                if(nums[j]>sum){
                    sum=nums[j];
                    i=j;
                }
                j++;
            }
            else{
                
                int the=0;
                for(int k=i+1;k<=j;k++){
                    the+=nums[k];
                }
                
                if(the<0){
                    if(nums[j]>sum){
                        sum=nums[j];
                        i=j;
                    }
                }else{
                    if(sum+the>nums[j]){
                        sum+=the;
                        i=j;
                    }else{
                        sum=nums[j];
                        i=j;
                    }
                }
                j++;
            }
        }
        
        return sum;*/
        
        int local=nums[0];
        int global=nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            local=nums[i]>local+nums[i] ? nums[i] : local+nums[i];
            global=local>global ? local : global;
            
            cout<<"local: "<<local<<"---"<<"global: "<<global<<endl;
            
        }
        
        return global;
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
    cout<<solution->maxSubArray(nums);
    
    return 0;
    
}
