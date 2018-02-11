#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        UndirectedGraphNode *newnode=new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        vector<UndirectedGraphNode *> queue;
        queue.push_back(node);
        map[node] = newnode;
        while(!queue.empty()){
            UndirectedGraphNode *cur=queue.front();
            queue.erase(queue.begin());
            
            for(int i=0;i<cur->neighbors.size();i++){
                if(!map[cur->neighbors[i]]){
                    newnode = new UndirectedGraphNode(cur->neighbors[i]->label);
                    map[cur->neighbors[i]]=newnode;
                    queue.push_back(cur->neighbors[i]);
                }
                map[cur]->neighbors.push_back(map[cur->neighbors[i]]);
            }
        }
        
        return map[node];
    }
};

int main(){
}
