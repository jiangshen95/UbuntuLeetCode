#include<iostream>
#include<vector>
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
		
		vector<pair<int, char> > chars;
		
		for(auto t : m) {
			chars.push_back(make_pair(t.second, t.first));
		}
		
		sort(chars.begin(), chars.end(), [](pair<int, char> a, pair<int, char> b) {
			return a.first > b.first;
		});
		
		string result = "";
		for(auto it : chars) {
			for(int i = 0; i < it.first; i++) result += it.second;
		}
		
		return result;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->frequencySort(s);
	
	return 0;
	
}
