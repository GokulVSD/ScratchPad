// https://leetcode.com/problems/maximum-frequency-stack/

// This works by maintaining a map of stacks. At any given time, we keep track of
// the maximum frequency of any value. When pushing, we push the value into the
// stack corresponding to its frequency. This essentially means there will be
// frequency number of copies of a value, from 1 to frequency stacks, each of them
// will have a copy of value. The order in which it will be in each of those stacks
// will be the order in which the values were pushed (to overcome a tie).

// When popping, we fetch the stack for the maximum frequency, and return the top 
// of that stack. After popping, if the stack is empty, that means we don't have 
// any more values with that max frequency, so we decrement it. By decrementing,
// we go to the (frequency - 1)th stack, which at the very least should have a copy
// of the value itself.

class FreqStack {
public:
    unordered_map<int, int> val_to_freq;
    unordered_map<int, stack<int>> freq_to_stack;
    int max_freq;
    
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        int freq = ++val_to_freq[val];
        freq_to_stack[freq].push(val);
        max_freq = max(max_freq, freq);
    }
    
    int pop() {
        int val = freq_to_stack[max_freq].top();
        freq_to_stack[max_freq].pop();
        val_to_freq[val]--;
        if (freq_to_stack[max_freq].empty()) {
            max_freq--;
        }
        return val;
    }
};