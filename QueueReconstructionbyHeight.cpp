#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
    	
    	sort(people.begin(), people.end(), [](pair<int, int> a, pair<int, int> b){
    		if(a.second != b.second) return a.second < b.second;
    		else return a.first < b.first;
		});
    	
    	int n = people.size();
        vector<pair<int, int> > result;
        for(int i = 0; i < n; i++) {
        	int count = 0;
        	for(int j = 0; j < result.size(); j++) {
        		if(result[j].first >= people[i].first) count++;
        		if(count == people[i].second + 1) {
        			cout<<people[i].first<<" "<<people[i].second<<endl;
        			cout<<j<<endl;
        			result.insert(result.begin() + j, people[i]);
        			break;
				}
			}
			if(count != people[i].second + 1) {
				result.push_back(people[i]);
				cout<<people[i].first<<" "<<people[i].second<<endl;
			}
		}
		
		return result;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<pair<int, int> > people;
	for(int i = 0; i < n; i++) {
		int h, k;
		cin>>h>>k;
		people.push_back(make_pair(h, k));
	}
	
	Solution *solution = new Solution();
	vector<pair<int, int> > result = solution->reconstructQueue(people);
	
	for(int i = 0; i < n; i++) {
		cout<<"["<<result[i].first<<","<<result[i].second<<"]"<<", ";
	}
	
	return 0;
}
