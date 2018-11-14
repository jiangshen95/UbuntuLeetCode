#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
    	
    	vector<string> result;
    	
        for(int i = 0; i < 4; i++) {
        	if(num - i < 6 && num - i >= 0) {
        		vector<int> hours = getNums(i, 4, 12);
        		vector<int> minutes = getNums(num - i, 6, 60);
        		
        		for(int h : hours) {
        			for(int m : minutes) {
        				string s = to_string(h);
        				s += ":";
        				if(m / 10 == 0) s += "0";
        				s += to_string(m);
        				result.push_back(s);
					}
				}
			}
		}
		
		return result;
    }
    
    vector<int> getNums(int n, int bytes, int max_num) {
    	
    	vector<int> hours(1, 0);
    	
    	for(int i = 0; i < n; i++) {
    		vector<int> temp;
    		for(int j = 0; j < hours.size(); j++) {
    			for(int k = 0; k < bytes; k++) {
    				int t = (hours[j] << (k + 1)) | 1 << k;
    				if(t < max_num) temp.push_back(t);
				}
			}
			hours = temp;
		}
		
		for(int i = 0; i < hours.size(); i++) cout<<hours[i]<<"  ";
		cout<<endl;
		
		return hours;
	}
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	vector<string> result = solution->readBinaryWatch(num);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	cout<<endl;
	
	return 0;
	
}
