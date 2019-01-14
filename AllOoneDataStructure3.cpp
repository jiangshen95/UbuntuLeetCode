#include<iostream>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class AllOne {
private:
	struct BucketNode {
		int val;
		BucketNode *next;
		BucketNode *pre;
		unordered_set<string> keys;
		
		BucketNode(int val, BucketNode *next, BucketNode *pre) : val(val), next(next), pre(pre) {}
	};
	BucketNode *head;
	BucketNode *tail;
	unordered_map<string, BucketNode*> m;
public:
    /** Initialize your data structure here. */
    AllOne() {
        head = NULL;
        tail = NULL;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(m.find(key) != m.end()) {
        	
        	BucketNode *cur = m[key];
        	
        	if(cur == tail || cur->next->val != cur->val + 1) {
        		BucketNode *newBucket = new BucketNode(cur->val + 1, cur->next, cur);
        		if(cur->next) cur->next->pre = newBucket;
        		cur->next = newBucket;
        		if(cur == tail) tail = newBucket;
			}
			cur->next->keys.insert(key);
			m[key] = cur->next;
			cur->keys.erase(key);
			if(cur->keys.empty()) {
				if(cur == head) {
					head = cur->next;
					cur->next->pre = NULL;
					cur->next = NULL;
					free(cur);
				}else {
					cur->pre->next = cur->next;
					cur->next->pre = cur->pre;
					free(cur);
				}
			}
		}else {
			if(head == NULL && tail == NULL) {
				head = tail = new BucketNode(1, NULL, NULL);
			}else if(head->val > 1) {
				head->pre = new BucketNode(1, head, NULL);
				head = head->pre;
			}
			head->keys.insert(key);
			m[key] = head;
		}
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m.find(key) == m.end()) return;
        
        BucketNode *cur = m[key];
        if(cur->val == 1) {
            
        	cur->keys.erase(key);
        	if(cur->keys.empty()) {
        		if(tail == cur) tail = head = NULL;
        		else {
        			head = cur->next;
        			head->pre = NULL;
				}
        		free(cur);
			}
        	m.erase(key);
        	return;
		}
		
		if(cur == head || cur->pre->val + 1 != cur->val) {
			BucketNode *newBucket = new BucketNode(cur->val - 1, cur, cur->pre);
			if(cur->pre) cur->pre->next = newBucket;
			cur->pre = newBucket;
			if(cur == head) head = newBucket;
		}
		cur->pre->keys.insert(key);
		m[key] = cur->pre;
		cur->keys.erase(key);
		if(cur->keys.empty()) {
			if(tail == cur) {
				tail = cur->pre;
				tail->next = NULL;
				cur->pre = NULL;
				free(cur);
			}else {
				cur->next->pre = cur->pre;
				cur->pre->next = cur->next;
				free(cur);
			}
		}
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(tail == NULL) return "";
        else return *(tail->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(head == NULL) return "";
        else return *(head->keys.begin());
    }
};

int main() {
	
	AllOne *obj = new AllOne();
	
	obj->inc("a");
	obj->inc("b");
	obj->inc("b");
	obj->inc("b");
	obj->inc("b");
	
	obj->dec("b");
	obj->dec("b");
	
	cout<<obj->getMaxKey()<<endl;
	cout<<obj->getMinKey()<<endl;
	
//	obj->inc("hello");
//	obj->inc("hello");
//	obj->inc("world");
//	obj->dec("world");
//	
//	cout<<obj->getMaxKey()<<endl;
//	cout<<obj->getMinKey()<<endl;
	
	return 0;
	
}
