class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length())
        {
            return false;
        }
        else{
        string con = s+s;
        return con.find(goal) != string::npos;
        }
        
    }
};