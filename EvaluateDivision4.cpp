#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
private:
	struct Node {
		Node *parent;
		double value;
		Node() : parent(this), value(0) {}
	};
	
	void unionNodes(Node *node1, Node *node2, double v, unordered_map<string, Node*>& m) {
		Node *parent1 = findParent(node1), *parent2 = findParent(node2);
		double ratio = node2->value * v / node1->value;
		for(auto it = m.begin(); it != m.end(); it++) {
			if(findParent(it->second) == parent1) {
				it->second->value *= ratio;
			}
		}
		parent1->parent = parent2;
	}
	
	Node* findParent(Node *node) {
		if(node->parent == node) return node;
		node->parent = findParent(node->parent);
		return node->parent;
	}
	
public:
    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
	    unordered_map<string, Node*> m;
	    for(int i = 0; i < equations.size(); i++) {
	    	string s1 = equations[i].first, s2 = equations[i].second;
	    	if(m.find(s1) == m.end() && m.find(s2) == m.end()) {
	    		m[s1] = new Node();
	    		m[s2] = new Node();
	    		m[s2]->value = 1;
	    		m[s1]->value = values[i];
	    		m[s1]->parent = m[s2];
			}else if(m.find(s1) == m.end()) {
				m[s1] = new Node();
				m[s1]->value = values[i] * m[s2]->value;
				m[s1]->parent = m[s2];
			}else if(m.find(s2) == m.end()) {
				m[s2] = new Node();
				m[s2]->value = m[s1]->value / values[i];
				m[s2]->parent = m[s1];
			}else {
				unionNodes(m[s1], m[s2], values[i], m);
			}
		}
		
		vector<double> result(queries.size(), -1);
		for(int i = 0; i < queries.size(); i++) {
			if(m.find(queries[i].first) == m.end() || m.find(queries[i].second) == m.end() || findParent(m[queries[i].first]) != findParent(m[queries[i].second])) {
				continue;
			}
			result[i] = m[queries[i].first]->value / m[queries[i].second]->value; 
		}
		
		return result;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<pair<string, string> > equations;
	for(int i = 0; i < n; i++) {
		string s1, s2;
		cin>>s1>>s2;
		equations.push_back(make_pair(s1, s2));
	}
	
	vector<double> values;
	for(int i = 0; i < n; i++) {
		double v;
		cin>>v;
		values.push_back(v);
	}
	
	cin>>n;
	vector<pair<string, string> > queries;
	for(int i = 0; i < n; i++) {
		string s1, s2;
		cin>>s1>>s2;
		queries.push_back(make_pair(s1, s2));
	}
	
	Solution *solution = new Solution();
	vector<double> result = solution->calcEquation(equations, values, queries);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	
	return 0;
	
}
