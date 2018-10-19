#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    NestedInteger deserialize(string s) {
    	istringstream in(s);
    	return deserialize(in);
    }
private:
	NestedInteger deserialize(istringstream &in) {
		int number;
		if(in >> number) return NestedInteger(number);
		in.clear();
		in.get();
		NestedInteger list;
		while(in.peek() != ']') {
			list.add(deserialize(in));
			if(in.peek() == ',') in.get();
		}
		in.get();
		return list;
	}
};

int main() {
	
//	string s;
//	cin>>s;
//	
//	Solution *solution = new Solution();
//	solution->deserialize(s);
	
//	vector<int> test{1, 2, 3};
//	test.back() = 4;
//	cout<<test[2]<<endl;

	vector<int> test;
	int a = 3;
	test.emplace_back(a);
	a = 4;
	cout<<test.back()<<endl;
		
	return 0;
	
}
