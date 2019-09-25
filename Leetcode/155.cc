#define ST_SIZE 1000000
class MinStack {
public:
	stack<int> st1;
	stack<int> st2;

	MinStack() {
		st2.push(INT_MAX);
	}
    
    void push(int x) {
    	st1.push(x);
		if (x <= st2.top()) st2.push(x);
	}
    
    void pop() {
		int x = st1.top();
		st1.pop();
		if (st2.top() == x) st2.pop();
    }
    
    int top() {
    	return st1.top();
	}
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
