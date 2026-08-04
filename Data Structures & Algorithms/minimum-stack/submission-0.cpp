class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {
        min = LLONG_MAX;
    }
    
    void push(int val) {
        long long x = (long long) val;
        if(st.size() == 0){
            st.push(x);
            min = x;
        }else if(x>=min){
            st.push(x);
        }else{
            st.push(2*x - min);
            min = x;
        }
    }
    
    void pop() {
        if(st.top()<min){//fake value is present
            //before popping the top element make sure to retrieve old min
            long long oldmin = 2*min - st.top();
            min = oldmin;
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < min){
            return min;
        }
        else{
            return st.top();
        }
    }
    
    int getMin() {
        return min;
    }
};