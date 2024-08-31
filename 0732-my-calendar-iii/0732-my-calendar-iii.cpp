class MyCalendarThree {
public:
    map<int, int> events;

    MyCalendarThree() {
        
    }
    
    int book(int st, int et) {
        events[st]++;
        events[et]--;
        
        int currentOverlap = 0;
        int maxOverlap = 0;
        
        for (const auto& event : events) {
            currentOverlap += event.second;
            maxOverlap = max(maxOverlap, currentOverlap);
        }
        return maxOverlap;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
