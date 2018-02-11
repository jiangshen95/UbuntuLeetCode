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
        vector<UndirectedGraphNode*> stack;
        stack.push_back(node);
        map[node] = copy;
        
        while(!stack.empty()){
            UndirectedGraphNode *cur=stack.back();
            stack.pop_back();
            
            for(int i=0;i<cur->neighbors.size();i++){
                if(!map[cur->neighbors[i]]){
                    copy = new UndirectedGraphNode(cur->neighbors[i]->label);
                    map[cur->neighbors[i]] = copy;
                    stack.push_back(cur->neighbors[i]);
                }
                map[cur]->neighbors.push_back(map[cur->neighbors[i]]);
            }
        }
        
        return map[node];
    }
};

int main(){
}
