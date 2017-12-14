#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
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
                
                cout<<"area: "<<area<<endl;
                
                i--;
                if(area>largest) largest=area;
                
            }
        }
        
        return largest;
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<int> heights;
    for(int i=0;i<n;i++){
        int height;
        cin>>height;
        heights.push_back(height);
    }
    
    Solution *solution=new Solution();
    cout<<solution->largestRectangleArea(heights);
    
    return 0;
}

