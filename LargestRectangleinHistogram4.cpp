#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        
        vector<int> left(n);
        vector<int> right(n);
        
        left[0]=-1;
        right[n-1]=n;
        
        int s=0;
        for(int i=1;i<n;i++){
            s=i-1;
            while(s>=0&&heights[s]>=heights[i])
                s=left[s];
            left[i]=s;
        }
        
        for(int i=0;i<n;i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
        
        for(int i=n-2;i>=0;i--){
            s = i+1;
            while(s<n&&heights[s]>=heights[i])
                s=right[s];
            right[i]=s;
        }
        
        for(int i=0;i<n;i++){
            cout<<right[i]<<" ";
        }
        cout<<endl;
        
        int largest=0;
        int size=0;
        for(int i=0;i<n;i++){
            size=(right[i]-left[i]-1)*heights[i];
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

