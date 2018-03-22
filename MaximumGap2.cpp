#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int a = nums[0], b = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<a) a = nums[i];
            if(nums[i]>b) b = nums[i];
        }
        
        if(a == b) return 0;
        
        int cell_len = (b-a)/(nums.size()-1) + ((b-a)%(nums.size()-1)==0 ? 0 : 1);
        int cells = (b-a)/cell_len + 1;
        cout<<"a, b: "<<a<<" "<<b<<endl;
        cout<<"cell_len: "<<(b-a)/(nums.size()-1)<<endl;
        cout<<"cells: "<<cells<<endl;
        vector<vector<int> > buckets(cells, vector<int>(2, -1));
        for(int i=0;i<nums.size();i++){
            int locate = (nums[i]-a)/cell_len;
            if(buckets[locate][0]==-1 && buckets[locate][1]==-1){
                buckets[locate][0] = nums[i];
                buckets[locate][1] = nums[i];
            }else{
                buckets[locate][0] = min(buckets[locate][0], nums[i]);
                buckets[locate][1] = max(buckets[locate][1], nums[i]);
            }
        }
        int maxdif = 0;
        int i=0;
        while(i<cells){
            if(buckets[i][0]==-1) i++;
            else{
                int j;
                for(j=i+1;j<cells;j++){
                    if(buckets[j][0] != -1) break;
                }
                if(j<cells) maxdif = max(maxdif, buckets[j][0]-buckets[i][1]);
                i = j;
            }
        }
        
        return maxdif;
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
    cout<<solution->maximumGap(nums);
    
    return 0;
    
}
