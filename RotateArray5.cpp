#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        k = k%n;
        
        int gcd = getGcd(n, k);
        
        for(int i=0;i<gcd;i++){
            int next = i;
            int count = n/gcd - 1;
            for(int j=0;j<count;j++){
                next = (next + k)%n;
                //交换
                nums[i] ^= nums[next];
                nums[next] ^= nums[i];
                nums[i] ^= nums[next];
            }
        }
        
        
    }
    
    int getGcd(int a, int b){
        return (a == 0 || b == 0) ? a + b : getGcd(b, a%b);
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
