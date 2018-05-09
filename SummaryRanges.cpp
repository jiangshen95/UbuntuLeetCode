#include<iostream>
#include<vector>
#include<string>
#include<limits.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int i = 0;
        vector<string> result;
        string range = "";
        while(i < nums.size()){
            range += numtostr(nums[i]);
            int begin = nums[i];
            while(i + 1 < nums.size() && nums[i+1] == nums[i] + 1){
                i ++;
            }
            if(nums[i] > begin){
                range += "->" + numtostr(nums[i]);
            }
            result.push_back(range);
            range = "";
            i ++;
        }
        
        return result;
    }
    
    string numtostr(int num) {
        if(num == 0) return "0";
        if(num == INT_MIN) return "-2147483648";
        bool sign = true;
        if(num < 0){
            num = -num;
            sign = false;
        }
        string s = "";
        while(num > 0){
            s = (char)(num % 10 + '0') + s;
            num /= 10;
        }
        if(!sign) s = '-' + s;
        return s;
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
    
    Solution *solution = new Solution();
    vector<string> result = solution->summaryRanges(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    
    return 0;
    
}
