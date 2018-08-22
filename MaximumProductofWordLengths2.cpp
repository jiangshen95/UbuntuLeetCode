#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
    	
    	int n = words.size();
    	
        vector<int> value(n, 0);
        
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < words[i].size(); j++) {
        		value[i] |= 1 << (words[i][j] - 'a');
			}
		}
		
		int maxpro = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if((value[i] & value[j]) == 0) {
					int product = words[i].size() * words[j].size();
					maxpro = max(maxpro, product);
				}
			}
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
