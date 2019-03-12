#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class LFUCache {
private:
	int capacity;
	int minFreq;
	unordered_map<int, pair<int, int> > m;
	unordered_map<int, list<int> > freq;
	unordered_map<int, list<int>::iterator> iter;
	
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
    	if(m.find(key) == m.end()) return -1;
    	freq[m[key].second].erase(iter[key]);
    	m[key].second++;
    	freq[m[key].second].push_back(key);
    	iter[key] = --freq[m[key].second].end();
    	if(freq[minFreq].empty()) minFreq++;
    	return m[key].first;
    }
    
    void put(int key, int value) {
    	if(get(key) != -1) {
    		m[key].first = value;
    		return;
		}
		if(capacity > 0) {
			capacity--;
		}else {
			if(m.empty()) return;
			m.erase(freq[minFreq].front());
			iter.erase(freq[minFreq].front());
			freq[minFreq].pop_front();
		}
		m[key] = make_pair(value, 1);
		freq[1].push_back(key);
		iter[key] = --freq[1].end();
		minFreq = 1;
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
