class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> numIndex;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (numIndex.find(val) != numIndex.end()) {
            return false;
        }
        nums.push_back(val);
        numIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (numIndex.find(val) == numIndex.end()) {
            return false;
        }
        
        int lastElement = nums.back();
        int idx = numIndex[val];

        nums[idx] = lastElement;
        numIndex[lastElement] = idx;

        nums.pop_back();
        numIndex.erase(val);

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */