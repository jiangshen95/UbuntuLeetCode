#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        
        vector<int> stack(n);
        vector<int> left(n);
        vector<int> right(n);
        
        int s=0;
        for(int i=0;i<n;i++){
            while(s>0&&heights[stack[s-1]]>=heights[i]) s--;
            left[i]=(s==0?0:stack[s-1]+1);
            stack[s++]=i;
        }
        
        for(int i=0;i<n;i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
        
        s=0;
        for(int i=n-1;i>=0;i--){
            while(s>0&&heights[stack[s-1]]>=heights[i]) s--;
            right[i]=(s==0?n:stack[s-1]);
            stack[s++]=i;
        }
        
        for(int i=0;i<n;i++){
            cout<<right[i]<<" ";
        }
        cout<<endl;
        
        int largest=0;
        int size=0;
        for(int i=0;i<n;i++){
            size=(right[i]-left[i])*heights[i];
            if(size>largest) largest=size;
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

