#include<iostream>
#include<vector>
#include<random>
#include<unordered_map>

using namespace std;

class RandomizedSet {
private:
	unordered_map<int, int> m;
	vector<int> all;
	int count;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        count = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m[val] > 0) return false;
        count++;
        m[val]++;
        all.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m[val] > 0) {
        	count--;
        	m[val] = 0;
        	return true;
		}
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int rand_index = rand() % count;
        
        while(rand_index < all.size() && m[all[rand_index]] == 0) rand_index++;
        return all[rand_index];
        
    }
};

int main() {
	
	RandomizedSet *obj = new RandomizedSet();
	obj->insert(1);
//	obj->remove(1);
	cout<<obj->getRandom()<<endl;
	
	return 0;
	
}
