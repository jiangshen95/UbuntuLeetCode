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
    int  k;
    int num;
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        helper(root);
        return num;
    }
    
    void helper(TreeNode *root) {
        if(root == NULL) return;
        helper(root->left);
        k --;
        if(k == 0){
            num = root->val;
            return;
        }
        helper(root->right);
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
