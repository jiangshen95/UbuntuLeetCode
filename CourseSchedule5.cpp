/*
 * Time Limit Exceeded
 */
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph = make_graph(numCourses, prerequisites);
        
        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs_cycle(i, graph, onpath, visited)) return false;
        }
        
        return true;
    }
    
    /*
     * 有回环返回“是”， 没有回环返回否
     */
    bool dfs_cycle(int course, vector<unordered_set<int> > graph, vector<bool>& onpath, vector<bool>& visited){
        if(visited[course]) return false;
        if(onpath[course]) return true;
        onpath[course] = visited[course] = true;
        for(auto neighor : graph[course]){
            if(onpath[neighor] || dfs_cycle(neighor, graph, onpath, visited)) return true;
        }
        onpath[course] = false;
        return false;
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
