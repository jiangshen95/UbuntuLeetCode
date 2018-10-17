#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode *head;
	int count;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        ListNode *p = head;
        count = 0;
        while(p) {
        	count++;
        	p = p->next;
		}
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int rand_index = rand() % count;
        ListNode *p = head;
        for(int i = 0; i < rand_index; i++) p = p->next;
        return p->val;
    }
};

int main() {
	
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	
	a->next = b;
	b->next = c;
	
	Solution *solution = new Solution(a);
	cout<<solution->getRandom()<<endl;
	cout<<solution->getRandom()<<endl;
	cout<<solution->getRandom()<<endl;
	
	return 0;
	
}
