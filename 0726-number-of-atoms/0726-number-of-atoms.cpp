class Solution {
public:
    string countOfAtoms(string formula) {
        // For multipliers
        int runningMul = 1;
        stack<int> stack;
        stack.push(1);

        // Map to store the count of atoms
        unordered_map<string, int> finalMap;

        // Strings to take care of current atom and count
        string currAtom = "";
        string currCount = "";

        // Index to traverse the formula in reverse
        int index = formula.length() - 1;

        // Parse the formula
        while (index >= 0) {
            // If digit, update the count
            if (isdigit(formula[index])) {
                currCount = formula[index] + currCount;
            }

            // If a lowercase letter, prepend to the currAtom
            else if (islower(formula[index])) {
                currAtom = formula[index] + currAtom;
            }

            // If UPPERCASE LETTER, update the finalMap
            else if (isupper(formula[index])) {
                currAtom = formula[index] + currAtom;
                int count = currCount.empty() ? 1 : stoi(currCount);
                finalMap[currAtom] += count * runningMul;

                currAtom = "";
                currCount = "";
            }

            // If the right parenthesis, the currCount if any
            // will be considered as multiplier
            else if (formula[index] == ')') {
                int currMultiplier = currCount.empty() ? 1 : stoi(currCount);
                stack.push(currMultiplier);
                runningMul *= currMultiplier;
                currCount = "";
            }

            // If left parenthesis, update the runningMul
            else if (formula[index] == '(') {
                runningMul /= stack.top();
                stack.pop();
            }

            index--;
        }

        // Sort the final map
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};