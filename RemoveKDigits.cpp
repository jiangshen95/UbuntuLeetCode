#include<iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
    	if(num.size() == 0) return "0";
    	if(k == 0) return num;
        int n = num.size();
        for(int i = 0; i < k; i++) {
        	if(num[i] == '0') {
        		return removeKdigits(num.substr(i + 1), k - i);
			}
		}
		
		if(num[k] == '0') {
			while(num[k] == '0') k++;
			return k < n ? num.substr(k) : "0";
		}
		
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < num.size(); j++) {
				if((j < num.size() - 1 && num[j] > num[j + 1]) || j == num.size() - 1) {
					num.erase(num.begin() + j);
					break;
				}
			}
		}
		
		return num.size() > 0 ? num : "0";
		
//		for(int i = 0; i < n; i++) {
//			if((i < n - 1 && num[i] > num[i + 1]) || i == n - 1) {
//				num.erase(num.begin() + i);
//				break;
//			}
//		}
//		return removeKdigits(num, k - 1);
    }
};

int main() {
	
	string num;
	cin>>num;
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	cout<<solution->removeKdigits(num, k);
	
	return 0;
	
}
