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
        
        UndirectedGraphNode *copy=new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        
        map[node] = copy;
        
        cloneGraph(map, node);
        
        return map[node];

    }
    
    void cloneGraph(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& map, UndirectedGraphNode *node){
        
        for(int i=0;i<node->neighbors.size();i++){
            if(!map[node->neighbors[i]]){
                UndirectedGraphNode *copy=new UndirectedGraphNode(node->neighbors[i]->label);
                map[node->neighbors[i]] = copy;
                cloneGraph(map, node->neighbors[i]);
            }
            map[node]->neighbors.push_back(map[node->neighbors[i]]);
        }
    }
};

int main(){
    return 0;
}
