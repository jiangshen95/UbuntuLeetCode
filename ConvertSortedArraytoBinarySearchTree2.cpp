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
        
        vector<TreeNode*> nodeStack;
        vector<int> leftIndexStack;
        vector<int> rightIndexStack;
        
        TreeNode *head=new TreeNode(0);
        
        nodeStack.push_back(head);
        leftIndexStack.push_back(0);
        rightIndexStack.push_back(nums.size()-1);
        
        while(!nodeStack.empty()){
            TreeNode *curNode=nodeStack.back();
            nodeStack.pop_back();
            int left=leftIndexStack.back();
            leftIndexStack.pop_back();
            int right=rightIndexStack.back();
            rightIndexStack.pop_back();
            int mid=(left+right)/2+(left+right)%2;
            curNode->val=nums[mid];
            if(left<=mid-1){
                curNode->left=new TreeNode(0);
                nodeStack.push_back(curNode->left);
                leftIndexStack.push_back(left);
                rightIndexStack.push_back(mid-1);
            }
            if(mid+1<=right){
                curNode->right=new TreeNode(0);
                nodeStack.push_back(curNode->right);
                leftIndexStack.push_back(mid+1);
                rightIndexStack.push_back(right);
            }
        }
        
        return head;
        
        
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
