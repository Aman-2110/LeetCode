class MyStack {
public:
    queue<int> que;
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
        int t = que.size();
        while(t != 1){
            que.push(que.front());
            que.pop();
            t--;
        }
    }
    
    int pop() {
        int t = que.front();
        que.pop();
        return t;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */