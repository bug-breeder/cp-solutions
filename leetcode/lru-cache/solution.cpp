class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {
    }

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) {
            return -1;
        }

        order.splice(order.end(), order, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->second = value;
            order.splice(order.end(), order, it->second);
            return;
        }

        order.emplace_back(key, value);
        pos[key] = prev(order.end());

        if ((int)pos.size() > cap) {
            pos.erase(order.front().first);
            order.pop_front();
        }
    }

private:
    int cap;
    list<pair<int, int>> order;
    unordered_map<int, list<pair<int, int>>::iterator> pos;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
