#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph = make_graph(numCourses, prerequisites);
        vector<int> indegree(numCourses, 0);
        vector<int> order;
        
        for(auto neighbors : graph){
            for(auto neighbor : neighbors){
                indegree[neighbor] ++;
            }
        }
        
        for(int i=0;i<numCourses;i++){
            int j = 0;
            for(;j<numCourses;j++) if(indegree[j] == 0) break;
            if(j == numCourses){
                order.clear();
                return order;
            }
            indegree[j] = -1;
            order.push_back(j);
            for(auto to : graph[j]){
                indegree[to] --;
            }
        }
        
        return order;
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
