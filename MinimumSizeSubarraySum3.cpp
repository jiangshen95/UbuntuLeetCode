#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        /*
         * 二分搜索 O(nlog(n))
         */
        if(nums.empty()) return 0;
        
        int minSub = -1;
        vector<int> sums(nums.size() + 1);
        sums[0] = 0;
        for(int i=0;i<nums.size();i++){
            sums[i + 1] = sums[i] + nums[i];
        }
        
        for(int i=1;i<=nums.size();i++){
            int to_find = s + sums[i - 1];
            int find = lower_bound(sums, to_find);
            if(find < sums.size() && sums[find] >= to_find){
                cout<<"find: "<<find<<endl;
                cout<<sums[find]<<endl;
                if(minSub == -1 || minSub > (find - i + 1))
                    minSub = find - i + 1;
            }
        }
        
        
        return minSub == -1 ? 0 : minSub;
        
    }
    
    int lower_bound(vector<int>& sums, int to_find){
        int l = 0, r = sums.size();
        while(l < r){
            int mid = (l + r) / 2;
            if(sums[mid] < to_find) l = mid + 1;
            else if(sums[mid] > to_find) r = mid;
            else return mid;
        }
        
        return l;
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
    
    int s;
    cin>>s;
    
    Solution *solution = new Solution();
    cout<<solution->minSubArrayLen(s, nums);
    
    return 0;
    
}

