#include<iostream>
#include<unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        RandomListNode *cur=head;
        RandomListNode *front = new RandomListNode(0);
        RandomListNode *pre = front;
        
        unordered_map<RandomListNode*, RandomListNode*> map;
        
        while(cur){
            
            if(map[cur]){
                pre->next = map[cur];
            }else{
                pre->next = new RandomListNode(cur->label);
                map[cur] = pre->next;
            }
            pre = pre->next;
            
            //RandomListNode *node = new RandomListNode(cur->label);
            //pre->next = node;
            //pre = node;
            if(cur->random){
                if(map[cur->random]){
                    pre->random = map[cur->random];
                }else{
                    pre->random = new RandomListNode(cur->random->label);
                    map[cur->random] = pre->random;
                }
            }
            cur = cur->next;
        }
        
        return front->next;
    }
};

int main(){
    cout<<"I can't get the input...";
    return 0;
}
