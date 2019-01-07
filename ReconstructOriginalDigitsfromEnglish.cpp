#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        //zero one two three four five six seven eight nine
        vector<string> words{"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<int> m(26, 0);
        vector<char> chars{'z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i'};
        for(char c : s) m[c - 'a']++;
        
        string result = "";
        for(int i = 0; i < 10; i++) {
        	if(m[chars[i] - 'a'] > 0) {
        		int cnt = m[chars[i] - 'a'];
        		for(char c : words[i]) m[c - 'a'] -= cnt;
        		for(int j = 0; j < cnt; j++) result.push_back(nums[i] + '0');
			}
		}
		
		sort(result.begin(), result.end());
		
		return result;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->originalDigits(s)<<endl;
	
	return 0;
	
}
