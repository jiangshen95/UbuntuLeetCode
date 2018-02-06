/*
 * Time Limit Exceeded
*/
#include<map>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    void generatePath(vector<vector<string> >& result_path, vector<string>& temp_path, map<string, vector<string> >& path, string start, string end){
        temp_path.insert(temp_path.begin(), start);
        if(start==end){
            //vector<string> ret=temp_path;
            //reverse(ret.begin(), ret.end());
            result_path.push_back(temp_path);
            return;
        }
        
        for(int i=0;i<path[start].size();i++){
            generatePath(result_path, temp_path, path, path[start][i], end);
            temp_path.erase(temp_path.begin());
        }
        
        //for(auto it=path[start].begin();it!=path[start].end();it++){
        //    generatePath(path, *it, end);
        //    temp_path.pop_back();
        //}
    }
    
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList){
        //temp_path.clear();
        //result_path.clear();
        
        vector<string> current_step;
        vector<string> next_step;
        
        map<string, vector<string> > path;
        
        vector<string> unvisited=wordList;
        
        
        if(isContains(unvisited, beginWord)!=-1){
            unvisited.erase(unvisited.begin()+isContains(unvisited, beginWord));
        }
        
        current_step.push_back(beginWord);
        
        cout<<"current_step: ";
        for(int i=0;i<current_step.size();i++) cout<<current_step[i]<<"  ";
        cout<<endl;
        
        while(isContains(current_step, endWord)==-1&&unvisited.size()>0){
            for(int i=0;i<current_step.size();i++){
                string word=current_step[i];
                for(int j=0;j<word.length();j++){
                    for(int k=0;k<26;k++){
                        string temp=word;
                        if(temp[j]=='a'+k) continue;
                        temp[j]='a'+k;
                        if(isContains(unvisited, temp)!=-1){
                            if(isContains(next_step, temp)==-1)
                                next_step.push_back(temp);
                            if(isContains(path[temp], word)==-1)
                                path[temp].push_back(word);
                        }
                    }
                }
            }
            
            if(next_step.empty()) break;
            
            cout<<"unvisited: ";
        for(int i=0;i<unvisited.size();i++) cout<<unvisited[i]<<"  ";
        cout<<endl;
            
            for(int i=0;i<next_step.size()&&!unvisited.empty();i++){
                if(isContains(unvisited, next_step[i])!=-1)
                    unvisited.erase(unvisited.begin()+isContains(unvisited, next_step[i]));
            }
            
            current_step=next_step;
            
            cout<<"current_step: ";
        for(int i=0;i<current_step.size();i++) cout<<current_step[i]<<"  ";
        cout<<endl;
            
            next_step.clear();
        }
        
        vector<string> temp_path;
        vector<vector<string> > result_path;
        
        if(isContains(current_step, endWord)!=-1){
            generatePath(result_path, temp_path, path, endWord, beginWord);
        }
        
        return result_path;
    }
    
    int isContains(vector<string> list, string word){
        for(int i=0;i<list.size();i++){
            if(list[i]==word) return i;
        }
        return -1;
    }
        
    /*vector<vector<string> > findLadders(string start, string end, unordered_set<string>& dict){
        temp_path.clear();
        result_path.clear();
        
        unordered_set<string> current_step;
        unordered_set<string> next_step;
        
        map<string, unordered_set<string> > path;
        
        unordered_set<string> unvisited = dict;
        
        if(unvisited.count(start)>0)
            unvisited.erase(start);
        current_step.insert(start);
        
        while(current_step.count(end)==0&&unvisited.size()>0) {
            for(auto pcur=current_step.begin();pcur!=current_step.end();++pcur){
                string word=*pcur;
                for(int i=0;i<start.length();i++){
                    for(int j=0;j<26;j++){
                        string temp=word;
                        if(temp[i]=='a'+j) continue;
                        temp[i]='a'+j;
                        if(unvisited.count(temp)>0){
                            next_step.insert(temp);
                            path[temp].insert(word);
                        }
                    }
                }
            }
            
            if(next_step.empty()) break;
            for(auto it=next_step.begin();it!=next_step.end();++it){
                unvisited.erase(*it);
            }
            
            current_step=next_step;
            next_step.clear();
        }
        
        if(current_step.count(end)>0){
            generatePath(path, end, start);
        }
        
        return result_path;
    }*/
    
};

int main(){
    string beginWord;
    cin>>beginWord;
    string endWord;
    cin>>endWord;
    
    int n;
    cin>>n;
    vector<string> wordList;
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        wordList.push_back(word);
    }
    
    Solution *solution=new Solution();
    vector<vector<string> > result = solution->findLadders(beginWord, endWord, wordList);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
