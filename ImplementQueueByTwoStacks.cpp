/*
As the title described, you should only use two stacks to implement a queue's actions.

The queue should support push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue.

Both pop and top methods should return the value of first element.

Have you met this question in a real interview? Yes
Example
For push(1), pop(), push(2), push(3), top(), pop(), you should return 1, 2 and 2

Challenge
implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by AVERAGE.

Tags Expand 
LintCode Copyright Stack Queue
*/

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
        //stack1 for enqueue
        //stack2 for dequeue
    }

    void push(int element) {
        // write your code here
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        int res = top();
        if(!stack2.empty()){
            stack2.pop();
        }
        return res;
    }

    int top() {
        // write your code here
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        if(!stack2.empty()){
            return stack2.top();
        }else{
            return -1;
        }
    }
};

