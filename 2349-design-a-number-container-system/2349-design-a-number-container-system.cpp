class NumberContainers {
public:
    unordered_map<int, int> ump;
    unordered_map<int, set<int>> ucnt;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(ump[index] != number) {
            if(ump[index] != 0) {
                ucnt[ump[index]].erase(index);
            }
            ucnt[number].insert(index);
            ump[index] = number;
        }
    }
    
    int find(int number) {
        if(ucnt[number].empty() == false) {
            return *ucnt[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */