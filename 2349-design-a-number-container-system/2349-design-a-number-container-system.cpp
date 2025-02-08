class NumberContainers {
public:
    unordered_map<int, int> ump;
    unordered_map<int, set<int>> ucnt;

    void change(int index, int number) {
        if (ump.count(index)) {
            int prev = ump[index];
            if (prev == number) return;
            ucnt[prev].erase(index);
            if (ucnt[prev].empty()) ucnt.erase(prev);
        }
        ump[index] = number;
        ucnt[number].insert(index);
    }

    int find(int number) {
        return ucnt.count(number) && !ucnt[number].empty() ? *ucnt[number].begin() : -1;
    }
};
