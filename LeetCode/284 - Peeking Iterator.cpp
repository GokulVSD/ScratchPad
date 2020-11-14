// https://leetcode.com/problems/peeking-iterator/

// Simple enough

class PeekingIterator : public Iterator {
public:
    int c;
    bool peaked;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    c = 0;
        peaked = false;
	}
	
	int peek() {
        if(!peaked)
            c = Iterator::next();
        peaked = true;
        return c;
	}
	
	int next() {
	    if(peaked){
            peaked = false;
            return c;
        }
        return Iterator::next();
	}
	
	bool hasNext() const {
	    return peaked || Iterator::hasNext();
	}
};