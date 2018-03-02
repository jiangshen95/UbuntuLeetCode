#include<iostream>
#include<vector>

using namespace std;

class LRUCache {
private:
    vector<int> keys;
    vector<int> values;
    vector<int> ages;
    int age;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->age = 0;
    }
    
    int get(int key) {
        age++;
        for(int i=0;i<keys.size();i++)
            if(keys[i] == key){
                ages[i] = age;
                return values[i];
            }
        return -1;
    }
    
    void put(int key, int value) {
        age++;
        if(keys.size()<capacity){
            keys.push_back(key);
            values.push_back(value);
            ages.push_back(age);
        }else{
            int evict=0;
            int min_age=ages[0];
            for(int i=1;i<ages.size();i++){
                if(ages[i]<min_age){
                    evict = i;
                    min_age = ages[i];
                }
            }
            keys[evict] = key;
            values[evict] = value;
            ages[evict] = age;
        }
    }
};

int main(){
    
    LRUCache *cache = new LRUCache(2);
    cache->put(1, 1);
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
