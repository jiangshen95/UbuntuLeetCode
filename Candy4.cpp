#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int result=0;
        int up=0;
        int down=0;
        int old_slope=0;
        /*
         * 关于加一的问题。一个波峰对应的应该是 count(up)+count(down)+(max(up, down)+1)，
         * 而一个波峰的最后一个节点会被服用，算到下次里面，所以要减去1
         * 而最后一个波峰和相等的（平的情况），最后一个节点不会被复用，所以要加一
         */
        for(int i=1;i<ratings.size();i++){
            int new_slope = (ratings[i]>ratings[i-1])?1:(ratings[i]<ratings[i-1]?-1:0);
            
            if((old_slope>0&&new_slope==0)||(old_slope<0&&new_slope>=0)){
                result += count(up)+count(down)+max(up, down);
                up=0;
                down=0;
            }
            if(new_slope>0) up++;
            if(new_slope<0) down++;
            if(new_slope==0) result++;
            
            old_slope = new_slope;
        }
        
        result += count(up)+count(down)+max(up, down)+1;
        
        return result;
    }
    
    int count(int n){
        return ((n+1)*n)/2;
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
