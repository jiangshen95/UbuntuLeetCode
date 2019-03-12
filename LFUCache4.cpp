#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class LFUCache {
private:
	struct Node {
		int key;
		int val;
		int freq;
		int stamp;
		Node() : key(-1), val(-1), stamp(-1), freq(0) {}
		Node(int key, int val, int stamp) : key(key), val(val), stamp(stamp), freq(1) {}
	};
private:
	int capacity;
	vector<Node*> pq;
	unordered_map<int, int> m;
	int stamp;
	
	void sink(int index) {
		int left = 2 * index, right = 2 * index + 1, target = index;
		if(left < pq.size() && pq[left]->freq <= pq[target]->freq) {
			target = left;
		}
		if(right < pq.size()) {
			if(pq[right]->freq < pq[target]->freq || (pq[right]->freq == pq[target]->freq && pq[right]->stamp < pq[target]->stamp)) {
				target = right;
			}
		}
		if(target != index) {
			myswap(target, index);
			sink(target);
		}
	}
	
	void swim(int index) {
		int father = index / 2;
		while(father > 0 && (pq[father]->freq > pq[index]->freq)) {
			myswap(father, index);
			index = father;
			father = index / 2;
		}
	}
	
	void myswap(int index1, int index2) {
		swap(pq[index1], pq[index2]);
		m[pq[index1]->key] = index1;
		m[pq[index2]->key] = index2;
	}
	
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        stamp = 0;
        Node *dummy = new Node();
        pq.push_back(dummy);
    }
    
    int get(int key) {
    	if(m.find(key) == m.end()) return -1;
    	int index = m[key];
    	int val = pq[index]->val;
    	pq[index]->freq++;
    	pq[index]->stamp = ++stamp;
    	sink(index);
    	return val;
    }
	
    void put(int key, int value) {
    	if(m.find(key) != m.end()) {
    		pq[m[key]]->val = value;
    		get(key);
		}else if(capacity > 0) {
			capacity--;
			Node *newnode = new Node(key, value, ++stamp);
			pq.push_back(newnode);
			m[key] = pq.size() - 1;
			swim(pq.size() - 1); 
		}else {
			if(m.empty()) return;
			int oldkey = pq[1]->key;
			m.erase(oldkey);
			Node *newnode = new Node(key, value, ++stamp);
			pq[1] = newnode;
			m[key] = 1;
			sink(1);
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
