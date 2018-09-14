#include<iostream>
#include<vector>

using namespace std;

class NestedIterator {
private:
	vector<int> list;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		make_list(nestedList);
	}
	
	void make_list(vector<NestedInteger> nestedList) {
		for(int i = 0; i < nestedList.size(); i++) {
			if(nestedList[i].isInteger()) {
				list.push_back(nestedList[i].getInteger());
			}else {
				make_list(nestedList[i].getList());
			}
		}
	} 
	
	int next() {
		int t = list[0];
		list.erase(list.begin());
		return t;
	}
	
	bool hasNext() {
		return !list.empty();
	}
};
