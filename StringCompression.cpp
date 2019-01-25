#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
    	int index = 0;
        for(int i = 0, j = 0; i <= chars.size(); i++) {
        	if(i == chars.size() || chars[i] != chars[j]) {
        		int count = i - j;
        		if(count > 0) { 
        			chars[index++] = chars[j];
        			if(count > 1) {
        				vector<char> nums = numToChars(count);
        				for(char num : nums) chars[index++] = num;
					}
				}
				j = i;
			}
		}
		
		return index;
    }
    
    vector<char> numToChars(int num) {
    	vector<char> chars;
    	while(num > 0) {
    		chars.push_back('0' + num % 10);
    		num /= 10;
		}
		reverse(chars.begin(), chars.end());
		return chars;
	}
};

int main() {
	
	int n;
	cin>>n;
	
	vector<char> chars;
	for(int i = 0; i < n; i++) {
		char ch;
		cin>>ch;
		chars.push_back(ch);
	}
	
	Solution *solution = new Solution();
	cout<<solution->compress(chars);
	
	return 0;
	
}
