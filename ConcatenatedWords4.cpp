#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    	if(words.size() <= 2) return {};
    	unordered_set<string> dict(words.begin(), words.end());
    	vector<string> result;
    	for(string word : words) {
    		if(word.empty()) continue;
    		if(canConcated(word, dict, 0, 0)) result.push_back(word);
		}
		return result;
    }
    
    bool canConcated(string& word, unordered_set<string>& dict, int pos, int count) {
    	if(pos >= word.size() && count >= 2) return true;
    	for(int i = pos; i < word.size(); i++) {
    		string t = word.substr(pos, i - pos + 1);
    		if(dict.find(t) != dict.end() && canConcated(word, dict, i + 1, count + 1)) return true;
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
