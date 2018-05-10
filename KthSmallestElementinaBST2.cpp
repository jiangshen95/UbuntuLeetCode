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
        int count = countNode(root->left);
        if(count == k - 1){
            return root->val;
        }else if(count > k - 1){
            return kthSmallest(root->left, k);
        }else{
            return kthSmallest(root->right, k - count - 1);
        }
        
    }
    
    int countNode(TreeNode *root) {
        if(root == NULL) return 0;
        return 1 + countNode(root->left) + countNode(root->right);
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
