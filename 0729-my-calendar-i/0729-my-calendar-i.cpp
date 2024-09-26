class MyCalendar {
private:
    vector<pair<int, int>> bookings;  // Store the start and end of booked events

public:
    MyCalendar() {}

    bool book(int start, int end) {
        // Check for overlap with any existing bookings
        for (auto& event : bookings) {
            int existingStart = event.first;
            int existingEnd = event.second;
            
            // If the new event overlaps with any existing event, return false
            if (start < existingEnd && end > existingStart) {
                return false;
            }
        }
        // If no overlap, add the event to bookings
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */