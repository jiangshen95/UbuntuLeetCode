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

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        return cloneGraph(map, node);
    }
    
    UndirectedGraphNode *cloneGraph(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& map, UndirectedGraphNode *node){
        
        if(node==NULL) return NULL;
        
        if(map[node]) return map[node];
        
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        map[node] = copy;
        
        for(int i=0;i<node->neighbors.size();i++){
            copy->neighbors.push_back(cloneGraph(map, node->neighbors[i]));
        }
        
        return copy;
    }
};

int main(){
    return 0;
}
