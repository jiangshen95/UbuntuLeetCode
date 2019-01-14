#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class AllOne {
private:
	unordered_map<string, int> data;
	unordered_map<int, unordered_set<string> > m;
	int min_val = INT_MAX;
	int max_val = INT_MIN;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        data[key] += 1;
        if(data[key] > max_val) max_val = data[key];
        if(data[key] < min_val) min_val = data[key];
    	else {
    		if(min_val == data[key] - 1 && m[min_val].size() == 1) min_val++;
		}
		m[data[key]].insert(key);
		if(data[key] - 1 > 0) m[data[key] - 1].erase(key);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        data[key] -= 1;
        m[data[key] + 1].erase(key);
        if(data[key] == 0) {
        	data.erase(key);
        	if(m[1].size() == 0)  {
        		if(max_val == 1) max_val = 0;
        		while(min_val <= max_val && m[min_val].size() == 0) min_val++;
        		if(min_val > max_val) min_val = 0;
			}
		}else {
			cout<<"max_val: "<<max_val<<"  min_val: "<<min_val<<endl;
			if(max_val == data[key] + 1 && m[max_val].size() == 0) max_val--;
			if(min_val == data[key] + 1) min_val--;
			m[data[key]].insert(key);
		}
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(max_val == 0 || max_val == INT_MIN) return "";
        else return *m[max_val].begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(min_val == 0 || min_val == INT_MAX) return "";
        else return *m[min_val].begin();
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
