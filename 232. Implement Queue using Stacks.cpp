//METHOD - 1
/*
  Time complexity
  pushing - O(1)
  poping  - O(N)
  peak      - O(N)
  empty   - O(1)
 */
 
class MyQueue {
    public:
    stack<int> st1,st2;
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        int temp=st2.top();
        st2.pop();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return temp;
    }
    
    int peek() {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        int temp=st2.top();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        
        return temp;
    }
    
    bool empty() {
        
        return st1.empty();
    }
};


//METHOD - 2
/* Time complexity
pushing - O(N)
Poping  - O(1)
peak    - O(1)
empty   - O(1)
*/
class MyQueue {
    public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
       if(!st1.empty())
       {
           int temp=st1.top();
           st1.pop();
           return temp;
       }
       return -1;
    }
    
    int peek() {
       if(!st1.empty())
       return st1.top();
       
       return -1;
    }
    
    bool empty() {
        return st1.empty();
    }
};