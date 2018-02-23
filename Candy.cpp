#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int result=0;
        vector<int> num(ratings.size(), 0);
        int i=0;
        while(i<ratings.size()){
            int j=i-1;
            while(j>=0&&ratings[j]<ratings[j+1]) j--;
            for(int k=j+1;k<=i;k++) num[k]=k-j;
            j=i+1;
            while(j<ratings.size()&&ratings[j]<ratings[j-1]) j++;
            for(int k=i+1;k<j;k++) num[k]=j-k;
            num[i]=max(num[i], j-i);
            i=j;
            cout<<i<<endl;
        }
        
        for(i=0;i<num.size();i++) result+=num[i];
        
        return result;
    }
};

int main(){
    
    int n;
    cin>>n;
    
    vector<int> ratings;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        ratings.push_back(num);
    }
    
    Solution solution=Solution();
    cout<<solution.candy(ratings);
    
    return 0;
    
}
