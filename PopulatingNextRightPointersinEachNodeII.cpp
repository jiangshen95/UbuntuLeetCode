#include<iostream>

using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur=root;
        TreeLinkNode *p, *q;
        
        while(cur){
            p=cur;
            q=NULL;
            while(p!=NULL){
                if(p->left!=NULL&&p->right!=NULL){
                    p->left->next=p->right;
                    if(q!=NULL) q->next=p->left;
                    q=p->right;
                }else if(p->left!=NULL){
                    if(q!=NULL) q->next=p->left;
                    q=p->left;
                }else if(p->right!=NULL){
                    if(q!=NULL) q->next=p->right;
                    q=p->right;
                }
                p=p->next;
            }
            while(cur!=NULL){
                if(cur->left!=NULL){
                    cur=cur->left;
                    break;
                }
                if(cur->right!=NULL){
                    cur=cur->right;
                    break;
                }
                cur=cur->next;
            }
        }
    }
};

int main(){
    return 0;
}
