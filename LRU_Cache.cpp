/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.
*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
public:
    int cap;
    list<int> used; //STL doubly linked list
    unordered_map<int,pair<int,list<int>::iterator>> has; /*hash-map stores value and a                                                                 pointer (iterator) to the key in                                                             an STL list.*/
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(has.find(key) != has.end()) { //present in the cache i.e key is already in memory
            used.erase(has[key].second); /* bringing the already present key to the front of                                             the list */     
            used.push_back(key);
            has[key].second = --used.end();
            return has[key].first;
        }
        return -1;
    }
    void put(int key, int value) {
        if(has.find(key) == has.end() && has.size() == cap) {
            has.erase(*used.begin());
            used.erase(used.begin());
        }
        else if(has.find(key) != has.end()) {
            used.erase(has[key].second);
        }
        used.push_back(key);
        has[key] = make_pair(value, --used.end());
    }
};
