#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    	vector<int> repeatCnt(n1 + 1, 0);
    	vector<int> nextIndex(n1 + 1, 0);
    	int j = 0, count = 0;
    	for(int k = 1; k <= n1; k++) {
    		for(int i = 0; i < s2.size(); i++) {
    			if(s1[i] == s2[j]) j++;
    			if(j == s2.size()) {
    				j = 0;
    				count++;
				}
			}
			repeatCnt[k] = count;
			nextIndex[k] = j;
			for(int l = 0; l < k; l++) {    // 若从 1 开始循环的时候遇到恰好分割的情况可能多循环几次
				if(nextIndex[l] == j) {
					int interval = k - l;
					int repeat = (n1 - l) / interval;
					int patternCnt = (repeatCnt[k] - repeatCnt[l]) * repeat;
					int remainCnt = repeatCnt[l + (n1 - l) % interval];
					return (patternCnt + remainCnt) / n2; 
				}
			}
		}
		return repeatCnt[n1] / n2; 
    }
};

int main() {
	
	string s1, s2;
	int n1, n2;
	cin>>s1>>n1>>s2>>n2;
	
	Solution *solution = new Solution();
	cout<<solution->getMaxRepetitions(s1, n1, s2, n2);
	
	return 0;
	
}
