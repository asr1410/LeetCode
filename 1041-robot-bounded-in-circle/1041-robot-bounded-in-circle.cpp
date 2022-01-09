class Solution {
public:
    bool isRobotBounded(string inst)
{
     int x = 0;
     int y = 0;
     char dir = 'N';
     int count = 100;
     while (count--)
     {
          for (int i = 0; i < inst.size(); i++)
          {
               if (inst[i] == 'G')
                    if (dir == 'N')
                         y = y + 1;
                    else if (dir == 'W')
                         x = x - 1;
                    else if (dir == 'E')
                         x = x + 1;
                    else
                         y = y - 1;
               else if (inst[i] == 'L')
                    if (dir == 'N')
                         dir = 'W';
                    else if (dir == 'W')
                         dir = 'S';
                    else if (dir == 'S')
                         dir = 'E';
                    else
                         dir = 'N';
               else if (inst[i] == 'R')
                    if (dir == 'N')
                         dir = 'E';
                    else if (dir == 'E')
                         dir = 'S';
                    else if (dir == 'S')
                         dir = 'W';
                    else
                         dir = 'N';
          }
          if (x == 0 && y == 0)
               return true;
     }
     return false;
}
};