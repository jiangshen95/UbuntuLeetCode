#include<iostream>

using namespace std;

class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
	
	Node() {}
	
	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = prev;
		next = _next;
		child = _child;
	}
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* p = head;
        while(p) {
        	if(p->child) {
        		Node *next = p->next;
        		Node *t = p->child;
        		p->next = t;
        		t->prev = p;
        		while(t->next) t = t->next;
        		t->next = next;
        		if(next) next->prev = t;
        		p->child = NULL;
			}
			
			p = p->next;
		}
		
		return head;
    }
};

int main() {
	
	Node* a = new Node(1, NULL, NULL, NULL);
	Node* b = new Node(2, NULL, NULL, NULL);
	Node* c = new Node(3, NULL, NULL, NULL);
	Node* d = new Node(4, NULL, NULL, NULL);
	Node* e = new Node(5, NULL, NULL, NULL);
	Node* f = new Node(6, NULL, NULL, NULL);
	Node* g = new Node(7, NULL, NULL, NULL);
	Node* h = new Node(8, NULL, NULL, NULL);
	Node* i = new Node(9, NULL, NULL, NULL);
	Node* j = new Node(10, NULL, NULL, NULL);
	Node* k = new Node(11, NULL, NULL, NULL);
	Node* l = new Node(12, NULL, NULL, NULL);
	
	a->next = b;
	b->prev = a;
	
	b->next = c;
	c->prev = b;
	
	c->next = d;
	d->prev = c;
	
	d->next = e;
	e->prev = d;
	
	e->next = f;
	f->prev = e;
	
	c->child = g;
	
	g->next = h;
	h->prev = g;
	
	h->next = i;
	i->prev = h;
	
	i->next = j;
	j->prev = i;
	
	h->child = k;
	
	k->next = l;
	l->prev = k;
	
	Solution *solution = new Solution();
	Node *head = solution->flatten(a);
	
	while(head) {
		cout<<head->val<<"  ";
		head = head->next;
	}
	
	return 0;
	
	
}
