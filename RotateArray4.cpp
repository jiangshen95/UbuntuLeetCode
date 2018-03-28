#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        k %= n;
        
        int count = 0;
        
        for(int i=0;count<n;i++){
            int current = i;
            int pre = nums[i];
            
            do {
                int next = (current + k)%n;
                int temp = nums[next];
                nums[next] = pre;
                pre = temp;
                current = next;
                count ++;
            }while(i != current);
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
    
    int k;
    cin>>k;
    
    Solution *solution = new Solution();
    solution->rotate(nums, k);
    
    for(int i=0;i<n;i++) cout<<nums[i]<<"  ";
    
    return 0;
    
}
