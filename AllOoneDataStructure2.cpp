#include<iostream>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class AllOne {
private:
	struct Bucket {
		int val;
		unordered_set<string> keys;
	};
	list<Bucket> buckets;
	unordered_map<string, list<Bucket>::iterator> m;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(m.find(key) != m.end()) {
        	list<Bucket>::iterator it = m[key];
        	list<Bucket>::iterator next = ++m[key];
        	
        	it->keys.erase(key);
        	if(next->val != it->val + 1) {
        		list<Bucket>::iterator newBucket = buckets.insert(next, {it->val + 1, {key}});
        		m[key] = newBucket;
			}else {
				next->keys.insert(key);
				m[key] = next;
			}
        	
        	if(it->keys.empty()) buckets.erase(it);
		}else {
			if(buckets.front().val != 1) {
				m[key] = buckets.insert(buckets.begin(), {1, {key}});
			}else {
				buckets.begin()->keys.insert(key);
				m[key] = buckets.begin();
			}
		}
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m.find(key) == m.end()) return;
        
        list<Bucket>::iterator it = m[key];
        list<Bucket>::iterator last = --m[key];
        
        it->keys.erase(key);
        
        if(it->val == 1) {
        	if(it->keys.empty()) buckets.erase(it);
        	m.erase(key);
        	return;
		}
		
        if(it->val - 1 != last->val) {
        	list<Bucket>::iterator newBucket =  buckets.insert(it, {it->val - 1, {key}});
        	m[key] = newBucket;
		}
		else {
			last->keys.insert(key);
			m[key] = last;
		}
		
		if(it->keys.empty()) buckets.erase(it);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(buckets.empty()) return "";
        else return *(buckets.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(buckets.empty()) return "";
        else return *(buckets.begin()->keys.begin());
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
