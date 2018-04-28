#include<iostream>
#include<vector>

using namespace std;

//HeapSort 堆排序
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int heapsize = nums.size();
        buildMaxHeap(nums, heapsize);
        for(int i=0;i<k;i++){
            int temp = nums[0];
            nums[0] = nums[heapsize - 1];
            nums[heapsize - 1] = temp;
            heapsize --;
            maxHeapify(nums, 0, heapsize);
        }
        
        return nums[heapsize];
        
    }
    
    void maxHeapify(vector<int>& nums, int i, int heapsize){
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest;
        while(left < heapsize){
            if(nums[left] > nums[i]) largest = left;
            else largest = i;
            if(right < heapsize && nums[right] > nums[largest]) largest = right;
            if(largest != i){
                int temp = nums[i];
                nums[i] = nums[largest];
                nums[largest] = temp;
                i = largest;
                left = i * 2 + 1;
                right = i * 2 + 2;
            }else{
                break;
            }
        }
    }
    
    void buildMaxHeap(vector<int>& nums, int heapsize){
        for(int i=heapsize/2-1;i>=0;i--)
            maxHeapify(nums, i, heapsize);
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
    cout<<solution->findKthLargest(nums, k);
    
    return 0;
    
}
