#include<iostream>
#include<unordered_map>
#include<list>
#include<set>

using namespace std;

class LFUCache {
private:
	struct Node {
		int count;
		list<pair<int, int> > vals;
		Node(int count = 1) : count(count) {}
	};
private:
	int capacity;
	list<Node> cache;
	unordered_map<int, pair<list<Node>::iterator, list<pair<int, int> >::iterator> > m;
	
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
    	if(m.find(key) == m.end()) return -1;
    	m[key] = promote(key);
    	return m[key].second->second;
    }
    
    pair<list<Node>::iterator, list<pair<int, int> >::iterator> promote(int key, int val = -1) {
    	list<Node>::iterator i = m[key].first;
    	list<pair<int, int> >::iterator j = m[key].second;
    	list<Node>::iterator k = ++m[key].first;
    	
    	if(val < 0) val = j->second;
    	int freq = i->count + 1;
    	
    	i->vals.erase(j);
    	if(i->vals.empty()) cache.erase(i);
    	
    	if(k == cache.end() || k->count != freq) {
    		i = cache.insert(k, Node(freq));
		}else i = k;
		i->vals.push_back(make_pair(key, val));
		j = --i->vals.end();
		return make_pair(i, j);
	}
	
	void evict() {
		list<Node>::iterator i = cache.begin();
		int key = i->vals.front().first;
		i->vals.erase(i->vals.begin());
		if(i->vals.empty()) cache.erase(i);
		m.erase(key);
	}
	
	pair<list<Node>::iterator, list<pair<int, int> >::iterator> insert(int key, int val) {
		list<Node>::iterator i = cache.begin();
		if(i == cache.end() || i->count != 1) i = cache.insert(i, Node(1));
		i->vals.push_back(make_pair(key, val));
		return make_pair(i, --i->vals.end());
	}
	
    void put(int key, int value) {
    	if(m.find(key) != m.end()) {
    		m[key] = promote(key, value);
    		return;
		}else if(capacity > 0) {
			capacity--;
		}else {
			if(m.empty()) return;
			evict();
		}
		m[key] = insert(key, value);
		
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
