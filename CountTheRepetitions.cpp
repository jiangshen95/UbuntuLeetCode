#include<iostream>

using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    	int i = 0, j = 0, nums = 1, count = 0;
    	bool flag = false;
    	while(i < s1.size() && j < s2.size()) {
    		if(s1[i] == s2[j]) {
    			i++;
    			j++;
    			flag = true;
			}else i++;
			
			if(i == s1.size() && j > 0 && j < s2.size() && flag) {
				i = 0;
				nums++;
				flag = false;
			}
			
			if(j == s2.size()) {
				count++;
				j = 0;
			}
			
			if(nums > n1) return count / n2;
		}
		
		cout<<"nums: "<<nums<<endl;
		cout<<"count: "<<count<<endl;
		return n1 * count / nums  / n2;
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
