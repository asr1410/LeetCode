class Solution {
public:
    bool isRobotBounded(string instructions)
{
     int x = 0;
     int y = 0;
     char direction = 'N';
     int count = 100;
     while (count--)
     {
          for (int i = 0; i < instructions.size(); i++)
          {
               if (instructions[i] == 'G')
                    if (direction == 'N')
                         y = y + 1;
                    else if (direction == 'W')
                         x = x - 1;
                    else if (direction == 'E')
                         x = x + 1;
                    else
                         y = y - 1;
               else if (instructions[i] == 'L')
                    if (direction == 'N')
                         direction = 'W';
                    else if (direction == 'W')
                         direction = 'S';
                    else if (direction == 'S')
                         direction = 'E';
                    else
                         direction = 'N';
               else if (instructions[i] == 'R')
                    if (direction == 'N')
                         direction = 'E';
                    else if (direction == 'E')
                         direction = 'S';
                    else if (direction == 'S')
                         direction = 'W';
                    else
                         direction = 'N';
          }
          if (x == 0 && y == 0)
               return true;
     }
     return false;
}
};