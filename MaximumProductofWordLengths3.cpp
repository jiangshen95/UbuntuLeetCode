#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
    	
    	int n = words.size();
    	
        unordered_map<int, int> value;
        
        int maxpro = 0;
        
        for(int i = 0; i < n; i++) {
        	
        	int t = 0;
        	for(char ch : words[i]) {
        		t |= 1 << (ch - 'a');
			}
			
			for(auto v : value) {
				if((v.first & t) == 0) {
					maxpro = max(maxpro, v.second * int(words[i].size()));
				}
			}
			
			value[t] = max(value[t], int(words[i].size()));
		}
		
		return maxpro;
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
	cout<<solution->maxProduct(words);
	
	return 0;
	
}
