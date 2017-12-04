#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> one;
        
        result.push_back(one);
        
        for(int i=0;i<nums.size();i++){
            vector<vector<int> > temp;
            for(int j=0;j<result.size();j++){
                vector<int> line;
                line=result[j];
                line.push_back(nums[i]);
                temp.push_back(line);
            }
            result.insert(result.end(), temp.begin(), temp.end());
        }
        
        return result;
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<int> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    
    vector<vector<int> > result;
    Solution *solution=new Solution();
    result=solution->subsets(nums);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
