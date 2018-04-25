#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(numCourses, graph);
        
        for(int i=0;i<numCourses;i++){
            int j=0;
            for(;j<numCourses;j++) if(degrees[j] == 0) break;
            if(j == numCourses) return false;
            degrees[j] = -1;
            for(auto neighbor : graph[j]){
                degrees[neighbor] --;
            }
        }
        
        return true;
    }
    
    vector<int> compute_indegree(int numCourses, vector<unordered_set<int> > graph){
        vector<int> degrees(numCourses, 0);
        for(auto neighbors : graph){
            for(auto neighbor : neighbors)
                degrees[neighbor] ++;
        }
        
        return degrees;
    }
    
    vector<unordered_set<int> > make_graph(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph(numCourses);
        for(auto pre : prerequisites){
            graph[pre.second].insert(pre.first);
        }
        
        return graph;
    }
};

int main(){
    
    int numCourses;
    cin>>numCourses;
    
    int n;
    cin>>n;
    vector<pair<int, int> > prerequisites;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        prerequisites.push_back(pair<int, int>(a, b));
    }
    
    Solution *solution = new Solution();
    solution->canFinish(numCourses, prerequisites) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}

