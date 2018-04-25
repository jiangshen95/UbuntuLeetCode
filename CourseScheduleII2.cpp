#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph = make_graph(numCourses, prerequisites);
        vector<int> order;
        vector<int> visited(numCourses, 0);
        vector<int> result;
        
        for(int i=0;i<numCourses;i++){
            if(!dfs_cycle(i, order, visited, graph)) return result;
        }
        
        for(int l=0, r=numCourses-1;l<r;l++, r--){
            int t = order[l];
            order[l] = order[r];
            order[r] = t;
        }
        return order;
        /*for(int i=0;i<numCourses;i++){
            result.push_back(order.back());
            order.pop_back();
        }
        
        return result;*/
    }
    
    bool dfs_cycle(int course, vector<int>& order, vector<int>& visited, vector<unordered_set<int> >& graph){
        if(visited[course] == -1) return true; 
        if(visited[course] == 1)  return false;
        visited[course] = 1;
        for(auto to : graph[course]){
            if(visited[to] == 1) return false;
            else if(!dfs_cycle(to, order, visited, graph)) return false;
        }
        visited[course] = -1;
        order.push_back(course);
        return true;
        
    }
    
    vector<unordered_set<int> > make_graph(int numCourses, vector<pair<int, int> >& prerequisites){
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
    vector<int> order = solution->findOrder(numCourses, prerequisites);
    
    for(int i=0;i<order.size();i++) cout<<order[i]<<"  ";
    
    return 0;
    
}
