#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m+n-1;i>=n;i--){
            nums1[i]=nums1[i-n];
        }
        
        int l1=n, l2=0, l=0;
        while(l1<m+n&&l2<n){
            if(nums1[l1]>nums2[l2]) nums1[l++]=nums2[l2++];
            else nums1[l++]=nums1[l1++];
        }
        while(l2<n){
            nums1[l++]=nums2[l2++];
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
