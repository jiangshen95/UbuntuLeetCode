#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string res="";
        int last=0;
        //int f=0, s=-1;
        
        /*while(f<path.length()&&s<path.length()){
            //for(f=s+1;f<path.length();f++){
            //    if(path[f]=='/') break;
            //}
            for(s=f+1;s<path.length();s++){
                if(path[s]=='/') break;
            }
            if(s==path.length()&&f<path.length()){
                s--;
            }
            
            if(f<path.length()&&s<path.length()){
                if(s-f>1)
            }
        }*/
        if(path[last]!='/') last--;
        for(int i=0;i<path.length();i++){
            if((path[i]=='/'||i==path.length()-1)&&i>last){
                if(i==path.length()-1&&path[i]!='/') i++;
                
                bool is_dir=false;
                if(i-last>3) is_dir=true;
                else{
                    for(int j=last+1;j<i;j++){
                        if(path[j]!='.'){
                            is_dir=true;
                            break;
                        }
                    }
                }
                
                if(is_dir){
                    dirs.push_back(path.substr(last+1, i-last-1));
                }else{
                    if(i-last>2){
                        if(!dirs.empty()) dirs.pop_back();
                    }
                }
                
                last=i;
                
            }
        }
        
        if(dirs.empty()) res+='/';
        
        for(int i=0;i<dirs.size();i++){
            cout<<"dir: "<<dirs[i]<<endl;
            res+='/'+dirs[i];
        }
        
        return res;
    }
};

int main(){
    string path;
    cin>>path;
    
    Solution *solution=new Solution();
    cout<<solution->simplifyPath(path);
    
    return 0;
}
