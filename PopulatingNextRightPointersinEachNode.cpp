#include<iostream>
#include<vector>

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
        TreeLinkNode *p;
        while(cur->left){
            p=cur;
            while(p){
                p->left->next=p->right;
                if(p->next) p->right->next=p->next->left;
                p=p->next;
            }
            cur=cur->left;
        }
        
        /*TreeLinkNode *cur=root;
        TreeLinkNode *p, *q;
        while(cur){
            p=cur;
            while(p){
                q=p;
                p=p->next;
                if(q->left){
                    q->left->next=q->right;
                    if(p) q->right->next=p->left;
                }
            }
            cur=cur->left;
        }*/
    }
};

int main(){
    return 0;
}
