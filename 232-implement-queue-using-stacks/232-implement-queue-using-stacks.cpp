class MyQueue
{
     stack<int> que, help;

public:
     MyQueue()
     {
     }

     void push(int x)
     {
          que.push(x);
     }

     int pop()
     {
          int x;
          if (!help.empty())
          {
               int x = help.top();
               help.pop();
               return x;
          }
          else
          {
               while (!que.empty())
               {
                    x = que.top();
                    que.pop();
                    help.push(x);
               }
               x = help.top();
               help.pop();
               return x;
          }
     }

     int peek()
     {
          int x;
          if (!help.empty())
          {
               x = help.top();
               return x;
          }
          else
          {
               while (!que.empty())
               {
                    x = que.top();
                    que.pop();
                    help.push(x);
               }
               x = help.top();
               return x;
          }
     }

     bool empty()
     {
          return (que.size() + help.size()) == 0;
     }
};