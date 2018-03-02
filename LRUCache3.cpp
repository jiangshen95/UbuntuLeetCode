#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int> >::iterator> map;
    list<pair<int, int> > m_list;
public:
    LRUCache(int capacity) : capacity(capacity) {
    }
    
    int get(int key) {
        
        auto found_iter = map.find(key);
        if(found_iter == map.end()){
            return -1;
        }
        m_list.splice(m_list.begin(), m_list, found_iter->second);
        return found_iter->second->second;
        
    }
    
    void put(int key, int value) {
        auto found_iter = map.find(key);
        if(found_iter == map.end()){
            if(map.size() == capacity){
                int key_to_del = m_list.back().first;
                m_list.pop_back();
                map.erase(key_to_del);
            }
            m_list.emplace_front(key, value);
            map[key] = m_list.begin();
        }else{
            m_list.splice(m_list.begin(), m_list, found_iter->second);
            found_iter->second->second = value;
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
