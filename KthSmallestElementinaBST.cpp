#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        TreeNode *cur = root;
        vector<TreeNode*> stack;
        int n = 0, kth = 0;
        while(cur != NULL || !stack.empty()) {
            while(cur){
                stack.push_back(cur);
                cur = cur->left;
            }
            cur = stack.back();
            stack.pop_back();
            if(++n == k){
                kth = cur->val;
                break;
            }
            cur = cur->right;
        }
        
        return kth;
    }
    
    void printTree(TreeNode *root){
        if(root == NULL) return;
        cout<<root->val<<" ";
        printTree(root->left);
        printTree(root->right);
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
    
    TreeNode *root = new TreeNode(nums.front());
    queue<TreeNode*> nodes;
    nodes.push(root);
    for(int i=1;i<n;i++){
        TreeNode *node = nodes.front();
        if(i % 2 == 1){
            if(nums[i] != -1){
                node->left = new TreeNode(nums[i]);
                nodes.push(node->left);
            }
        }else{
            if(nums[i] != -1){
                node->right = new TreeNode(nums[i]);
                nodes.push(node->right);
            }
            nodes.pop();
        }
    }
    
    int k;
    cin>>k;
    
    Solution *solution = new Solution();
    cout<<solution->kthSmallest(root, k);
    
    return 0;
    
    
    
}
