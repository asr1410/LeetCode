class Solution
{
public:
     vector<int> sequentialDigits(int low, int high)
     {
          string digit = "123456789";
          vector<int> result;
          int lenMin = to_string(low).length();
          int lenMax = to_string(high).length();
          for (int i = lenMin; i <= lenMax; i++)
          {
               for (int j = 0; j < 10 - i; j++)
               {
                    int num = stoi(digit.substr(j, i));
                    if (num >= low and num <= high)
                    {
                         result.push_back(num);
                    }
               }
          }
          return result;
     }
};