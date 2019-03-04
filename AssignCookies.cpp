#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        while(i < g.size() && j < s.size()) {
        	if(s[j] < g[i]) j++;
        	else {
        		i++;
        		j++;
			}
		}
		return i;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> g;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		g.push_back(num);
	} 
	
	cin>>n;
	vector<int> s;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		s.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->findContentChildren(g, s);
	
	return 0;
	
}
