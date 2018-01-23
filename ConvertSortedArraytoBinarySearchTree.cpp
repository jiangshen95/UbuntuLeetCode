#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.empty()) return NULL;
        
        return sortedArrayToBST(nums, 0, nums.size()-1);
        
        
    }
    
    TreeNode *sortedArrayToBST(vector<int>& nums, int begin, int end){
        
        if(begin>end) return NULL;
        
        int mid=(begin+end)/2+(begin+end)%2;
        
        TreeNode *root=new TreeNode(nums[mid]);
        
        root->left=sortedArrayToBST(nums, begin, mid-1);
        root->right=sortedArrayToBST(nums, mid+1, end);
        
        return root;
        
    }
    
    void printTree(TreeNode *root){
        if(root!=NULL){
            cout<<root->val<<" ";
            printTree(root->left);
            printTree(root->right);
            cout<<endl;
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
    
    Solution *solution=new Solution();
    TreeNode *root=solution->sortedArrayToBST(nums);
    solution->printTree(root);
    
    return 0;
    
}
