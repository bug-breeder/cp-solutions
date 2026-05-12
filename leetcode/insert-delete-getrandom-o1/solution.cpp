class RandomizedSet {
public:
    vector<int> vals;
    unordered_map<int, int> valToIdx;

    RandomizedSet() {
    }

    bool insert(int val) {
        if (valToIdx.contains(val)) {
            return false;
        }

        valToIdx[val] = vals.size();
        vals.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!valToIdx.contains(val)) {
            return false;
        }

        int pos = valToIdx[val];
        vals[pos] = vals.back();
        valToIdx[vals[pos]] = pos;
        valToIdx.erase(val);
        vals.pop_back();
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
