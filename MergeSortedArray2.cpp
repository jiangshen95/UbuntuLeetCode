#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r1=m-1, r2=n-1, r=m+n-1;
        while(r1>=0&&r2>=0){
            if(nums1[r1]>nums2[r2]) nums1[r--]=nums1[r1--];
            else nums1[r--]=nums2[r2--];
        }
        while(r2>=0){
            nums1[r--]=nums2[r2--];
        }
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    
    vector<int> nums1(m+n, 0);
    vector<int> nums2;
    
    for(int i=0;i<m;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums2.push_back(num);
    }
    
    Solution *solution=new Solution();
    solution->merge(nums1, m, nums2, n);
    
    for(int i=0;i<m+n;i++){
        cout<<nums1[i]<<" ";
    }
    
    return 0;
}
