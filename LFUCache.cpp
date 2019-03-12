#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;

class LFUCache {
private:
	struct Node {
		int key;
		int value;
		int times;
		Node *pre;
		Node *next;
		Node(int key, int value) : key(key), value(value), times(1), pre(NULL), next(NULL) {}
	};
private:
	int capacity;
	unordered_map<int, Node*> key_value;
	set<int> times;
	unordered_map<int, pair<Node*, Node*> > times_map;
	
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(key_value.find(key) != key_value.end()) {
        	
        	Node *cur = key_value[key];
        	delete_one(cur);
//        	Node *begin = times_map[cur->times].first;
//        	Node *tail = times_map[cur->times].second;
//        	
//        	if(begin == tail) {
//        		times_map.erase(cur->times);
//        		times.erase(cur->times);
//			}else {
//				if(cur == begin) {
//					begin = begin->next;
//					begin->pre = NULL;
//					times_map[cur->times].first = begin;
//				}else if(cur == tail) {
//					tail = tail->pre;
//					tail->next = NULL;
//					times_map[cur->times].second = tail;
//				}else {
//					cur->pre->next = cur->next;
//					cur->next->pre = cur->pre;
//				}
//			}
        	
        	cur->times++;
//        	if(times_map.find(cur->times) == times_map.end()) {
//        		times_map[cur->times] = make_pair(cur, cur);
//        		times.insert(cur->times);
//			}else {
//				times_map[cur->times].second->next = cur;
//				cur->pre = times_map[cur->times].second;
//				cur->next = NULL;
//				times_map[cur->times].second = cur;
//			}
			add_one(cur);
        	
        	return cur->value;
        	
		}else return -1;
    }
    
    void delete_one(Node *cur) {
		Node *begin = times_map[cur->times].first;
    	Node *tail = times_map[cur->times].second;
    	cout<<"key: "<<begin->key<<endl;
    	cout<<"key2: "<<tail->key<<endl;
    	
    	if(begin == tail) {
    		times_map.erase(cur->times);
    		times.erase(cur->times);
		}else {
			if(cur == begin) {
				cout<<"---1---"<<endl;
				begin = begin->next;
				begin->pre = NULL;
				times_map[cur->times].first = begin;
			}else if(cur == tail) {
				tail = tail->pre;
				tail->next = NULL;
				times_map[cur->times].second = tail;
			}else {
				cur->pre->next = cur->next;
				cur->next->pre = cur->pre;
			}
		}
	}
	
	void add_one(Node *cur) {
		if(times_map.find(cur->times) == times_map.end()) {
    		times_map[cur->times] = make_pair(cur, cur);
    		times.insert(cur->times);
		}else {
			times_map[cur->times].second->next = cur;
			cur->pre = times_map[cur->times].second;
			cur->next = NULL;
			times_map[cur->times].second = cur;
		}
	}
    
    void put(int key, int value) {
        if(key_value.find(key) != key_value.end()) {
        	Node *cur = key_value[key];
        	delete_one(cur);
        	cur->value = value;
        	cur->times++;
        	add_one(cur);
		}else if(capacity > 0) {
			cout<<"capacity: "<<capacity<<endl;
			Node *new_one = new Node(key, value);
			add_one(new_one);
			capacity--;
			key_value[key] = new_one;
		}else {
			if(key_value.empty()) return;
			int time_to_delete = *(times.begin());
			cout<<"begin: "<<time_to_delete<<endl;
			Node *to_delete = times_map[time_to_delete].first;
			key_value.erase(to_delete->key);
			delete_one(to_delete);
			
			Node *new_one = new Node(key, value);
			add_one(new_one);
			key_value[key] = new_one;
		}
    }
};

int main() {
	
	LFUCache *cache = new LFUCache(2);
	cache->put(1, 1);
	cache->put(2, 2);
	cout<<cache->get(1)<<endl;
	cache->put(3, 3);
	cout<<cache->get(2)<<endl;
	cout<<cache->get(3)<<endl;
	cache->put(4, 4);
	cout<<cache->get(1)<<endl;
	cout<<cache->get(3)<<endl;
	cout<<cache->get(4)<<endl;
	
	return 0;
	
}
