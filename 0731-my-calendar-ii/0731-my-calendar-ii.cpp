class MyCalendarTwo {
public:
    vector<pair<int,int>> single,twice;
    MyCalendarTwo() {
        single.clear();
        twice.clear();
    }
    bool overlaps(int st1,int st2,int ed1,int ed2){
        return max(st1,st2) < min(ed1,ed2);
    }
    pair<int,int> get(int st1,int st2,int ed1,int ed2){
        return {max(st1,st2),min(ed1,ed2)};
    }
    bool book(int start, int end) {
        for(auto it:twice){
            if(overlaps(it.first,start,it.second,end))
                return false;
        }
        for(auto it:single){
            if(overlaps(it.first,start,it.second,end))
                twice.push_back(get(it.first,start,it.second,end));
        }
        single.push_back({start,end});
        return true;        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */