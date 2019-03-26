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
		vector<bool> v(len + 1, false);
		v[0] = true;
		for(int i = 0; i < len; i++) {
			if(!v[i]) continue;
			for(int j = i + 1; j <= len; j++) {
				if(dict.find(word.substr(i, j - i)) != dict.end()) {
					v[j] = true;
				}
			}
			if(v.back()) return true;
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
