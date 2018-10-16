#include<iostream>
#include<vector>
#include<random>
#include<unordered_map>

using namespace std;

class RandomizedSet {
private:
	unordered_map<int, int> m;
	vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m[val] > 0) return false;
        nums.push_back(val);
        m[val] = nums.size();
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m[val] == 0) return false;
        if(m[val] < nums.size()) {
        	swap(nums[m[val] - 1], nums[nums.size() - 1]);
        	cout<<nums.back()<<endl;
        	m[nums[m[val] - 1]] = m[val];
		}
		nums.pop_back();
		m[val] = 0;
		return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int rand_index = rand() % nums.size();
        return nums[rand_index];
        
        
    }
};

int main() {
	
	RandomizedSet *obj = new RandomizedSet();
	obj->insert(1);
//	obj->remove(1);
	cout<<obj->getRandom()<<endl;
	
	return 0;
	
}
