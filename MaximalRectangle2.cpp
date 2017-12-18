#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        int max=0;
        
        vector<int> height(n, 0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                height[j]=matrix[i][j]=='0' ? 0 : (1+height[j]);
            }
            int largest=largestRectangleArea(height);
            if(largest>max){
                max=largest;
            }
        }
        
        return max;
    }
    
    int largestRectangleArea(vector<int> heights) {
        
        heights.push_back(-1);
        
        vector<int> stack;
        int largest=0;
        
        for(int i=0;i<heights.size();i++){
            if(stack.empty()||(!stack.empty()&&heights[i]>=heights[stack.back()])){
                stack.push_back(i);
            }else{
                int top=stack.back();
                stack.pop_back();
                
                int area=0;
                if(stack.size()==0){
                    area=heights[top]*i;
                }else{
                    area=heights[top]*(i-stack.back()-1);
                }
                i--;
                if(area>largest) largest=area;
            }
        }
        
        return largest;
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    
    vector<vector<char> > matrix;
    for(int i=0;i<m;i++){
        vector<char> row;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            row.push_back(ch);
        }
        matrix.push_back(row);
    }
    
    Solution *solution=new Solution();
    cout<<solution->maximalRectangle(matrix);
    
    return 0;
}

