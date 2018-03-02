#include<iostream>
#include<unordered_map>

using namespace std;

struct Node {
    int key;
    int value;
    Node *next;
    Node *pre;
    Node(int key, int value) : key(key), value(value), next(NULL), pre(NULL) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> map;
    Node *begin = NULL;
    Node *end = NULL;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map.count(key)){
            Node *cur = map[key];
            if(cur == begin) return cur->value;
            if(cur->pre && cur->next){
                cur->pre->next = cur->next;
                cur->next->pre = cur->pre;
                cur->next = begin;
                cur->pre = NULL;
                begin->pre = cur;
                begin = cur;
            }else if(cur == end && cur->pre){
                end = cur->pre;
                cur->pre->next = NULL;
                cur->pre = NULL;
                cur->next = begin;
                begin->pre = cur;
                begin = cur;
            }
            return cur->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            Node *cur = map[key];
            
            //cout<<"cur: "<<cur->key<<endl;

            if(cur->pre && cur->next){
                cur->pre->next = cur->next;
                cur->next->pre = cur->pre;
                cur->next = begin;
                cur->pre = NULL;
                begin->pre = cur;
                begin = cur;
            }else if(cur == end && cur!=begin){
                end = cur->pre;
                cur->pre->next = NULL;
                cur->pre = NULL;
                cur->next = begin;
                begin->pre = cur;
                begin = cur;
            }
                
            cur->value = value;
        }else{
            if(map.size()<capacity){
                
                Node *add = new Node(key, value);
                if(!begin){
                    begin = add;
                    end = add;
                }else{
                    add->next = begin;
                    begin->pre = add;
                    begin = add;
                }
                map[key] = add;
            }else{
                Node *add = end;
                map.erase(end->key);
                if(end->pre){
                    end = end->pre;
                    end->next = NULL;
                    add->pre = NULL;
                    add->next = begin;
                    begin->pre = add;
                    begin = add;
                }
                add->key = key;
                add->value = value;
                map[key] = add;
            }
        }
        
    }
};

int main(){
    
    /*LRUCache *cache = new LRUCache(2);
    cout<<cache->get(1)<<endl;
    cache->put(2, 6);
    cout<<cache->get(1)<<endl;
    cache->put(1, 5);
    cache->put(1, 2);
    cout<<cache->get(1)<<endl;
    cout<<cache->get(2)<<endl;*/
    
    /*LRUCache *cache = new LRUCache(1);
    cache->put(2, 1);
    cout<<cache->get(2)<<endl;
    cache->put(3, 2);
    cout<<cache->get(2)<<endl;
    cout<<cache->get(3)<<endl;*/
    
    LRUCache *cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(1, 3);
    cache->put(2, 2);
    cout<<cache->get(1)<<endl;
    cache->put(3, 3);
    cout<<cache->get(2)<<endl;
    cache->put(4, 4);
    cout<<cache->get(1)<<endl;
    cout<<cache->get(3)<<endl;
    cout<<cache->get(4)<<endl;
    
    return 0;
}
