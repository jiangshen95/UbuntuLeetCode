/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest=0;
        
        for(int i=0;i<heights.size();i++){
            
            int min=heights[i];
            int largestw=heights[i];
            for(int j=i-1;j>=0;j--){
                if(heights[j]<min){
                    min=heights[j];
                }
                if(min*(i-j+1)>largestw){
                    largestw=min*(i-j+1);
                }
            }
            
            if(largestw>largest){
                largest=largestw;
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
