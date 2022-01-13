class MyQueue
{
     stack<int> que;

public:
     void push(int x)
     {
          if (!que.size())
          {
               que.push(x);
               return;
          }
          int data = que.top();
          que.pop();
          push(x);
          que.push(data);
     }
     int pop()
     {
          int x = que.top();
          que.pop();
          return x;
     }
     int peek()
     {
          int x = que.top();
          return x;
     }
     bool empty()
     {
          return que.size() == 0;
     }
};