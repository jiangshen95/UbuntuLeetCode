#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
    	unordered_map<char, int> m;
        for(char c : s) {
        	m[c]++;
		}
		
		sort(s.begin(), s.end(), [&](char &a, char &b) {
			return m[a] > m[b] || (m[a] == m[b] && a < b);
		});
		
		return s;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->frequencySort(s);
	
	return 0;
	
}
