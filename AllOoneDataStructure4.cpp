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
	unordered_map<string, int> keyCountMap;
	unordered_map<int, BucketNode*> countBucketMap;
public:
    /** Initialize your data structure here. */
    AllOne() {
        head = new BucketNode(INT_MIN, NULL, NULL);
        tail = new BucketNode(INT_MAX, NULL, head);
        head->next = tail;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(keyCountMap.find(key) != keyCountMap.end()) {
        	changeKey(key, 1);
		}else {
			keyCountMap[key] = 1;
			if(head->next->val != 1) addBucketAfter(new BucketNode(1, head->next, head), head);
			head->next->keys.insert(key);
			countBucketMap[1] = head->next;
		}
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(keyCountMap.find(key) == keyCountMap.end()) return;
        
        int count = keyCountMap[key];
        if(count == 1) {
        	keyCountMap.erase(key);
        	removeKeyFromBucket(countBucketMap[1], key);
		}else {
			changeKey(key, -1);
		}
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(tail->pre == head) return "";
        else return *(tail->pre->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(head->next == tail) return "";
        else return *(head->next->keys.begin());
    }
    
    void changeKey(string key, int offset) {
    	int count = keyCountMap[key];
    	keyCountMap[key] = count + offset;
    	
    	BucketNode *cur = countBucketMap[count];
    	BucketNode *newBucket;
    	
    	if(countBucketMap.find(count + offset) != countBucketMap.end()) {
    		newBucket = countBucketMap[count + offset];
		}else {
			newBucket = new BucketNode(count + offset, NULL, NULL);
			countBucketMap[count + offset] = newBucket;
			addBucketAfter(newBucket, offset > 0 ? cur : cur->pre);
		}
		
		newBucket->keys.insert(key);
		removeKeyFromBucket(cur, key);
	} 
	
	void removeKeyFromBucket(BucketNode *bucket, string key) {
		bucket->keys.erase(key);
		if(bucket->keys.empty()) {
			removeBucketFromList(bucket);
			countBucketMap.erase(bucket->val);
			free(bucket);
		}
	}
	
	void removeBucketFromList(BucketNode *bucket) {
		bucket->pre->next = bucket->next;
		bucket->next->pre = bucket->pre;
		bucket->pre = NULL;
		bucket->next = NULL;
	}
	
	void addBucketAfter(BucketNode *newBucket, BucketNode *preBucket) {
		newBucket->pre = preBucket;
		newBucket->next = preBucket->next;
		preBucket->next->pre = newBucket;
		preBucket->next = newBucket;
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
