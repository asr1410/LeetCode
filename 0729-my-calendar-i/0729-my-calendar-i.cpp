class MyCalendar {
public:
    vector<pair<int, int>> cal;
    
    MyCalendar() {
        
    }
    
    bool book(int s2, int e2) {
        for(auto [s1, e1] : cal) {
            if(e1 > s2 and e2 > s1) {
                return false;
            }
        }
        cal.push_back(make_pair(s2, e2));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */