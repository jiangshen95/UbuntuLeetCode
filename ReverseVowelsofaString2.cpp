#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
        	i = s.find_first_of("aeiouAEIOU", i);
        	j = s.find_last_of("aeiouAEIOU", j);
        	if(i < j) {
        		swap(s[i++], s[j--]);
			}
		}
		
		return s;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	s = solution->reverseVowels(s);
	
	cout<<s;
	
	return 0;
	
}
