#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
private:
	struct TireNode {
		unordered_map<char, TireNode*> children;
		bool isEnd;
		TireNode() : isEnd(false) {}
	};
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    	if(words.size() <= 2) return {};
    	vector<string> result;
    	
    	sort(words.begin(), words.end(), [&](string &a, string &b) {
    		return a.size() < b.size();
		});
		
		TireNode *root = new TireNode();
		
		for(string word : words) {
			if(word.empty()) continue;
			if(canConcated(word, 0, root, 0)) result.push_back(word);
			addWord(word, root);
		}
		
		return result;
    }
    
    void addWord(string word, TireNode *root) {
    	TireNode *cur = root;
    	for(char ch : word) {
    		if(cur->children.find(ch) == cur->children.end()) {
    			cur->children[ch] = new TireNode();
			}
			cur = cur->children[ch];
		}
		cur->isEnd = true;
	}
    
    bool canConcated(string word, int pos, TireNode *root, int count) {
    	TireNode *cur = root;
    	for(int i = pos; i < word.size(); i++) {
    		if(cur->children.find(word[i]) == cur->children.end()) return false;
    		cur = cur->children[word[i]];
    		if(cur->isEnd && i == word.size() - 1) return true;
    		if(cur->isEnd && canConcated(word, i + 1, root, count + 1)) return true;
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
