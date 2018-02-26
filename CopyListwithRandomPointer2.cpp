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
        RandomListNode *cur=head, *next;
        
        while(cur){
            next = cur->next;
            RandomListNode *copy = new RandomListNode(cur->label);
            cur->next = copy;
            copy->next = next;
            cur = next;
        }
        
        cur = head;
        while(cur){
            if(cur->random){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        cur = head;
        RandomListNode *front = new RandomListNode(0);
        RandomListNode *copy=front;
        while(cur){
            next = cur->next->next;
            
            copy->next = cur->next;
            copy = copy->next;
            
            cur->next = next;
            cur = next;
        }
        
        return front->next;
    }
};

int main(){
    cout<<"I can't get the input...";
    return 0;
}
