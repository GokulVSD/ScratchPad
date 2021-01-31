// https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/

// TIL, don't instantiate dynamic data types like vectors and maps unless you want to fix a size or reserve, it take 16ms.

// swap val with last element and pop the vector for O(1) removal.

class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> l;
    
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) == m.end()){
            m[val] = l.size();
            l.emplace_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        m[l.back()] = m[val];
        swap(l[m[val]], l.back());
        m.erase(val);
        l.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return l[rand() % l.size()];
    }
};