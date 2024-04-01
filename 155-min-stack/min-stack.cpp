class MinStack {
private:
    vector<int> st;
    vector<int> premin;
    int last = 0;
public:
    MinStack() {
        st.resize(1e5);
        premin.resize(1e5);
        last = 0;
    }
    
    void push(int val) {
        if(last == 0){
            st[last] = val;
            premin[last] = val;
        } else {
            st[last] = val;
            premin[last] = min(premin[last-1], val);
        }

        last++;
    }
    
    void pop() {
        last--;
    }
    
    int top() {
        return st[last-1];
    }
    
    int getMin() {
        return premin[last-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */