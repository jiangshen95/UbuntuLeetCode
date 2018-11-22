#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        bool negtive = false;
        if(num < 0) {
        	negtive = true;
        	num = INT_MAX + num + 1;
		}
		cout<<num<<endl;
		vector<char> hex_num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
		string hex = "";
		while(num > 0) {
			hex = hex_num[num % 16] + hex;
			num /= 16;
		}
		
		if(negtive) {
			if(hex.size() < 8) {
				for(int i = hex.size(); i < 8; i++) {
					hex = "0" + hex;
				}
			}
			hex[0] = hex_num[hex[0] - '0' + 8];
		}
		
		return hex;
        
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	cout<<solution->toHex(num);
	
	return 0;
	
}
