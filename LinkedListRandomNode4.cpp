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
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
    	vector<int> buffer(100);
        ListNode *c = head;
        int r = c->val;
        int before = 0;
        while(c) {
        	int i = 0;
        	for(i = 0; i < 100 && c; i++) {
        		buffer[i] = c->val;
        		c = c->next;
			}
			int rindex = rand() % (before + i);
			if(rindex < i) r = buffer[rindex];
			before += i;
		}
		
		return r;
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
