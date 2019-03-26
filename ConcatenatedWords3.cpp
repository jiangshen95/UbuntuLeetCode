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
    	vector<string> result;
    	unordered_set<string> dict(words.begin(), words.end());
    	for(string word : words) {
    		int len = word.size();
    		if(len == 0) continue;
    		vector<bool> v(len + 1, false);
    		v[0] = true;
    		for(int i = 0; i < len; i++) {
    			if(!v[i]) continue;
    			for(int j = i + 1; j < len + 1; j++) {
    				if(j - i < len && dict.find(word.substr(i, j - i)) != dict.end()) v[j] = true;
				}
				if(v.back()) {
					result.push_back(word);
					break;
				}
			}
		}
		
		return result;
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
