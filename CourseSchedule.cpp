#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(numCourses, 0));
        vector<int> in(numCourses, 0);
        
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i].second][prerequisites[i].first] = 1;
            in[prerequisites[i].first] ++;
        }
        
        queue<int> nodes;
        for(int i=0;i<numCourses;i++){
            if(in[i] == 0) nodes.push(i);
        }
        
        /*while(!nodes.empty()) {
            int t = nodes.front();
            nodes.pop();
            for(int i=0;i<numCourses;i++){
                if(graph[t][i]){
                    in[i] --;
                    if(in[i] == 0) nodes.push(i);
                }
            }
        }
        
        for(int i=0;i<numCourses;i++){
            if(in[i] != 0) return false;
        }
        return true; 
        */
        
        //另一种方式
        int count = 0;
        while(!nodes.empty()) {
            int t = nodes.front();
            nodes.pop();
            count ++;
            for(int i=0;i<numCourses;i++){
                if(graph[t][i]){
                    in[i] --;
                    if(in[i] == 0) nodes.push(i);
                }
            }
        }
        return count == numCourses;
        
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
