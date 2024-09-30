class CustomStack {
public:
    int mlen = 0;
    vector<int> st;
    CustomStack(int maxSize) {
        mlen = maxSize;
    }
    
    void push(int x) {
        if(st.size() < mlen) {
            st.push_back(x);
        }
    }
    
    int pop() {
        if(st.empty() == true) {
            return -1;
        }
        int back = st.back();
        st.pop_back();
        return back;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k and i < st.size(); i++) {
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */