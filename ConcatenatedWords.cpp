/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//        unordered_map<int, vector<string> > m;
//        set<int> sizes;
//        for(auto word : words) {
//        	m[word.size()].push_back(word);
//        	sizes.insert(word.size());
//		}
		
		int max_len = 0;
		for(auto word : words) max_len = max(max_len, (int)word.size());
				
		vector<string> result;
		unordered_set<int> indexes;
		
		concateWords(words, result, max_len, indexes, "");
		
		return result;
    }
    
//    void concateWords(set<int>& sizes, int len, vector<int>& word_sizes) {
//    	
//    	if(word_sizes.size() >= 2 && sizes.find(len) != sizes.end()) {
//    		for(int i = 0; i < word_sizes.size(); i++) {
//    			
//			}
//		}
//    	
//    	for(int size : sizes) {
//    		if(len + size <= sizes.back()) {
//    			word_sizes.push_back(size);
//    			concateWords(sizes, len + size, word_sizes);
//    			word_sizes.pop_back();
//			}
//		}
//	}
    
    void concateWords(vector<string>& words, vector<string>& result, int max_len, unordered_set<int>& indexes, string concated) {
    	if(indexes.size() >= 2) {
    		for(auto word : words) {
    			if(word == concated) {
    				result.push_back(concated);
    				break;
				}
			}
		}
		
    	for(int i = 0; i < words.size(); i++) {
    		if(!words[i].empty() && concated.size() + words[i].size() <= max_len) {
    			if(indexes.find(i) == indexes.end()) {
    				indexes.insert(i);
    				concateWords(words, result, max_len, indexes, concated + words[i]);
    				indexes.erase(i);
				}else {
					concateWords(words, result, max_len, indexes, concated + words[i]);
				}
			}
		}
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
