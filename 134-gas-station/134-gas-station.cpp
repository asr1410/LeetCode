class Solution
{
public:
     int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
     {
          // first find if a solution exists
          int gastotal = 0, costtotal = 0;
          for (int i = 0; i < gas.size(); ++i)
          {
               gastotal += gas[i];
               costtotal += cost[i];
          }
          // if cost is greater than gas count
          if (gastotal < costtotal)
          {
               return -1;
          }
          // if a solution is possible, do below
          int start = 0;
          int tank = 0;

          for (int i = 0; i < gas.size(); ++i)
          {
               tank += gas[i];
               // if cost to next station is more than the gas we have right now,
               // reset tank back to 0 and try again at the next station
               if (cost[i] > tank)
               {
                    tank = 0;
                    start = i + 1;
               }
               else
               {
                    tank -= cost[i];
               }
          }
          return start;
     }
};