/*
 * Time Limit Exceeded
 */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(numCourses, 0));
        vector<bool> visited(numCourses, false);
        
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i].second][prerequisites[i].first] = 1;
        }
        
        for(int i=0;i<numCourses;i++){
            visited[i] = true;
            if(!dfs(i, numCourses, graph, visited)) return false;
        }
        return true;
        
    }
    
    bool dfs(int course, int n, vector<vector<int> >& graph, vector<bool>& visited){
        for(int i=0;i<n;i++){
            if(graph[course][i] == 1){
                if(visited[i]) return false;
                else{
                    visited[i] = true;
                    if(!dfs(i, n, graph, visited)) return false;
                }
            }
        }
        visited[course] = false;
        return true;
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
