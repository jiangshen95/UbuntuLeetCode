#include<iostream>
#include<stack>

using namespace std;

class NestedIterator {
private:
	stack<NestedInteger> s;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		for(int i = nestedList.size() - 1; i >= 0; i--) {
			s.push(nestedList[i]);
		}
	}
	
	int next() {
		NestedInteger t = s.top();
		s.pop();
		return t.getInteger();
	}
	
	bool hasNext() {
		while(!s.empty()) {
			NestedInteger t = s.top();
			if(t.isInteger()) return true;
			s.pop();
			vector<NestedInteger> list = t.getList();
			for(int i = list.size() - 1; i >= 0; i--) s.push(list[i]);
		}
		return false;
	}
};
