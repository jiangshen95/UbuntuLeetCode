#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class RandomizedCollection {
private:
	unordered_map<int, vector<int> > locs;
	vector<pair<int, int> > nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
    	int ret = false;
        if(locs.find(val) == locs.end()) {
        	locs[val] = vector<int>();
        	ret = true;
		}
		//nums.push_back(val);
		locs[val].push_back(nums.size());
		nums.push_back(make_pair(val, locs[val].size() - 1));
		return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(locs.find(val) == locs.end()) return false;
        int index = locs[val].back();
        locs[val].pop_back();
        if(locs[val].empty()) locs.erase(val);
        
        if(index < nums.size() - 1) {
        	pair<int, int> last = nums.back();
	        //swap(nums[index], nums[nums.size() - 1]);
	        nums[index] = nums.back();
	        locs[last.first][last.second] = index;
		}
        
        nums.pop_back();
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

int main() {
	
	RandomizedCollection *obj = new RandomizedCollection();
	obj->insert(1);
	obj->remove(1);
	obj->insert(1);
	
	cout<<obj->getRandom();
	
	return 0;
	
}
