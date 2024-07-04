class BrowserHistory {
public:
    int ind = -1;
    vector<string> v;
    BrowserHistory(string h) {
        v.push_back(h);
        ind++;
    }
    
    
    void visit(string url) {
        v.erase(v.begin()+ind+1,v.end());
        ind++;
        v.push_back(url);
    }
    
    string back(int steps) {
        ind = max(0,ind-steps);
        return v[ind];
    }
    
    string forward(int steps) {
        ind = min(int(v.size()-1), ind+steps);
        return v[ind];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */