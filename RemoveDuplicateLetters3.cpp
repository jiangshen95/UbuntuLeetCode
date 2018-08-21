#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> lastPosMap(26, -1);
        for(int i = 0; i < s.size(); i++) lastPosMap[s[i] - 'a'] = i;
        
        int begin = 0, end = findMinLastPos(lastPosMap);
        string result = "";
        
        while(end != INT_MAX) {
        	
        	cout<<"begin: "<<begin<<endl;
        	cout<<"end: "<<end<<endl;
        	char minChar = 'z' + 1;
        	for(int i = begin; i <=end; i++) {
        		if(s[i] < minChar && lastPosMap[s[i] - 'a'] != -1) {
        			minChar = s[i];
        			begin = i + 1;
				}
        		//if(s[i] < s[pos] && lastPosMap[s[i] - 'a'] != -1) pos = i;
			}
			
			result += minChar;
			lastPosMap[minChar - 'a'] = -1;
			//result += s[pos];
			//lastPosMap[s[pos] - 'a'] = -1;
			
			//begin = pos + 1;
			if(s[end] == minChar) end = findMinLastPos(lastPosMap);
        	
		}
		
		return result;
        
    }
    
    int findMinLastPos(vector<int> lastPosMap) {
    	int minLastPos = INT_MAX;
    	for(int i = 0; i < lastPosMap.size(); i++) {
    		if(lastPosMap[i] != -1) {
    			minLastPos = min(minLastPos, lastPosMap[i]);
			}
		}
		return minLastPos;
	}
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->removeDuplicateLetters(s);
	
	return 0;
	
}
