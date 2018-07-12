#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        addOperatorsDFS(num, target, 0, 0, "", result);
        return result;
    }
    
    void addOperatorsDFS(string num, int target, long long diff, long long curNum, string out, vector<string>& result) {
    	if(num.size() == 0 && curNum == target) {
    		result.push_back(out);
		}
		
		for(int i=1;i<=num.size();i++) {
			
			string cur = num.substr(0, i);
			if(cur.size() > 1 && cur[0] == '0') continue;
			string next = num.substr(i, num.size() - i);
			
			if(out.size() > 0) {
				addOperatorsDFS(next, target, strToNum(cur), curNum + strToNum(cur), out + "+" + cur, result);
				addOperatorsDFS(next, target, -strToNum(cur), curNum - strToNum(cur), out + "-" + cur, result);
				addOperatorsDFS(next, target, diff * strToNum(cur), curNum - diff + diff * strToNum(cur), out + "*" + cur, result);
			}else {
				addOperatorsDFS(next, target, strToNum(cur), strToNum(cur), cur, result);
			}
		}
	}
	
	long strToNum(string num) {
		long value = 0;
		for(int i=0;i<num.size();i++) value = value * 10 + num[i] - '0';
		return value;
	}
    
};

int main() {
	
	string num;
	cin>>num;
	int target;
	cin>>target;
	
	Solution *solution = new Solution();
	vector<string> result = solution->addOperators(num, target);
	for(int i=0;i<result.size();i++) {
		cout<<result[i]<<endl;
	}
	
	return 0;
	
}
