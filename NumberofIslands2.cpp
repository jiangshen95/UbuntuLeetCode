#include<iostream>
#include<vector>

using namespace std;

class UnionFind {
public:
    vector<int> father;
    int m, n;
    int count = 0;
    
    UnionFind(vector<vector<char> > grid){
        m = grid.size();
        n = grid[0].size();
        father = vector<int>(m*n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    int id = i*n + j;
                    father[id] = id;
                    count ++;
                }
            }
        }
    }
    
    void print(){
        for(int i=0;i<m*n;i++){
            if(i%n == 0) cout<<endl;
            cout<<father[i]<<"  ";
        }
    }
    
    void uf_union(int node1, int node2){
        int find1 = find(node1);
        int find2 = find(node2);
        if(find1 != find2){
            father[find1] = find2;
            count --;
        }
    }
    
    int find(int node){
        if(father[node] == node) return node;
        father[node] = find(father[node]);
        return father[node];
    }
    
};

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        UnionFind *uf = new UnionFind(grid);
        vector<vector<int> > distance = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    for(int k=0;k<distance.size();k++){
                        int x = i + distance[k][0];
                        int y = j + distance[k][1];
                        cout<<"x: "<<x<<endl;
                        cout<<"y: "<<y<<endl;
                        if(x>=0 && x<m && y >=0 && y<n && grid[x][y] == '1'){
                            int id1 = i * n + j;
                            int id2 = x * n + y;
                            uf->print();
                            uf->uf_union(id1, id2);
                        }
                    }
                }
            }
        }
        
        return uf->count;
        
    }
    
};

int main(){
    
    int m, n;
    cin>>m>>n;
    
    vector<vector<char> > grid;
    for(int i=0;i<m;i++){
        vector<char> raw;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            raw.push_back(ch);
        }
        grid.push_back(raw);
    }
    
    Solution *solution = new Solution();
    cout<<solution->numIslands(grid);
    
}
