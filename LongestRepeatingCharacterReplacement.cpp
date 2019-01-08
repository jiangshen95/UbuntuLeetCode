#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
    	
    	int result = 0;
        for(int i = 0; i < s.size(); i++) {
        	cout<<"i: "<<i<<endl;
        	int cnt = 0, next = i;
        	for(int j = i + 1; j <= s.size(); j++) {
        		if(j < s.size() && s[i] != s[j]) {
        			cnt++;
        			if(next == i) next = j;
//        			if((s[j] != s[next] || j - i > k + 1) && next == i) next = j;
				}
        		if(j == s.size() || (s[j] != s[i] && cnt > k)) {
        			if(j == s.size()) {
        				result = max(result, j - i + min(i, max(k - cnt, 0)));
        				i = j;
					}
        			else {
        				result = max(result, j - i);
        				i = next - 1;
        				break;
					}
				}
			}
			cout<<"next: "<<next<<"   cnt: "<<cnt<<endl;
		}
        
        return result;
    	
//    	vector<char> chars;
//    	vector<int> times;
//    	
//    	for(int i = 0, j = 0; i <= s.size(); i++) {
//    		if(i == s.size() || s[i] != s[j]) {
//    			chars.push_back(s[j]);
//    			times.push_back(i - j);
//    			j = i;
//			}
//		}
//		
//		int result = 0;
//		for(int i = 0; i < times.size(); i++) {
//			if(times[i] > k) continue;
//			int len = times[i], j = i + 1;
//			while(j < times.size() && len + times[j] <= k) {
//				len += times[j];
//				j++;
//			}
//			if(i > 0 && j < times.size()) {
//				if(chars[i - 1] == chars[j]) len += times[i - 1] + times[j];
//				else len += max(times[i - 1], times[j]);
//			}else if(i > 0) len += times[i - 1];
//			else if(j < times.size()) len += times[j];
//			result = max(result, len);
//		}
//        
//        return result;
    }
};

int main() {
	string s;
	int k;
	cin>>s;
	cin>>k;
	
	Solution *solution = new Solution();
	cout<<solution->characterReplacement(s, k);
	
	return 0;
}
