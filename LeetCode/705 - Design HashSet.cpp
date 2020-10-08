// https://leetcode.com/problems/design-hashset/

// Seriously, needed stricter constraints. Faster than 99.5%

class MyHashSet {
public:
    /** Initialize your data structure here. */
    bool hs[1000000];
    MyHashSet() {
        fill(this->hs, this->hs + 1000000, false);
    }
    
    void add(int key) {
        this->hs[key] = true;
    }
    
    void remove(int key) {
        this->hs[key]= false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return this->hs[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */