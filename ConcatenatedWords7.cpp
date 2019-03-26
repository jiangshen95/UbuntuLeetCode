#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    	if(words.size() <= 2) return {};
    	vector<string> result;
    	unordered_set<string> dict;
    	
    	sort(words.begin(), words.end(), [&](string &a, string &b) {
    		return a.size() < b.size();
		});
		
		for(string word : words) {
			if(word.empty()) continue;
			if(canConcated(word, dict)) result.push_back(word);
			dict.insert(word);
		}
		
		return result;
    }
    
    bool canConcated(string word, unordered_set<string>& dict) {
    	int len = word.size();
		vector<int> st;
		st.push_back(0);
		unordered_set<int> visited;
		visited.insert(0);
		while(!st.empty()) {
			int n = st.back();st.pop_back();
			if(n == len) return true;
			for(int i = 0; i < len - n; i++) {
				if(dict.find(word.substr(n, i + 1)) != dict.end() && visited.find(n + i + 1) == visited.end()) {
					st.push_back(n + i + 1);
					visited.insert(n + i + 1);
				}
			}
		}
		return false;
	}
};

int main() {
	int n;
	cin>>n;
	
	vector<string> words;
	for(int i = 0; i < n; i++) {
		string word;
		cin>>word;
		words.push_back(word);
	}
	
	Solution *solution = new Solution();
	vector<string> result = solution->findAllConcatenatedWordsInADict(words);
	
	for(auto s : result) cout<<s<<"  ";
	
	return 0;
}
